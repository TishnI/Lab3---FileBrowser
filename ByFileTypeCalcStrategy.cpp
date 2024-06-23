#include "ByFileTypeCalcStrategy.h"

void ByFileTypeCalcStrategy::Calculate(const QString &path)
{
    QDir dir(path);
    dir.setFilter(QDir::Files | QDir::AllDirs | QDir::NoDotAndDotDot );

    QFileInfoList list = dir.entryInfoList();
    for(int i = 0; i < list.size(); ++i)
    {
        QFileInfo fileInfo = list.at(i);
        if(fileInfo.isDir())
        {
            Calculate(fileInfo.filePath());
        }
        else
        {
            totalSize += fileInfo.size();
            map[fileInfo.suffix()] += fileInfo.size();

        }
    }
}

void ByFileTypeCalcStrategy::GetStatus()
{
    QMapIterator<QString, double> it(map);
    while(it.hasNext())
    {
        it.next();
        qDebug()<< it.key() << ": "<< 100 * it.value()/totalSize;
    }
}
