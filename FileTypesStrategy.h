#ifndef FILETYPESSTRATEGY_H
#define FILETYPESSTRATEGY_H
#include "CalculateStrategy.h"

class FileTypesStartegy : public ICalculate
{
public:
    FileTypesStartegy() = default;
    void Calculate(const QString &path) override;
    virtual ~FileTypesStartegy() {}
};

#endif // FILETYPESSTRATEGY_H
