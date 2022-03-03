#include "filemanagerform.h"
#include "ui_filemanagerform.h"
#include "FoldersStrategy.h"
#include "FileTypesStrategy.h"
#include "Chart.h"

FileManagerForm::FileManagerForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileManagerForm),
    folder_strat(new FoldersStrategy),
    types_strat(new FileTypesStrategy),
    strategy(folder_strat)
{
    ui->setupUi(this);
    tree_model = new QFileSystemModel(this);
    tree_model->setRootPath(QDir::currentPath());
    tree_model->setFilter(QDir::AllDirs | QDir::Hidden | QDir::NoDotAndDotDot );
    ui->treeView->setModel(tree_model);
    ui->treeView->header()->setSectionResizeMode(QHeaderView::ResizeToContents);

    observers.push_back(new FileDisplayModel(ui->stackedWidget->layout()));
    observers.push_back(new PieChart(ui->stackedWidget->layout()));
    observers.push_back(new BarChart(ui->stackedWidget->layout()));
    for (auto& obs : observers) {
        folder_strat->Subscribe(obs);
        types_strat->Subscribe(obs);
    }

    connect(ui->groupBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &FileManagerForm::changeGrouping);
    connect(ui->treeView->selectionModel(), &QItemSelectionModel::selectionChanged,
            this,  &FileManagerForm::selectionChanged);
    connect(ui->displayBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &FileManagerForm::changeDisplay);
}

FileManagerForm::~FileManagerForm()
{
    qDeleteAll(observers);
    delete ui;
    delete folder_strat;
    delete types_strat;
    delete tree_model;
}

void FileManagerForm::changeGrouping(int index)
{
    switch (index) {
    case 0:
        strategy = folder_strat;
        break;
    case 1:
        strategy = types_strat;
        break;
    default:
        strategy = folder_strat;
        break;
    }
    strategy->Calculate(path);
}

void FileManagerForm::changeDisplay(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
}

void FileManagerForm::selectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    Q_UNUSED(deselected);

    QModelIndexList indexes = selected.indexes();
    path = tree_model->filePath(indexes[0]);
    strategy->Calculate(path);
}

