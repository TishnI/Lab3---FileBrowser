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
            QString suffix = fileInfo.suffix();
            QMap<QString, qint64>::Iterator it = map.find(suffix);
            if(it != map.end())
            {
                it.value() += fileInfo.size();
            }
            else
            {
                map.insert(suffix, fileInfo.size());
            }
        }
    }

    QMapIterator<QString, qint64> it(map);
    while(it.hasNext())
    {
        it.next();
        qDebug()<< it.key() << ": "<< it.value();
    }

}
