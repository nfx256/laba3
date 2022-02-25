#ifndef DATA_H
#define DATA_H
#include <QString>

struct Data
{
    QString name_;
    int size_;
    qreal percent_;
    Data(const QString& name, int size, qreal percent)
                : name_(name), size_(size), percent_(percent) {}
};
#endif // DATA_H
