#include <QCoreApplication>
#include "FoldersStrategy.h"
#include "FileTypesStrategy.h"
#include "CalculateStrategy.h"


int main(int argc, char *argv[])
{
    ICalculate* calc_strat = new FileTypesStartegy;
    CalculateStrategy* calc = new CalculateStrategy(calc_strat);
    calc->Calculate("D:/pdf");
    delete calc;
    delete calc_strat;
    return 0;
}
