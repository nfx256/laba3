#ifndef FOLDERSSTRATEGY_H
#define FOLDERSSTRATEGY_H
#include "CalculateStrategy.h"
#include <QPair>

class FoldersStartegy : public ICalculate
{
public:
    FoldersStartegy() = default;
    void Calculate(const QString &path) override;
    virtual ~FoldersStartegy() {}
private:
    QMap<QString, qint64> CalculateFoldersSizes(const QString& path) const;
    QList<QPair<QString, double> >  CalculateFoldersPercentage(const qint64& totalSize, const QMap<QString, qint64>& FoldersList) const;
    void PrintToConsole(const QMap<QString, qint64>& FoldersListSizes, const QList<QPair<QString, double> >& FoldersAndPercents) const;
};

#endif // FOLDERSSTRATEGY_H
