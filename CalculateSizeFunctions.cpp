#include "CalculateSizeFunctions.h"

qint64 CalculateSize::getTotalSize(const QString &path)
{
    QDir folder(path);
    qint64 totalSize = 0;
    for (auto& it : folder.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot | QDir::Hidden, QDir::Name | QDir::Type | QDir::Size))
    {
        if (it.isDir() && !it.isSymLink()) {
            totalSize += getTotalSize(it.absoluteFilePath());
        } else {
            totalSize += it.size();
        }
    }
    return totalSize;
}

qint64 CalculateSize::sumSizes(const QMap<QString, qint64> &Sizes)
{
    qint64 totalSize = 0;
    auto values = Sizes.values();
    foreach(qint64 size, values)
        totalSize += size;
    return totalSize;
}

qint64 CalculateSize::getSizeOfDir(const QString &path)
{
    qint64 totalSize = 0;
    QDir dir(path);
    for (auto& it : dir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot , QDir::Name | QDir::Type))
        totalSize += it.size();
    return totalSize;
}
