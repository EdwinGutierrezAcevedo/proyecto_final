#ifndef HOMERO_H
#define HOMERO_H

#include <QObject>

class Homero : public QObject
{
    Q_OBJECT
public:
    explicit Homero(QObject *parent = nullptr);

signals:
};

#endif // HOMERO_H
