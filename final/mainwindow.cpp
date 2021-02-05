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
    intento->actualizar();
    time += 0.04;
    ui->tiempo->setText(QString::number(time));
    if (intento->getEsf()->PY - radio <= 1){
        intento->getEsf()->set_vel(intento->getEsf()->e*intento->getEsf()->VX,-1*intento->getEsf()->e*intento->getEsf()->VY,intento->getEsf()->PX,intento->getEsf()->PY + 0.04);
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
        tipo = 0.05;
        radio = distancia * tipo;
        intento = new bala(suelo_def->x + suelo_def->w/2,720 - suelo_def->y + radio,radio);
        intento->actualizar();
        scene->addItem(intento);
        intento->getEsf()->set_vel(-80,50,intento->getEsf()->PX,intento->getEsf()->PY);
        timer->start(40);
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
    if (avanzar == true){}
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
