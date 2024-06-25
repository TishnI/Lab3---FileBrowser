#ifndef BYFOLDERCALCSTRATEGY_H
#define BYFOLDERCALCSTRATEGY_H

#include "CalculationStrategy.h"

class ByFolderCalcStrategy : public CalculationStrategy
{
public:
    ByFolderCalcStrategy() = default;
    QMap<QString, double> Calculate(const QString& path);

private:
    double CalculateInDir(const QString& path);
};

#endif // BYFOLDERCALCSTRATEGY_H
