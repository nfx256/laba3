#include "FoldersStrategy.h"
#include "FileTypesStrategy.h"
#include "CalculateStrategy.h"


int main(int argc, char *argv[])
{
    ICalculate* calc_strat = new FileTypesStartegy;
    CalculateStrategy* calc = new CalculateStrategy(calc_strat);
    auto data = calc->Calculate("D:/Temp");
    calc->setStrategy(new FoldersStartegy);
    auto data2 = calc->Calculate("D:/Temp");
    delete calc;
    return 0;
}
