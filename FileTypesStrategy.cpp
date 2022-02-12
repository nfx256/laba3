#include "FileTypesStrategy.h"
#include "CalculateSizeFunctions.h"
#include <QFileInfo>
#include <QDebug>

void FileTypesStartegy::Calculate(const QString &path)
{
    QFileInfo folder(path);
    if (!folder.exists() && !folder.isReadable()){
        qDebug() << "Error! Folder doesn't exist or not readable." << Qt::endl;
        return;
    }
}
