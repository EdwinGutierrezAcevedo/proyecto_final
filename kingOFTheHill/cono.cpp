#include "cono.h"

Cono::Cono(QObject *parent)
    : QObject{parent}, QGraphicsPixmapItem()
{
    QPixmap conoPixmap(":/new/prefix1/cono.png");
    setPixmap(conoPixmap.scaled(40, 40, Qt::KeepAspectRatio));  // Ajusta el tamaño del cono según sea necesario
}

QRectF Cono::boundingRect() const
{
    return pixmap().rect();
}
