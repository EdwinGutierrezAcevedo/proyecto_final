#include "homero.h"

Homero::Homero(QObject *parent)
    : QObject{parent}, QGraphicsPixmapItem(), isJumping(false), jumpFrame(0)
{
    setFlag(QGraphicsItem::ItemIsFocusable); // Habilitar que Homero pueda recibir el foco
    setFocus(); // Establecer el foco en Homero
    timer = new QTimer(this);
    filas = 0;
    columnas = 0;
    // Dimensión de cada sección del sprite
    ancho = 75.0*1.7;  // Reducir el ancho al 70%
    alto = 75.0*1.7;   // Reducir el alto al 70%
    QPixmap originalPixmap(":/new/prefix1/spriteHomeroCorre.png");
    pixmap = new QPixmap(originalPixmap.scaled(9*ancho, alto, Qt::KeepAspectRatio));

    // Inicializar el sprite de salto
    QPixmap originalJumpPixmap(":/new/prefix1/spriteHomeroSaltando.png");
    jumpPixmap = new QPixmap(originalJumpPixmap.scaled(6 * ancho, alto, Qt::KeepAspectRatio));
    jumpTimer = new QTimer(this);
    connect(jumpTimer, &QTimer::timeout, this, &Homero::Actualizacion);

    if (pixmap->isNull() || jumpPixmap->isNull()) {
        qDebug() << "Error: No se pudo cargar uno o más sprites de Homero.";
    } else {
        qDebug() << "Sprites de Homero cargados correctamente.";
    }
    timer->start(50);
    connect(timer, &QTimer::timeout, this, &Homero::Actualizacion);
}


void Homero::Actualizacion()
{
    if (isJumping) {
        jumpFrame += ancho;
        if (jumpFrame >= jumpPixmap->width()) {
            jumpFrame = 0;
            isJumping = false;
            jumpTimer->stop();
            timer->start(100);  // Regresar al sprite original
        }
        this->update(-ancho / 2, -alto / 2, ancho, alto);
    } else {
        columnas += ancho;
        if (columnas >= pixmap->width()) {
            columnas = 0.0;
        }
        this->update(-ancho / 2, -alto / 2, ancho, alto);
    }
}

void Homero::Saltar()
{
    if (!isJumping) {
        isJumping = true;
        jumpFrame = 0;
        timer->stop();
        jumpTimer->start(100);
    }
}



QRectF Homero::boundingRect() const
{
    return QRectF(-ancho / 2, -alto / 2, ancho, alto);
}

void Homero::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (isJumping) {
        painter->drawPixmap(-ancho / 2, -alto / 2, *jumpPixmap, jumpFrame, 0, ancho, alto);
    } else {
        painter->drawPixmap(-ancho / 2, -alto / 2, *pixmap, columnas, 0, ancho, alto);
    }
}

void Homero::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space) {
        Saltar();  // Iniciar la animación de salto
    }
}



