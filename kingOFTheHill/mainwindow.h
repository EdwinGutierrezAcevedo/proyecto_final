#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene> // Paquete para control de escena
#include <QGraphicsView> // Paquete para vistas
#include <QGraphicsPixmapItem> // Paquete para imágenes
#include <QTimer> // Para el temporizador
#include <QKeyEvent>
#include "homero.h"
#include "cono.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;   // La escena que se va a construir
    Homero *homero;
    QGraphicsPixmapItem* fondo1;  // Variable para el primer fondo
    QGraphicsPixmapItem* fondo2;  // Variable para el segundo fondo
    Cono *cono; // Variable para el objeto Cono
    void detenerJuego();  // Función para detener el juego
    QTimer *backgroundTimer;  // Temporizador para mover el fondo
    QTimer *coneTimer;        // Temporizador para mover el cono (si es necesario)


private slots:
    void moveBackground();  // Función para mover el fondo
};

#endif // MAINWINDOW_H

