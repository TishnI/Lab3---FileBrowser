#ifndef BYFILETYPECALCSTRATEGY_H
#define BYFILETYPECALCSTRATEGY_H

#include "CalculationStrategy.h"
#include <QMap>

class ByFileTypeCalcStrategy: public CalculationStrategy
{
public:
    ByFileTypeCalcStrategy() = default;
    void Calculate(const QString& path);

private:
    QMap<QString, qint64> map;
};

#endif // BYFILETYPECALCSTRATEGY_H
