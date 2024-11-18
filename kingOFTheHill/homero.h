#ifndef HOMERO_H
#define HOMERO_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <QDebug>
#include <QKeyEvent>

class Homero : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Homero(QObject *parent = nullptr);
    QTimer *timer;
    QPixmap *pixmap;

    float filas, columnas;
    float ancho, alto;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void Saltar(); // Nueva función para manejar el salto

private:

    bool isJumping; // Bandera para verificar si está saltando
    int jumpFrame; // Marco actual del salto
    QPixmap *jumpPixmap; // Nuevo pixmap para el salto
    QTimer *jumpTimer;    // Temporizador para el salto

protected:
    void keyPressEvent(QKeyEvent *event) override;  // Añadir la función de eventos de teclado

signals:

public slots:
    void Actualizacion();
};

#endif // HOMERO_H

