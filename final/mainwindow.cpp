#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,4800,720);
    ui->graphicsView->setScene(scene);
    scene->setBackgroundBrush(QPixmap(":/pictures/desert-1170055.jpg"));
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar_central()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::actualizar_central()
{
    time += 0.01;
    for (int i = 0; i < balas.size(); i++){

        bala *bal = balas[i];
        fisicas *fis = bal->getEsf();

        tiempo_bala[i]+= 0.01;
        bal->actualizar(tiempo_bala[i],bal->ini_x,bal->ini_y,bal->vel_y);
        ui->tiempo->setText(QString::number(time));

        //----------------------------------------
        if (fis->PY <= radio){
            balas.removeAt(i);
            tiempo_bala.removeAt(i);
        }
    }
}


void MainWindow::on_lanzar_clicked()
{
    avanzar = true;
    if (suelo_def != nullptr && suelo_ofe != nullptr){
        scene->removeItem(suelo_def);
        scene->removeItem(suelo_ofe);
        suelo_def = nullptr;
        suelo_ofe = nullptr;
    }
    distancia = ui->distancia->value();//distancia de los cañones
    alt_ofe = ui->alt_ofe->value();//altura del cañon ofensivo
    alt_def = ui->alt_def->value();//altura del cañon defensivo
    //Creacion de la base ofensiva
    suelo_ofe = new base (2400 - distancia * 0.01 - (distancia/2),720 - alt_ofe,distancia*0.1,alt_ofe);
    scene->addItem(suelo_ofe);
    //Creacion de la base defensiva
    suelo_def = new base (2400 + (distancia/2) - distancia*0.1,720 - alt_def,distancia*0.1,alt_def);
    scene->addItem(suelo_def);
}

void MainWindow::on_defensivo_clicked()
{
    if (avanzar == true){
        //-----------------------------------------------------------------------------------------------
        tipo = 0.025;
        time = 0;
        radio = distancia * tipo;
        balas.push_back(new bala(suelo_def->x + suelo_def->w/2,720 - suelo_def->y,radio));
        tiempo_bala.push_back(0);
        scene->addItem(balas.back());
        balas.back()->ingreso(6*(-1),8);//Aqui ingreso una velocidad en X y una velocidad en Y
        timer->start(ui->crono->value());
        ui->tiempo->setText(QString::number(time));
        //-----------------------------------------------------------------------------------------------
    }
    else if (avanzar == false){
        val = "";
        val += "La scena todavia no ha sido lanzada\nlance primero la scena.";
        QMessageBox::about (this,"Parcial Final", val);
    }
}

void MainWindow::on_ofensivo_clicked()
{
    if (avanzar == true){
        tipo = 0.05;
        time = 0;
        radio = distancia * tipo;
        balas.push_back(new bala(suelo_ofe->x + suelo_ofe->w/2,720 - suelo_ofe->y,radio));
        tiempo_bala.push_back(0);
        scene->addItem(balas.back());
        balas.back()->ingreso(6*(1),8);//Aqui ingreso una velocidad en X y una velocidad en Y
        timer->start(ui->crono->value());
        ui->tiempo->setText(QString::number(time));
        //-----------------------------------------------------------------------------------------------
    }
    else if (avanzar == false){
        val = "";
        val += "La scena todavia no ha sido lanzada\nlance primero la scena.";
        QMessageBox::about (this,"Parcial Final", val);
    }
}

void MainWindow::on_simple_clicked()
{
    if (avanzar == true){}
    else if (avanzar == false){
        val = "";
        val += "La scena todavia no ha sido lanzada\nlance primero la scena.";
        QMessageBox::about (this,"Parcial Final", val);
    }
}

void MainWindow::on_contrataque_clicked()
{
    if (avanzar == true){}
    else if (avanzar == false){
        val = "";
        val += "La scena todavia no ha sido lanzada\nlance primero la scena.";
        QMessageBox::about (this,"Parcial Final", val);
    }
}

void MainWindow::on_neutralizar_clicked()
{
    if (avanzar == true){}
    else if (avanzar == false){
        val = "";
        val += "La scena todavia no ha sido lanzada\nlance primero la scena.";
        QMessageBox::about (this,"Parcial Final", val);
    }
}

void MainWindow::on_simulacion_clicked()
{
    if (avanzar == true){}
    else if (avanzar == false){
        val = "";
        val += "La scena todavia no ha sido lanzada\nlance primero la scena.";
        QMessageBox::about (this,"Parcial Final", val);
    }
}
