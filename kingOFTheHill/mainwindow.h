#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene> // Paquete para control de escena
#include <QGraphicsView> // Paquete para vistas
#include <QPainter>
#include <QBrush>
#include <QTimer> // Para el temporizador

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
};
#endif // MAINWINDOW_H
