#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//_________________________________________
#include <QGraphicsScene>
#include <QMessageBox>
#include <QTimer>
#include <math.h>
#include <QList>
//_________________________________________
using namespace std;
#include "base.h"
#include "bala.h"
#include "cannon.h"
#include "cannon_d.h"
#include "bullet.h"
#include "rastro.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //___________________Creacion de scena
    QGraphicsScene *scene;
    QTimer *timer;
    //______________________Variables_____
    bool avanzar =  false;
    QString val = "";
    base *suelo_ofe = nullptr;
    base *suelo_def = nullptr;
    cannon *can_ofe= nullptr;
    cannon_d *can_def= nullptr;
    QList<bala*> balas;
    QList<bullet*> ocho;
    QList<rastro*> ubi;
    double distancia = 0,alt_ofe=0,alt_def=0,time=0,radio = 0;
    float tipo = 0;

public slots:
    void actualizar_central();

private slots:
    void on_lanzar_clicked();

    void on_defensivo_clicked();

    void on_ofensivo_clicked();

    void on_simple_clicked();

    void on_contrataque_clicked();

    void on_neutralizar_clicked();

    void on_simulacion_clicked();
    void on_actionPausa_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
