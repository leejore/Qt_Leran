#ifndef THREAD_H
#define THREAD_H

#include <QThread>

class thread : public QThread
{
    Q_OBJECT
public:
    explicit thread(QObject *parent = 0);

signals:

public slots:

};

#endif // THREAD_H
