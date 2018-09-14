#ifndef APPMANAGER_H
#define APPMANAGER_H

#include <QObject>

class AppManager : public QObject
{
    Q_OBJECT
public:
    explicit AppManager(QObject *parent = nullptr);
    ~AppManager();

    Q_INVOKABLE void startApp(QString appname);

signals:

public slots:
};

#endif // APPMANAGER_H
