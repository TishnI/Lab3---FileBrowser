#ifndef CALCULATIONSTRATEGY_H
#define CALCULATIONSTRATEGY_H
#include <QString>
#include <QDir>
#include <QDebug>
#include <QMap>


class CalculationStrategy
{
public:
    virtual QMap<QString, double> Calculate(const QString&) = 0;
    virtual ~CalculationStrategy() = default;
};

#endif // CALCULATIONSTRATEGY_H
