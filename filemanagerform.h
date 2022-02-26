#ifndef FILEMANAGERFORM_H
#define FILEMANAGERFORM_H
#include "CalculateStrategy.h"
#include "filedisplaymodel.h"
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
    enum class Grouping {
        ByFolders,
        ByTypes
    };
    explicit FileManagerForm(QWidget *parent = nullptr);
    ~FileManagerForm();
protected:
    void changeDataInModel();
protected slots:
    void changeGrouping(int index);
    void selectionChanged(const QItemSelection& selected, const QItemSelection& deselected);
private:
    Ui::FileManagerForm *ui;
    QList<Data> data;
    QString path;
    CalculateStrategy* strategy;
    Grouping group;
    QFileSystemModel* tree_model;
    FileDisplayModel* display_model;
};

#endif // FILEMANAGERFORM_H
