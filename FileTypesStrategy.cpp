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
    QMap<QString, qint64> FileTypesAndSizes;
    CalculateTypesAndSizes(path, FileTypesAndSizes);
    QList<QPair<QString, double> > FoldersAndPercents = CalculateTypesPercentage(CalculateSize::sumSizes(FileTypesAndSizes), FileTypesAndSizes);
    PrintToConsole(FileTypesAndSizes, FoldersAndPercents);
}

void FileTypesStartegy::CalculateTypesAndSizes(const QString &path, QMap<QString, qint64> &fileTypesAndSizes) const
{
    QDir folder(path);

    for (auto& f : folder.entryInfoList(QDir::Dirs | QDir::Files | QDir::Hidden | QDir::NoDotAndDotDot, QDir::Name | QDir::Type))
    {
        if (f.isDir() && !f.isSymLink())
        {
            CalculateTypesAndSizes(f.absoluteFilePath(), fileTypesAndSizes);
        } else {
            if (fileTypesAndSizes.keys().contains(f.suffix().toLower()))
            {
                fileTypesAndSizes[f.suffix()] += f.size();
            } else {
                fileTypesAndSizes.insert(f.suffix().toLower(), f.size());
            }
        }
    }
}

QList<QPair<QString, double> > FileTypesStartegy::CalculateTypesPercentage(qint64 totalSize,
                                            QMap<QString, qint64> &fileTypesAndSizes) const
{
    QList<QPair<QString, double> > TypesAndPercents;
    double percent;
    for (auto it = fileTypesAndSizes.begin(); it != fileTypesAndSizes.end(); ++it)
    {
        if (it.value() == 0) {
            percent = 0.0;
        } else {
            percent = double(it.value() * 100) / totalSize;
            if (percent < 0.01)
                percent = -percent;
        }
        TypesAndPercents.append(qMakePair(it.key(), percent));
    }
    return TypesAndPercents;
}

void FileTypesStartegy::PrintToConsole(const QMap<QString, qint64> &TypesListSizes,
                                       const QList<QPair<QString, double> > &TypesAndPercents) const
{
    QTextStream out(stdout);
    out.setCodec("CP866");
    for (auto& x : TypesAndPercents)
    {
        out << qSetFieldWidth(10) << "*." + x.first
            << qSetFieldWidth(10)  << TypesListSizes.value(x.first) / 1024.0
            << qSetFieldWidth(4)<< "KB";
        if (x.second < 0) {
            out << qSetFieldWidth(8) << "< 0.01 %\n";
        } else {
            out << qSetFieldWidth(8) << QString::number(x.second, 'f', 2).append(" %") << "\n";
        }
    }
}
