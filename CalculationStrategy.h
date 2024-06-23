#ifndef CALCULATIONSTRATEGY_H
#define CALCULATIONSTRATEGY_H
#include <QString>
#include <QDir>
#include <QDebug>


class CalculationStrategy
{
public:
    virtual void Calculate(const QString&) = 0;
    virtual void GetStatus() = 0;
    virtual ~CalculationStrategy() = default;

protected:
    double totalSize;
    QMap<QString, double> map;

};

#endif // CALCULATIONSTRATEGY_H
