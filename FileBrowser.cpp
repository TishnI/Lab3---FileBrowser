#include "FileBrowser.h"

FileBrowser::FileBrowser(CalculationStrategy* calcStrategy):strategy(calcStrategy) {}

FileBrowser::~FileBrowser()
{
    delete strategy;
}

void FileBrowser::Calculate(const QString &path)
{
    if(strategy == nullptr)
    {
        qWarning()<<"Calculate: Strategy not initialized";
        return;
    }
    map = strategy->Calculate(path);
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

QMap<QString, double> FileBrowser::GetInfo()
{
    return map;
}
