#ifndef BYFOLDERCALCSTRATEGY_H
#define BYFOLDERCALCSTRATEGY_H

#include "CalculationStrategy.h"

class ByFolderCalcStrategy : public CalculationStrategy
{
public:
    ByFolderCalcStrategy() = default;
    void Calculate(const QString& path);
    void GetStatus();
};

#endif // BYFOLDERCALCSTRATEGY_H
