#include "FileBrowser.h"

FileBrowser::FileBrowser(CalculationStrategy* calcStrategy):strategy(calcStrategy) {}

FileBrowser::~FileBrowser()
{
    delete strategy;
}

void FileBrowser::Calculate(const QString &path)
{
    map = strategy->Calculate(path);
}

void FileBrowser::SetStrategy(CalculationStrategy *calcStrategy)
{
    strategy = calcStrategy;
}

QMap<QString, double> FileBrowser::GetInfo()
{
    return map;
}
