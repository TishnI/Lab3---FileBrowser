#include <QCoreApplication>

#include <QDir>
#include <QFileInfoList>
#include "CalculationStrategy.h"
#include "ByFileTypeCalcStrategy.h"
#include "ByFolderCalcStrategy.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CalculationStrategy *calculation;
    CalculationStrategy *fileTypeStrategy = new ByFileTypeCalcStrategy();
    CalculationStrategy *folderStrategy = new ByFolderCalcStrategy();

    //calculation = folderStrategy;
    calculation = fileTypeStrategy;

    calculation->Calculate("Files");
    calculation->GetStatus();


    return a.exec();
}
