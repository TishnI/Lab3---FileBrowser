#include "ByFolderCalcStrategy.h"

QMap<QString, double> ByFolderCalcStrategy::Calculate(const QString &path)
{
    QMap<QString, double> folders;

    double size = 0;
    QDir dir(path);
    dir.setFilter(QDir::Files | QDir::AllDirs | QDir::NoDotAndDotDot | QDir::NoSymLinks );
    QFileInfoList list = dir.entryInfoList();
    for(int i = 0; i < list.size(); ++i)
    {

        QFileInfo fileInfo = list.at(i);
        if(fileInfo.isDir())
        {
            folders[fileInfo.fileName()] += CalculateInDir(fileInfo.filePath());
        }
        else
        {
            size+=fileInfo.size();
        }
    }

    folders["Current directory"] = size;
    return folders;
}

double ByFolderCalcStrategy::CalculateInDir(const QString &path)
{
    double size = 0;
    QDir dir(path);
    dir.setFilter(QDir::Files | QDir::AllDirs | QDir::NoDotAndDotDot | QDir::NoSymLinks );
    QFileInfoList list = dir.entryInfoList();
    for(int i = 0; i < list.size(); ++i)
    {
        QFileInfo fileInfo = list.at(i);
        //qDebug()<<fileInfo.filePath();
        if(fileInfo.isDir())
        {
            size += CalculateInDir(fileInfo.filePath());
        }
        else
        {
            size += fileInfo.size();
        }
    }
    return size;
}
