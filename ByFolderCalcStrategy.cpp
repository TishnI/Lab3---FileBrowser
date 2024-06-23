#include "ByFolderCalcStrategy.h"

void ByFolderCalcStrategy::Calculate(const QString &path)
{
    QDir dir(path);
    dir.setFilter(QDir::Files | QDir::AllDirs | QDir::NoDotAndDotDot );


    QFileInfoList list = dir.entryInfoList();
    for(int i = 0; i < list.size(); ++i)
    {
        QString dirName = dir.dirName();
        QFileInfo fileInfo = list.at(i);
        if(fileInfo.isDir())
        {
            Calculate(fileInfo.filePath());
        }
        else
        {
            totalSize += fileInfo.size();
            map[dirName] += fileInfo.size();
        }
    }
}

void ByFolderCalcStrategy::GetStatus()
{
    QMapIterator<QString, double> it(map);
    while(it.hasNext())
    {
        it.next();
        qDebug()<< it.key() << ": "<< 100 * it.value()/ totalSize;
    }
}
