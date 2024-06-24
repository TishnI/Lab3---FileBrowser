#include "ByFileTypeCalcStrategy.h"

QMap<QString, double> ByFileTypeCalcStrategy::Calculate(const QString &path)
{
    QMap<QString, double> typeOfFile;
    CalculateInDir(path, typeOfFile);
    return typeOfFile;
}

void ByFileTypeCalcStrategy::CalculateInDir(const QString &path, QMap<QString, double>& map)
{
    QDir dir(path);
    dir.setFilter(QDir::Files | QDir::AllDirs | QDir::NoDotAndDotDot );

    QFileInfoList list = dir.entryInfoList();
    for(int i = 0; i < list.size(); ++i)
    {
        QFileInfo fileInfo = list.at(i);
        if(fileInfo.isDir())
        {
            CalculateInDir(fileInfo.filePath(), map);
        }
        else
        {
            map[fileInfo.suffix()] += fileInfo.size();
        }
    }
}
