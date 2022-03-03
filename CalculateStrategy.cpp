#include "CalculateStrategy.h"


void CalculateStrategy::Subscribe(FileObserver *observer)
{
    if (observer) {
        observers.append(observer);
    }
}

void CalculateStrategy::Unsubscribe(FileObserver *observer)
{
    if (observer) {
        observers.removeOne(observer);
    }
}

void CalculateStrategy::Update(const QList<Data> &data)
{
    for (auto& x : observers)
    {
        x->UpdateData(data);
    }
}
