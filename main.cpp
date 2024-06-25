#include <QCoreApplication>

#include <cmath>
#include <QDir>
#include <QFileInfoList>
#include "CalculationStrategy.h"
#include "ByFileTypeCalcStrategy.h"
#include "ByFolderCalcStrategy.h"
#include "FileBrowser.h"


void PrintResult(const QMap<QString, double>& result)
{
    QTextStream out(stdout);
    double totalSize = 0;

    if(result.isEmpty())
    {
        return;
    }

    for(auto key : result.keys())
    {
        totalSize+=result[key];
    }

    for(auto key : result.keys())
    {
        double value = round((100 * result[key]/totalSize)*100)/100;
        if(value==0 && result[key]!=0)
        {
            out<<key<<"\t"<<result[key]/1000<<"KB \t<0.01%"<<Qt::endl;
        }
        else if (result[key] == 0)
        {
            out<<key<<"\t"<<result[key]<<"KB\t\t0%"<<Qt::endl;
        }
        else
        {
            out<<key<<"\t"<<result[key]/1000<<"KB\t"<<value<<"%"<<Qt::endl;
        }
    }

    out<<Qt::endl;
}

QString UserInput()
{
    QTextStream in(stdin);
    QTextStream out(stdout);
    QString input;

    out<<"Enter the directory path"<<Qt::endl;

    in>>input;
    out<<Qt::endl;
    return input;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream in(stdin);

    FileBrowser* fileBrowser = new FileBrowser();

    CalculationStrategy *fileTypeStrategy = new ByFileTypeCalcStrategy();
    CalculationStrategy *folderStrategy = new ByFolderCalcStrategy();

    while(true)
    {
        QString dirPath = UserInput();

        QMap<QString, double> result;

        fileBrowser->SetStrategy(fileTypeStrategy);
        //fileBrowser->SetStrategy(nullptr);
        result = fileBrowser->Calculate(dirPath);

        PrintResult(result);

        fileBrowser->SetStrategy(folderStrategy);
        result = fileBrowser->Calculate(dirPath);

        PrintResult(result);
    }


    delete fileBrowser;
    delete fileTypeStrategy;
    delete folderStrategy;
    return a.exec();
}
