#include "filemanagerform.h"
#include "ui_filemanagerform.h"

FileManagerForm::FileManagerForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileManagerForm)
{
    ui->setupUi(this);
}

FileManagerForm::~FileManagerForm()
{
    delete ui;
}
