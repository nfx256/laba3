#ifndef CALCULATESTRATEGY_H
#define CALCULATESTRATEGY_H
#include <QString>
#include <QList>
#include "Data.h"

class ICalculate
{
public:
    virtual QList<Data> Calculate(const QString& path) = 0;
    virtual ~ICalculate() {}
};

class CalculateStrategy
{
public:
    explicit CalculateStrategy(ICalculate* c) : strat(c) {}
    QList<Data> Calculate(const QString& path)
    {
        if (strat) {
            return strat->Calculate(path);
        } else {
            return QList<Data>();
        }
    }
    void setStrategy(ICalculate* calculate_strategy)
    {
        if (strat) {
            delete strat;
        }
        strat = calculate_strategy;
    }
    ~CalculateStrategy()
    {
        if (strat) {
            delete strat;
        }
    }
private:
    ICalculate *strat = nullptr;
};

#endif // CALCULATESTRATEGY_H
