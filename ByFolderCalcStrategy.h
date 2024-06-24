#ifndef BYFOLDERCALCSTRATEGY_H
#define BYFOLDERCALCSTRATEGY_H

#include "CalculationStrategy.h"

class ByFolderCalcStrategy : public CalculationStrategy
{
public:
    ByFolderCalcStrategy() = default;
    QMap<QString, double> Calculate(const QString& path);

private:
    void CalculateInDir(const QString& path, QMap<QString, double>& map);
};

#endif // BYFOLDERCALCSTRATEGY_H
