#include "FileBrowser.h"

FileBrowser::FileBrowser(CalculationStrategy* calcStrategy):strategy(calcStrategy) {}

FileBrowser::~FileBrowser()
{
    delete strategy;
}

QMap<QString, double> FileBrowser::Calculate(const QString &path)
{
    if(strategy == nullptr)
    {
        qWarning()<<"Calculate: Strategy not initialized";
        return QMap<QString, double>();
    }
    return strategy->Calculate(path);
}

void FileBrowser::SetStrategy(CalculationStrategy *calcStrategy)
{
    if(calcStrategy == nullptr)
    {
        qWarning()<<"SetStrategy: Strategy not initialized";
        return;
    }
    strategy = calcStrategy;
}

