#ifndef FILEBROWSER_H
#define FILEBROWSER_H

#include "CalculationStrategy.h"

class FileBrowser
{
public:
    FileBrowser() = default;
    FileBrowser(CalculationStrategy* calcStrategy);
    ~FileBrowser();
    void Calculate(const QString& path);
    void SetStrategy(CalculationStrategy* calcStrategy);
    QMap<QString, double> GetInfo();

private:
    CalculationStrategy* strategy;
    QMap<QString, double> map;
};

#endif // FILEBROWSER_H
