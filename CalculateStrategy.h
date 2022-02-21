#ifndef CALCULATESTRATEGY_H
#define CALCULATESTRATEGY_H
#include <QString>

class ICalculate
{
public:
    virtual void Calculate(const QString& path) = 0;
    virtual ~ICalculate() {}
};

class CalculateStrategy
{
public:
    explicit CalculateStrategy(ICalculate* c) : strat(c) {}
    void Calculate(const QString& path)
    {
        strat->Calculate(path);
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
