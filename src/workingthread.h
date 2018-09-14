#ifndef WORKINGTHREAD_H
#define WORKINGTHREAD_H

#include <QThread>

class WorkingTHread : public QThread
{
    Q_OBJECT
public:
    WorkingTHread();
    ~WorkingTHread();
};

#endif // WORKINGTHREAD_H
