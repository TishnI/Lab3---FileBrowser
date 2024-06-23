#ifndef CALCULATIONSTRATEGY_H
#define CALCULATIONSTRATEGY_H
#include <QString>
#include <QDir>
#include <QDebug>


class CalculationStrategy
{
public:
    virtual void Calculate(const QString&) = 0;
};

#endif // CALCULATIONSTRATEGY_H
