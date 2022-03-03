#ifndef FILEOBSERVER_H
#define FILEOBSERVER_H
#include "Data.h"

class FileObserver
{
public:
    FileObserver() {}
    virtual void UpdateData(const QList<Data>& data) = 0;
    virtual ~FileObserver() {}
};


#endif // FILEOBSERVER_H
