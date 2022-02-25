#include "FoldersStrategy.h"
#include "FileTypesStrategy.h"
#include "CalculateStrategy.h"
#include "filemanagerform.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv) ;
    FileManagerForm f;
    f.show();
    return app.exec();
}
