#ifndef BYFILETYPECALCSTRATEGY_H
#define BYFILETYPECALCSTRATEGY_H

#include "CalculationStrategy.h"

class ByFileTypeCalcStrategy: public CalculationStrategy
{
public:
    ByFileTypeCalcStrategy() = default;
    QMap<QString, double> Calculate(const QString& path);

private:
    void CalculateInDir(const QString& path, QMap<QString, double>& map);
};

#endif // BYFILETYPECALCSTRATEGY_H
