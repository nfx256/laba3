#ifndef FOLDERSSTRATEGY_H
#define FOLDERSSTRATEGY_H
#include "CalculateStrategy.h"

class FoldersStartegy : public ICalculate
{
public:
    FoldersStartegy() = default;
    void Calculate(const QString &path) override;
    virtual ~FoldersStartegy() {}
};

#endif // FOLDERSSTRATEGY_H
