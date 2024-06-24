#include <QCoreApplication>

#include <QDir>
#include <QFileInfoList>
#include "CalculationStrategy.h"
#include "ByFileTypeCalcStrategy.h"
#include "ByFolderCalcStrategy.h"
#include "FileBrowser.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream out(stdout);

    FileBrowser* fileBrowser = new FileBrowser();

    CalculationStrategy *fileTypeStrategy = new ByFileTypeCalcStrategy();
    CalculationStrategy *folderStrategy = new ByFolderCalcStrategy();

    QMap<QString, double> result;

    fileBrowser->SetStrategy(fileTypeStrategy);
    fileBrowser->Calculate("Files");
    result = fileBrowser->GetInfo();

    for(auto key : result.keys())
    {
        out<<key<<": "<<result[key]<<Qt::endl;
    }

    out<<Qt::endl;

    fileBrowser->SetStrategy(folderStrategy);
    fileBrowser->Calculate("Files");
    result = fileBrowser->GetInfo();

    for(auto key : result.keys())
    {
        out<<key<<": "<<result[key]<<Qt::endl;
    }


    delete fileBrowser;
    return a.exec();
}
