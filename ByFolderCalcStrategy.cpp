#include "ByFolderCalcStrategy.h"

QMap<QString, double> ByFolderCalcStrategy::Calculate(const QString &path)
{
    QMap<QString, double> folders;
    CalculateInDir(path,folders);
    return folders;
}

void ByFolderCalcStrategy::CalculateInDir(const QString &path, QMap<QString, double>& map)
{
    QDir dir(path);
    dir.setFilter(QDir::Files | QDir::AllDirs | QDir::NoDotAndDotDot );


    QFileInfoList list = dir.entryInfoList();
    map[dir.dirName()] = 0;
    for(int i = 0; i < list.size(); ++i)
    {
        QString dirName = dir.dirName();
        QFileInfo fileInfo = list.at(i);
        if(fileInfo.isDir())
        {
            CalculateInDir(fileInfo.filePath(), map);
        }
        else
        {
            map[dirName] += fileInfo.size();
        }
    }
}


/*void ByFolderCalcStrategy::GetStatus()
{
    QMapIterator<QString, double> it(map);
    while(it.hasNext())
    {
        it.next();
        qDebug()<< it.key() << ": "<< 100 * it.value()/ totalSize;
    }
}*/
