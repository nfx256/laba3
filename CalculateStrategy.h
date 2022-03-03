#ifndef CALCULATESTRATEGY_H
#define CALCULATESTRATEGY_H
#include <QString>
#include <QList>
#include "Data.h"
#include "FileObserver.h"

class CalculateStrategy
{
public:
    virtual void Calculate(const QString& path) = 0;
    void Subscribe(FileObserver* observer);
    void Unsubscribe(FileObserver* observer);
    void Update(const QList<Data>& data);
    virtual ~CalculateStrategy() {}
private:
    QList<FileObserver*> observers;
};


#endif // CALCULATESTRATEGY_H
