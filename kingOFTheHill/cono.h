#ifndef CONO_H
#define CONO_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Cono : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Cono(QObject *parent = nullptr);
    QRectF boundingRect() const override;
};

#endif // CONO_H
