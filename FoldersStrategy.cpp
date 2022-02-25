#include "FoldersStrategy.h"
#include "CalculateSizeFunctions.h"
#include <QFileInfo>
#include <QDebug>


QList<Data> FoldersStartegy::Calculate(const QString &path)
{
    QFileInfo folder(path);
    if (!folder.exists() && !folder.isReadable()){
        qDebug() << "Error! Folder doesn't exist or not readable" << Qt::endl;
        return QList<Data>();
    }
    QMap<QString, qint64> FoldersSizesList = CalculateFoldersSizes(path);
    QList<QPair<QString, double> > FoldersAndPercents = CalculateFoldersPercentage(CalculateSize::sumSizes(FoldersSizesList), FoldersSizesList);
//    PrintToConsole(FoldersSizesList, FoldersAndPercents);
    return MergeToData(FoldersSizesList, FoldersAndPercents);
}

QMap<QString, qint64> FoldersStartegy::CalculateFoldersSizes(const QString &path) const
{
    QFileInfo folder(path);
    QString absolutePath = folder.absoluteFilePath();
    QMap<QString, qint64> FoldersSizesList;
    FoldersSizesList.insert(absolutePath, CalculateSize::getSizeOfDir(absolutePath));
    for (auto& f : QDir(path).entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot | QDir::Hidden, QDir::Name | QDir::Type))
    {
        QString absolutePath = f.absoluteFilePath();
        FoldersSizesList.insert(absolutePath, CalculateSize::getTotalSize(absolutePath));
    }
    return FoldersSizesList;
}

QList<QPair<QString, double> > FoldersStartegy::CalculateFoldersPercentage(const qint64& totalSize,
            const QMap<QString, qint64>& FoldersList) const
{
    QList<QPair<QString, double> > FoldersAndPercents;
    double percent;
    for (auto it = FoldersList.begin(); it != FoldersList.end(); ++it)
    {
        if (it.value() == 0) {
            percent = 0.0;
        } else {
            percent = double(it.value() * 100) / totalSize;
            if (percent < 0.01)
                percent = -percent;
        }
        FoldersAndPercents.append(qMakePair(it.key(), percent));
    }
    return FoldersAndPercents;
}

void FoldersStartegy::PrintToConsole(const QMap<QString, qint64>& FoldersListSizes, const QList<QPair<QString, double> >& FoldersAndPercents) const
{
    QTextStream out(stdout);
    out.setCodec("CP866");
    for (auto& x : FoldersAndPercents)
    {
        out << qSetFieldWidth(60) << x.first << qSetFieldWidth(10)  << FoldersListSizes.value(x.first) / 1024.0
            << qSetFieldWidth(4)<< "KB";
        if (x.second < 0) {
            out << qSetFieldWidth(8) << "< 0.01 %\n";
        } else {
            out << qSetFieldWidth(8) << QString::number(x.second, 'f', 2).append(" %") << "\n";
        }
    }
}

QList<Data> FoldersStartegy::MergeToData(const QMap<QString, qint64> &FoldersListSizes, const QList<QPair<QString, double> > &FoldersAndPercents) const
{
    QList<Data> data;
    for (auto& x : FoldersAndPercents)
    {
        data.append(Data(x.first, FoldersListSizes.value(x.first), x.second));
    }
    return data;
}
