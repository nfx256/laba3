#ifndef FILEMANAGERFORM_H
#define FILEMANAGERFORM_H

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

private:
    Ui::FileManagerForm *ui;
};

#endif // FILEMANAGERFORM_H
