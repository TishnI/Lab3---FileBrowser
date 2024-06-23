#include <QCoreApplication>

#include <QDir>
#include <QFileInfoList>
#include "CalculationStrategy.h"
#include "ByFileTypeCalcStrategy.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CalculationStrategy *calculation;
    CalculationStrategy *fileTypeStrategy = new ByFileTypeCalcStrategy();

    calculation = fileTypeStrategy;

    calculation->Calculate("Files");


    return a.exec();
}
