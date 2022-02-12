#ifndef CALCULATESIZEFUNCTIONS_H
#define CALCULATESIZEFUNCTIONS_H
#include <QString>
#include <QDir>
#include <QMap>

namespace CalculateSize
{
    qint64 getTotalSize(const QString& path);
    qint64 sumSizes(const QMap<QString, qint64>& Sizes);
    qint64 getSizeOfDir(const QString& path);

}


#endif // CALCULATESIZEFUNCTIONS_H
