#include "filemanagerform.h"
#include "ui_filemanagerform.h"
#include "FoldersStrategy.h"
#include "FileTypesStrategy.h"


FileManagerForm::FileManagerForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileManagerForm)
{
    ui->setupUi(this);
    strategy = new CalculateStrategy();
    display_model = new FileDisplayModel();
    tree_model = new QFileSystemModel(this);
    tree_model->setRootPath(QDir::currentPath());
    tree_model->setFilter(QDir::AllDirs | QDir::Hidden | QDir::NoDotAndDotDot );
    ui->treeView->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->treeView->setModel(tree_model);
    group = Grouping::ByFolders;

    connect(ui->groupBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &FileManagerForm::changeGrouping);
    connect(ui->treeView->selectionModel(), &QItemSelectionModel::selectionChanged, this,  &FileManagerForm::selectionChanged);
}

FileManagerForm::~FileManagerForm()
{
    delete ui;
    delete strategy;
    delete display_model;
    delete tree_model;
}

void FileManagerForm::changeDataInModel()
{
    if (path.isEmpty())
        return;
    switch (group) {
    case Grouping::ByFolders:
        strategy->setStrategy(new FoldersStartegy);
        break;
    case Grouping::ByTypes:
        strategy->setStrategy(new FileTypesStartegy);
        break;
    }
    data = strategy->Calculate(path);
    display_model->setDataToModel(data);
    ui->tableView->setModel(display_model);
}

void FileManagerForm::changeGrouping(int index)
{
    switch (index) {
        case 0:
            group = Grouping::ByFolders;
            break;
        case 1:
            group = Grouping::ByTypes;
            break;
        default:
            group = Grouping::ByFolders;
            break;
    }
    changeDataInModel();
}

void FileManagerForm::selectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    Q_UNUSED(deselected);

    QModelIndexList indexes = selected.indexes();
    path = tree_model->filePath(indexes[0]);
    changeDataInModel();
}


