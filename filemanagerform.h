#ifndef FILEMANAGERFORM_H
#define FILEMANAGERFORM_H
#include "CalculateStrategy.h"
#include "filedisplaymodel.h"
#include "FileTypesStrategy.h"
#include "FoldersStrategy.h"
#include <QFileSystemModel>
#include <QItemSelection>
#include <QWidget>

namespace Ui {
class FileManagerForm;
}

class FileManagerForm : public QWidget
{
    Q_OBJECT
public:
    explicit FileManagerForm(QWidget *parent = nullptr);
    ~FileManagerForm();
protected slots:
    void changeGrouping(int index);
    void changeDisplay(int index);
    void selectionChanged(const QItemSelection& selected, const QItemSelection& deselected);
private:
    Ui::FileManagerForm *ui;
    QString path;
    // strategies
    CalculateStrategy* folder_strat;
    CalculateStrategy* types_strat;
    CalculateStrategy* strategy;
    //observers
    QList<FileObserver*> observers;
    //models
    QFileSystemModel* tree_model;
};

#endif // FILEMANAGERFORM_H
