#ifndef FILEBROWSER_H
#define FILEBROWSER_H

#include "CalculationStrategy.h"

class FileBrowser
{
public:
    FileBrowser() = default;
    FileBrowser(CalculationStrategy* calcStrategy);
    ~FileBrowser();
    QMap<QString, double> Calculate(const QString& path);
    void SetStrategy(CalculationStrategy* calcStrategy);

private:
    CalculationStrategy* strategy;
};

#endif // FILEBROWSER_H
