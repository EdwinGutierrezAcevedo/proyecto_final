#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "homero.h"
#include <QGraphicsRectItem> // Paquete para uso de rectangulos desde Qt.
#include <QGraphicsPixmapItem> //Paquete para imagenes.
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer> // Para el temporizador
#include <QDebug> // Para la depuración

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Inicializar la escena
    scene = new QGraphicsScene(this);

    // Crear un temporizador para mover el fondo
    QTimer *backgroundTimer = new QTimer(this);
    connect(backgroundTimer, &QTimer::timeout, this, &MainWindow::moveBackground);
    backgroundTimer->start(10);  // Mover el fondo cada 50 ms

    // Agregar la imagen de fondo como parte de la escena
    QPixmap bk = QPixmap(":/new/prefix1/fondo.png").scaled(4000, 1500, Qt::KeepAspectRatio);
    if (bk.isNull()) {
        qDebug() << "Error: No se pudo cargar la imagen del fondo.";
    } else {
        fondo1 = new QGraphicsPixmapItem(bk);
        fondo2 = new QGraphicsPixmapItem(bk);
        qDebug() << "Imagen del fondo cargada correctamente.";
        fondo1->setPos(0, 0);  // Posicionar la primera imagen en el origen de la escena
        fondo2->setPos(fondo1->boundingRect().width(), 0);  // Posicionar la segunda imagen a la derecha de la primera
        scene->addItem(fondo1);  // Agregar el primer fondo a la escena
        scene->addItem(fondo2);  // Agregar el segundo fondo a la escena
    }

    // Asignar la escena al QGraphicsView que definiste en el archivo .ui
    ui->graphicsView->setScene(scene);

    // Ajustar la vista al tamaño de la escena
    ui->graphicsView->setFixedSize(1000, 500);

    // MainWindow Constructor - mainwindow.cpp
    homero = new Homero();
    homero->setPos(300, 560);
    scene->addItem(homero);
    homero->setFocus();  // Establecer el foco en Homero
    scene->setFocusItem(homero);  // Asegurar que Homero sea el elemento enfocado

    // Centrar la vista en el personaje Homero
    ui->graphicsView->centerOn(homero);

    // Inicializar y posicionar el objeto cono
    cono = new Cono();
    cono->setPos(1000, 570);  // Posición inicial del cono
    //scene->addItem(cono);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::detenerJuego()
{
    backgroundTimer->stop();
    homero->stopTimers();
    cono->setX(cono->x());  // Opcionalmente, detener el movimiento del cono
    qDebug() << "Juego detenido debido a colisión con el cono.";
}


// Mover el fondo hacia la izquierda
void MainWindow::moveBackground()
{
    fondo1->setX(fondo1->x() - 5);  // Mover el primer fondo 5 píxeles a la izquierda
    fondo2->setX(fondo2->x() - 5);  // Mover el segundo fondo 5 píxeles a la izquierda
    cono->setX(cono->x() - 5);  // Mover el cono 5 píxeles a la izquierda

    // Reiniciar la posición de los fondos
    if (fondo1->x() <= -fondo1->boundingRect().width()) {
        fondo1->setX(fondo2->x() + fondo2->boundingRect().width());  // Mover fondo1 a la derecha del fondo2
    }
    if (fondo2->x() <= -fondo2->boundingRect().width()) {
        fondo2->setX(fondo1->x() + fondo1->boundingRect().width());  // Mover fondo2 a la derecha del fondo1
    }

    // Reiniciar la posición del cono si sale de la escena
    if (cono->x() <= -cono->boundingRect().width()) {
        cono->setX(1000);  // Volver a poner el cono a la derecha de la escena
    }

    // Verificar colisión con Homero
    if (homero->collidesWithItem(cono)) {
        detenerJuego();  // Llama a detenerJuego si hay una colisión
    }
}


