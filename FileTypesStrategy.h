#ifndef FILETYPESSTRATEGY_H
#define FILETYPESSTRATEGY_H
#include "CalculateStrategy.h"
#include <QPair>

class FileTypesStartegy : public ICalculate
{
public:
    FileTypesStartegy() = default;
    void Calculate(const QString &path) override;
    virtual ~FileTypesStartegy() {}
private:
    void CalculateTypesAndSizes(const QString& path, QMap<QString, qint64>& fileTypesAndSizes) const;
    QList<QPair<QString, double> > CalculateTypesPercentage(qint64 totalSize, QMap<QString, qint64>& fileTypesAndSizes) const;
    void PrintToConsole(const QMap<QString, qint64>& TypesListSizes, const QList<QPair<QString, double> >& TypesAndPercents) const;
};

#endif // FILETYPESSTRATEGY_H
