#include <QCoreApplication>
#include "FoldersStrategy.h"
#include "CalculateStrategy.h"


int main(int argc, char *argv[])
{
    ICalculate* calc_strat = new FoldersStartegy();
    CalculateStrategy* calc = new CalculateStrategy(calc_strat);
    calc->Calculate("D:/Temp");
    delete calc;
    delete calc_strat;
    return 0;
}
