#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "homero.h"
#include <QGraphicsRectItem> // Paquete para uso de rectangulos desde Qt.
#include <QGraphicsPixmapItem> //Paquete para imagenes.
#include <QTimer> // Para el temporizador
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Inicializar la escena
    scene = new QGraphicsScene(this);

    // Agregar la imagen de fondo como parte de la escena
    QPixmap bk =  QPixmap(":/new/prefix1/fondo.png").scaled(4000,1500,Qt::KeepAspectRatio);
    QGraphicsPixmapItem* fondo = new QGraphicsPixmapItem(bk);
    if (bk.isNull()) {
        qDebug() << "Error: No se pudo cargar la imagen del fondo.";
    } else {
        qDebug() << "Imagen del fondo cargada correctamente.";
    }
    fondo->setPos(0, 0);  // Posicionar la imagen en el origen de la escena
    scene->addItem(fondo);  // Agregar el fondo a la escena

    // Asignar la escena al QGraphicsView que definiste en el archivo .ui
    ui->graphicsView->setScene(scene);
    // Ajustar la vista al tamaño de la escena
    ui->graphicsView->setFixedSize(1000, 500);


}

MainWindow::~MainWindow()
{
    delete ui;
}
