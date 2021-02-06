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

QList<string> MainWindow::disparos(double distancia, double alt_aliada, double altura_enemiga)
{
    QList<string> posibilidades;
    //_______________________________________________________________________________________
    double angulo_menor, angulo_mayor;
    double posy = alt_aliada;
    double vel_x = 0, vel_y = 0,tiempo = 0;
    string valor = "";
    if (alt_aliada >= altura_enemiga && distancia != 0){
        angulo_mayor = PI/4;
        angulo_menor = atan(-(alt_aliada-altura_enemiga)/distancia);
    }
    else if (alt_aliada < altura_enemiga){
        angulo_menor = atan((altura_enemiga-alt_aliada)/distancia);
        if (angulo_menor < PI/2 - (PI/180)*24){
            angulo_mayor = angulo_menor + (PI/180)*24;
        }
        else {angulo_mayor = PI/2;}
    }
    for (double e = angulo_mayor; e > angulo_menor; e -= PI /180){
        valor = "";
        for (float velocida = 1;;velocida+=1){
            posy = alt_aliada;
            vel_x = cos(e) * velocida;
            tiempo = distancia / vel_x;
            vel_y = sin(e)*velocida;
            posy = alt_aliada + (vel_y*tiempo)-((9.81*pow(tiempo,2))/2);
            if (posy >= altura_enemiga -(distancia*tipo) && posy < altura_enemiga +(distancia*tipo)){
                valor += to_string(vel_x);
                valor += " ";
                valor += to_string(vel_y);
                valor += " ";
                valor += to_string(tiempo);
                valor += "R";
                posibilidades.push_back(valor);
                break;
            }
        }
    }
    //---------------------------------------------------------------------------------------
    return posibilidades;
}

QList<string> MainWindow::contrataque(double ve_x, double ve_y, double dis, double pos_y_enemiga, double pos_y_propia, double retraso)
{
    QList<string> posibilidades;
    double posicion_enemiga = dis - (ve_x * retraso), pos_propia;
    double cambio;
    for (double tiempo = retraso;posicion_enemiga > (dis * tipo * 2);tiempo += 0.1){
        valor = "";
        for (float velocidad = 0.1;;velocidad += 0.1){
            pos_propia = velocidad * tiempo;
            if (posicion_enemiga - pos_propia < (distancia * tipo)){
                cambio = velocidad;
                break;
            }
        }
        if (tiempo > retraso){
            valor += to_string(cambio);
            valor += " ";
            posicion_enemiga = pos_y_enemiga + (ve_y*tiempo)-((9.81*pow(tiempo,2))/2);
            for (float velocidad = 0.1;;velocidad += 0.1){
                pos_propia = pos_y_propia + (velocidad*tiempo)-((9.81*pow(tiempo,2))/2);;
                if (posicion_enemiga - pos_propia <= (distancia * tipo)){
                    cambio = velocidad;
                    break;
                }
            }
            valor += to_string(cambio);
            valor += " ";
            valor += to_string(tiempo);
            valor += "R";
            posibilidades.push_back(valor);
        }
        posicion_enemiga = dis - (ve_x * (tiempo + 0.1));
    }
    return posibilidades;
}

void MainWindow::actualizar_central()
{
    time += 0.01;
    if (boton == 1){
        for (int i = 0; i < balas.size(); i++){
            bala *bal = balas[i];
            fisicas *fis = bal->getEsf();
            bal->tiempo_bala += 0.01;
            bal->rango += 1;
            bal->actualizar(bal->tiempo_bala,bal->vel_y);
            ocho.at(i)->actualizar(fis->PX,fis->PY);
            ui->tiempo->setText(QString::number(time));
            //----------------------------------------
            if (fis->PY <= 12){
                for (int a=0; a < bal->ubi.size();a++){scene->removeItem(bal->ubi[a]);}
                bal->ubi.clear();
                balas.removeAt(i);
                ocho.at(i);
            }
            //_________________________________________
            if (bal->rango == 10){//rango de imprecion de paso
                bal->ubi.push_back(new rastro());
                bal->ubi.back()->posicion(fis->PX,fis->PY);
                scene->addItem(bal->ubi.back());
                bal->rango = 0;
            }
        }
    }
    if (boton == 2){
        for (int i = 0; i < balas.size(); i++){
            bala *bal = balas[i];
            fisicas *fis = bal->getEsf();
            bal->tiempo_bala += 0.01;
            bal->rango += 1;
            bal->actualizar(bal->tiempo_bala,bal->vel_y);
            ocho.at(i)->actualizar(fis->PX,fis->PY);
            ui->tiempo->setText(QString::number(time));
            //----------------------------------------
            if (fis->PY <= 12){
                for (int a=0; a < bal->ubi.size();a++){scene->removeItem(bal->ubi[a]);}
                bal->ubi.clear();
                balas.removeAt(i);
                ocho.at(i);
            }
            //_________________________________________
            if (bal->rango == 10){//rango de imprecion de paso
                bal->ubi.push_back(new rastro());
                bal->ubi.back()->posicion(fis->PX,fis->PY);
                scene->addItem(bal->ubi.back());
                bal->rango = 0;
            }
            if (ocho.at(i)->collidesWithItem(ran_def) || ocho.at(i)->collidesWithItem(ran_ofe)){
                for (int a=0; a < bal->ubi.size();a++){scene->removeItem(bal->ubi[a]);}
                bal->ubi.clear();
                scene->removeItem(balas.at(i));
                balas.removeAt(i);
                scene->removeItem(ocho.at(i));
                ocho.at(i);
                val = "";
                val += "Enemigo abatido\nFELICITACIONES";
                QMessageBox::about (this,"Parcial Final", val);
            }
        }
    }
    if (boton == 3 && balas.size() > 0){
        if (time > espia ){
            for (int i = 0; i < balas.size(); i++){
                bala *bal = balas[i];
                fisicas *fis = bal->getEsf();
                bal->tiempo_bala += 0.01;
                bal->rango += 1;
                bal->actualizar(bal->tiempo_bala,bal->vel_y);
                ocho.at(i)->actualizar(fis->PX,fis->PY);
                ui->tiempo->setText(QString::number(time));
                //----------------------------------------
                if (fis->PY <= 12){
                    for (int a=0; a < bal->ubi.size();a++){scene->removeItem(bal->ubi[a]);}
                    bal->ubi.clear();
                    balas.removeAt(i);
                    ocho.at(i);
                }
                //_________________________________________
                if (bal->rango == 10){//rango de imprecion de paso
                    bal->ubi.push_back(new rastro());
                    bal->ubi.back()->posicion(fis->PX,fis->PY);
                    scene->addItem(bal->ubi.back());
                    bal->rango = 0;
                }
            }
            if (balas[0]->collidesWithItem(ran_def)){
                scene->removeItem(balas[0]);
                scene->removeItem(balas[1]);
                for (int a=0; a < balas.at(0)->ubi.size();a++){scene->removeItem(balas.at(0)->ubi[a]);}
                for (int a=0; a < balas.at(1)->ubi.size();a++){scene->removeItem(balas.at(1)->ubi[a]);}
                scene->removeItem(ocho[0]);
                scene->removeItem(ocho[1]);
                ocho.removeAt(1);
                ocho.removeAt(0);
                balas.removeAt(1);
                balas.removeAt(0);
                boton = 1;
                val = "";
                val += "La defensa del cañon fue imposible\nbajo los parametros dados";
                QMessageBox::about (this,"Parcial Final", val);
            }
            else if (balas[0]->collidesWithItem(balas[1])){
                scene->removeItem(balas[0]);
                scene->removeItem(balas[1]);
                for (int a=0; a < balas.at(0)->ubi.size();a++){scene->removeItem(balas.at(0)->ubi[a]);}
                for (int a=0; a < balas.at(1)->ubi.size();a++){scene->removeItem(balas.at(1)->ubi[a]);}
                scene->removeItem(ocho[0]);
                scene->removeItem(ocho[1]);
                ocho.removeAt(1);
                ocho.removeAt(0);
                balas.removeAt(1);
                balas.removeAt(0);
                boton = 2;
                val = "";
                val += "Bala del cannon ofensivo, neutralizada con exito.";
                QMessageBox::about (this,"Parcial Final", val);
            }
        }
        else {
            bala *bal = balas[0];
            fisicas *fis = bal->getEsf();
            bal->tiempo_bala += 0.01;
            bal->rango += 1;
            bal->actualizar(bal->tiempo_bala,bal->vel_y);
            ocho.at(0)->actualizar(fis->PX,fis->PY);
            ui->tiempo->setText(QString::number(time));
            //----------------------------------------
            if (fis->PY <= 12){
                for (int a=0; a < bal->ubi.size();a++){scene->removeItem(bal->ubi[a]);}
                bal->ubi.clear();
                balas.removeAt(0);
                ocho.at(0);
            }
            //_________________________________________
            if (bal->rango == 10){//rango de imprecion de paso
                bal->ubi.push_back(new rastro());
                bal->ubi.back()->posicion(fis->PX,fis->PY);
                scene->addItem(bal->ubi.back());
                bal->rango = 0;
            }
        }
    }
    if (boton == 4 && balas.size() > 0){
        if (time >= 3 ){
            for (int i = 0; i < balas.size(); i++){
                bala *bal = balas[i];
                fisicas *fis = bal->getEsf();
                bal->tiempo_bala += 0.01;
                bal->rango += 1;
                bal->actualizar(bal->tiempo_bala,bal->vel_y);
                ocho.at(i)->actualizar(fis->PX,fis->PY);
                ui->tiempo->setText(QString::number(time));
                //----------------------------------------
                if (fis->PY <= 12){
                    for (int a=0; a < bal->ubi.size();a++){scene->removeItem(bal->ubi[a]);}
                    bal->ubi.clear();
                    balas.removeAt(i);
                    ocho.at(i);
                }
                //_________________________________________
                if (bal->rango == 10){//rango de imprecion de paso
                    bal->ubi.push_back(new rastro());
                    bal->ubi.back()->posicion(fis->PX,fis->PY);
                    scene->addItem(bal->ubi.back());
                    bal->rango = 0;
                }
            }
            if (balas[0]->collidesWithItem(ran_def)){
                scene->removeItem(balas[0]);
                scene->removeItem(balas[1]);
                for (int a=0; a < balas.at(0)->ubi.size();a++){scene->removeItem(balas.at(0)->ubi[a]);}
                for (int a=0; a < balas.at(1)->ubi.size();a++){scene->removeItem(balas.at(1)->ubi[a]);}
                scene->removeItem(ocho[0]);
                scene->removeItem(ocho[1]);
                ocho.removeAt(1);
                ocho.removeAt(0);
                balas.removeAt(1);
                balas.removeAt(0);
                boton = 1;
                val = "";
                val += "Cañon defensivo derribado";
                QMessageBox::about (this,"Parcial Final", val);
            }
            else if (balas[0]->collidesWithItem(balas[1])){
                scene->removeItem(balas[0]);
                scene->removeItem(balas[1]);
                for (int a=0; a < balas.at(0)->ubi.size();a++){scene->removeItem(balas.at(0)->ubi[a]);}
                for (int a=0; a < balas.at(1)->ubi.size();a++){scene->removeItem(balas.at(1)->ubi[a]);}
                scene->removeItem(ocho[0]);
                scene->removeItem(ocho[1]);
                ocho.removeAt(1);
                ocho.removeAt(0);
                balas.removeAt(1);
                balas.removeAt(0);
                boton = 1;
                val = "";
                val += "Bala ofensiva fallida";
                QMessageBox::about (this,"Parcial Final", val);
            }
            else if (balas[1]->collidesWithItem(balas[2])){
                scene->removeItem(balas[2]);
                scene->removeItem(balas[1]);
                for (int a=0; a < balas.at(2)->ubi.size();a++){scene->removeItem(balas.at(2)->ubi[a]);}
                for (int a=0; a < balas.at(1)->ubi.size();a++){scene->removeItem(balas.at(1)->ubi[a]);}
                scene->removeItem(ocho[2]);
                scene->removeItem(ocho[1]);
                ocho.removeAt(2);
                ocho.removeAt(1);
                balas.removeAt(2);
                balas.removeAt(1);
                boton = 2;
                val = "";
                val += "Neutralizacion completa";
                QMessageBox::about (this,"Parcial Final", val);
            }
        }
        else if (time >= 2 ){
            for (int i = 0; i < 2; i++){
                bala *bal = balas[i];
                fisicas *fis = bal->getEsf();
                bal->tiempo_bala += 0.01;
                bal->rango += 1;
                bal->actualizar(bal->tiempo_bala,bal->vel_y);
                ocho.at(i)->actualizar(fis->PX,fis->PY);
                ui->tiempo->setText(QString::number(time));
                //----------------------------------------
                if (fis->PY <= 12){
                    for (int a=0; a < bal->ubi.size();a++){scene->removeItem(bal->ubi[a]);}
                    bal->ubi.clear();
                    balas.removeAt(i);
                    ocho.at(i);
                }
                //_________________________________________
                if (bal->rango == 10){//rango de imprecion de paso
                    bal->ubi.push_back(new rastro());
                    bal->ubi.back()->posicion(fis->PX,fis->PY);
                    scene->addItem(bal->ubi.back());
                    bal->rango = 0;
                }
            }
            if (balas[0]->collidesWithItem(ran_def)){
                scene->removeItem(balas[0]);
                scene->removeItem(balas[1]);
                for (int a=0; a < balas.at(0)->ubi.size();a++){scene->removeItem(balas.at(0)->ubi[a]);}
                for (int a=0; a < balas.at(1)->ubi.size();a++){scene->removeItem(balas.at(1)->ubi[a]);}
                scene->removeItem(ocho[0]);
                scene->removeItem(ocho[1]);
                ocho.removeAt(1);
                ocho.removeAt(0);
                balas.removeAt(1);
                balas.removeAt(0);
                boton = 1;
            }
            else if (balas[0]->collidesWithItem(balas[1])){
                scene->removeItem(balas[0]);
                scene->removeItem(balas[1]);
                for (int a=0; a < balas.at(0)->ubi.size();a++){scene->removeItem(balas.at(0)->ubi[a]);}
                for (int a=0; a < balas.at(1)->ubi.size();a++){scene->removeItem(balas.at(1)->ubi[a]);}
                scene->removeItem(ocho[0]);
                scene->removeItem(ocho[1]);
                ocho.removeAt(1);
                ocho.removeAt(0);
                balas.removeAt(1);
                balas.removeAt(0);
                boton = 1;
            }
        }
        else {
            bala *bal = balas[0];
            fisicas *fis = bal->getEsf();
            bal->tiempo_bala += 0.01;
            bal->rango += 1;
            bal->actualizar(bal->tiempo_bala,bal->vel_y);
            ocho.at(0)->actualizar(fis->PX,fis->PY);
            ui->tiempo->setText(QString::number(time));
            //----------------------------------------
            if (fis->PY <= 12){
                for (int a=0; a < bal->ubi.size();a++){scene->removeItem(bal->ubi[a]);}
                bal->ubi.clear();
                balas.removeAt(0);
                ocho.at(0);
            }
            //_________________________________________
            if (bal->rango == 10){//rango de imprecion de paso
                bal->ubi.push_back(new rastro());
                bal->ubi.back()->posicion(fis->PX,fis->PY);
                scene->addItem(bal->ubi.back());
                bal->rango = 0;
            }
        }
    }
    if (boton == 5 && balas.size() > 0){
        if (time >= 3 ){
            for (int i = 0; i < balas.size(); i++){
                bala *bal = balas[i];
                fisicas *fis = bal->getEsf();
                bal->tiempo_bala += 0.01;
                bal->rango += 1;
                bal->actualizar(bal->tiempo_bala,bal->vel_y);
                ocho.at(i)->actualizar(fis->PX,fis->PY);
                ui->tiempo->setText(QString::number(time));
                //----------------------------------------
                if (fis->PY <= 12){
                    for (int a=0; a < bal->ubi.size();a++){scene->removeItem(bal->ubi[a]);}
                    bal->ubi.clear();
                    balas.removeAt(i);
                    ocho.at(i);
                }
                //_________________________________________
                if (bal->rango == 10){//rango de imprecion de paso
                    bal->ubi.push_back(new rastro());
                    bal->ubi.back()->posicion(fis->PX,fis->PY);
                    scene->addItem(bal->ubi.back());
                    bal->rango = 0;
                }
            }
            if (balas[0]->collidesWithItem(ran_def)){
                scene->removeItem(balas[0]);
                scene->removeItem(balas[1]);
                for (int a=0; a < balas.at(0)->ubi.size();a++){scene->removeItem(balas.at(0)->ubi[a]);}
                for (int a=0; a < balas.at(1)->ubi.size();a++){scene->removeItem(balas.at(1)->ubi[a]);}
                scene->removeItem(ocho[0]);
                scene->removeItem(ocho[1]);
                ocho.removeAt(1);
                ocho.removeAt(0);
                balas.removeAt(1);
                balas.removeAt(0);
                boton = 1;
                val = "";
                val += "Cañon defensivo derribado";
                QMessageBox::about (this,"Parcial Final", val);
            }
            else if (balas[0]->collidesWithItem(balas[1])){
                scene->removeItem(balas[0]);
                scene->removeItem(balas[1]);
                for (int a=0; a < balas.at(0)->ubi.size();a++){scene->removeItem(balas.at(0)->ubi[a]);}
                for (int a=0; a < balas.at(1)->ubi.size();a++){scene->removeItem(balas.at(1)->ubi[a]);}
                scene->removeItem(ocho[0]);
                scene->removeItem(ocho[1]);
                ocho.removeAt(1);
                ocho.removeAt(0);
                balas.removeAt(1);
                balas.removeAt(0);
                boton = 1;
                val = "";
                val += "Bala ofensiva fallida";
                QMessageBox::about (this,"Parcial Final", val);
            }
            else if (balas[1]->collidesWithItem(balas[2])){
                scene->removeItem(balas[2]);
                scene->removeItem(balas[1]);
                for (int a=0; a < balas.at(2)->ubi.size();a++){scene->removeItem(balas.at(2)->ubi[a]);}
                for (int a=0; a < balas.at(1)->ubi.size();a++){scene->removeItem(balas.at(1)->ubi[a]);}
                scene->removeItem(ocho[2]);
                scene->removeItem(ocho[1]);
                ocho.removeAt(2);
                ocho.removeAt(1);
                balas.removeAt(2);
                balas.removeAt(1);
                boton = 2;
                val = "";
                val += "Neutralizacion completa";
                QMessageBox::about (this,"Parcial Final", val);
            }
        }
        else if (time >= 2 ){
            for (int i = 0; i < 2; i++){
                bala *bal = balas[i];
                fisicas *fis = bal->getEsf();
                bal->tiempo_bala += 0.01;
                bal->rango += 1;
                bal->actualizar(bal->tiempo_bala,bal->vel_y);
                ocho.at(i)->actualizar(fis->PX,fis->PY);
                ui->tiempo->setText(QString::number(time));
                //----------------------------------------
                if (fis->PY <= 12){
                    for (int a=0; a < bal->ubi.size();a++){scene->removeItem(bal->ubi[a]);}
                    bal->ubi.clear();
                    balas.removeAt(i);
                    ocho.at(i);
                }
                //_________________________________________
                if (bal->rango == 10){//rango de imprecion de paso
                    bal->ubi.push_back(new rastro());
                    bal->ubi.back()->posicion(fis->PX,fis->PY);
                    scene->addItem(bal->ubi.back());
                    bal->rango = 0;
                }
            }
            if (balas[0]->collidesWithItem(ran_def)){
                scene->removeItem(balas[0]);
                scene->removeItem(balas[1]);
                for (int a=0; a < balas.at(0)->ubi.size();a++){scene->removeItem(balas.at(0)->ubi[a]);}
                for (int a=0; a < balas.at(1)->ubi.size();a++){scene->removeItem(balas.at(1)->ubi[a]);}
                scene->removeItem(ocho[0]);
                scene->removeItem(ocho[1]);
                ocho.removeAt(1);
                ocho.removeAt(0);
                balas.removeAt(1);
                balas.removeAt(0);
                boton = 1;
            }
            else if (balas[0]->collidesWithItem(balas[1])){
                scene->removeItem(balas[0]);
                scene->removeItem(balas[1]);
                for (int a=0; a < balas.at(0)->ubi.size();a++){scene->removeItem(balas.at(0)->ubi[a]);}
                for (int a=0; a < balas.at(1)->ubi.size();a++){scene->removeItem(balas.at(1)->ubi[a]);}
                scene->removeItem(ocho[0]);
                scene->removeItem(ocho[1]);
                ocho.removeAt(1);
                ocho.removeAt(0);
                balas.removeAt(1);
                balas.removeAt(0);
                boton = 1;
            }
        }
        else {
            bala *bal = balas[0];
            fisicas *fis = bal->getEsf();
            bal->tiempo_bala += 0.01;
            bal->rango += 1;
            bal->actualizar(bal->tiempo_bala,bal->vel_y);
            ocho.at(0)->actualizar(fis->PX,fis->PY);
            ui->tiempo->setText(QString::number(time));
            //----------------------------------------
            if (fis->PY <= 12){
                for (int a=0; a < bal->ubi.size();a++){scene->removeItem(bal->ubi[a]);}
                bal->ubi.clear();
                balas.removeAt(0);
                ocho.at(0);
            }
            //_________________________________________
            if (bal->rango == 10){//rango de imprecion de paso
                bal->ubi.push_back(new rastro());
                bal->ubi.back()->posicion(fis->PX,fis->PY);
                scene->addItem(bal->ubi.back());
                bal->rango = 0;
            }
        }
    }
}


void MainWindow::on_lanzar_clicked()
{
    avanzar = true;
    if (suelo_def != nullptr && suelo_ofe != nullptr && can_ofe != nullptr && can_def != nullptr && ran_ofe != nullptr && ran_def != nullptr){
        scene->removeItem(suelo_def);
        scene->removeItem(suelo_ofe);
        scene->removeItem(can_ofe);
        scene->removeItem(can_def);
        scene->removeItem(ran_ofe);
        scene->removeItem(ran_def);
        suelo_def = nullptr;
        suelo_ofe = nullptr;
        can_ofe = nullptr;
        can_def = nullptr;
        ran_ofe = nullptr;
        ran_def = nullptr;
    }
    distancia = ui->distancia->value();//distancia de los cañones
    alt_ofe = ui->alt_ofe->value();//altura del cañon ofensivo
    alt_def = ui->alt_def->value();//altura del cañon defensivo
    //Creacion de la base ofensiva
    suelo_ofe = new base (2400 - distancia * 0.05 - (distancia/2),720 - alt_ofe,distancia*0.1,alt_ofe);
    can_ofe = new cannon (this);
    can_ofe->actualizar(suelo_ofe->x + suelo_ofe->w/2,720 - alt_ofe -28);
    scene->addItem(can_ofe);
    scene->addItem(suelo_ofe);
    //_____________________________________________________________
    ran_ofe = new ran_cannon (distancia*0.025);
    ran_ofe->posicion(suelo_ofe->x + suelo_ofe->w/2,720 - suelo_ofe->y);
    scene->addItem(ran_ofe);
    //Creacion de la base defensiva
    suelo_def = new base (2400 + (distancia/2) - distancia*0.05,720 - alt_def,distancia*0.1,alt_def);
    scene->addItem(suelo_def);
    can_def = new cannon_d (this);
    can_def->actualizar(suelo_def->x + suelo_def->w/2,720 - alt_def -28);
    scene->addItem(can_def);
    //_____________________________________________________________
    ran_def = new ran_cannon (distancia*0.05);
    ran_def->posicion(suelo_def->x + suelo_def->w/2,720 - suelo_def->y);
    scene->addItem(ran_def);
}

void MainWindow::on_defensivo_clicked()
{
    if (avanzar == true){
        //-----------------------------------------------------------------------------------------------
        boton = 1;
        tipo = 0.025;
        time = 0;
        radio = distancia * tipo;
        //________Calculo de disparo___________________________
        opciones = disparos(distancia,alt_def,alt_ofe);
        if (opciones.size() > 0){
            for (int o = 0; o < opciones.size(); o++){
                valor = opciones.at(o);
                velocidad_x = stod(valor.substr(0,valor.find(' ')));
                valor = valor.substr(valor.find(' ')+1,valor.find('R'));
                velocidad_y = stod(valor.substr(0,valor.find(' ')));
                //-----------------------------------------------------
                balas.push_back(new bala(suelo_def->x + suelo_def->w/2,720 - suelo_def->y,radio));
                balas.back()->color = 3;
                scene->addItem(balas.back());
                balas.back()->ingreso(velocidad_x*(-1),velocidad_y);//Aqui ingreso una velocidad en X y una velocidad en Y
                timer->start(ui->crono->value());
                ui->tiempo->setText(QString::number(time));
                //---------------------------------------------------
                ocho.push_back(new bullet(this));
                ocho.back()->actualizar(balas.back()->getEsf()->PX,balas.back()->getEsf()->PY);
                scene->addItem(ocho.back());
                //---------------------------------------------------
                //-----------------------------------------------------------------------------------------------
            }
        }
        else{
            val = "";
            val += "No existen ningun disparo posible\na ejecutar en la scena.";
            QMessageBox::about (this,"Parcial Final", val);
        }
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
        boton = 1;
        tipo = 0.05;
        time = 0;
        radio = distancia * tipo;
        //________Calculo de disparo___________________________
        opciones = disparos(distancia,alt_ofe,alt_def);
        if (opciones.size() > 0){
            for (int o = 0; o < opciones.size(); o++){
                valor = opciones.at(o);
                velocidad_x = stod(valor.substr(0,valor.find(' ')));
                valor = valor.substr(valor.find(' ')+1,valor.find('R'));
                velocidad_y = stod(valor.substr(0,valor.find(' ')));
                //-----------------------------------------------------
                balas.push_back(new bala(suelo_ofe->x + suelo_ofe->w/2,720 - suelo_ofe->y,radio));
                balas.back()->color = 2;
                scene->addItem(balas.back());
                balas.back()->ingreso(velocidad_x*(1),velocidad_y);//Aqui ingreso una velocidad en X y una velocidad en Y
                timer->start(ui->crono->value());
                ui->tiempo->setText(QString::number(time));
                //---------------------------------------------------
                ocho.push_back(new bullet(this));
                ocho.back()->actualizar(balas.back()->getEsf()->PX,balas.back()->getEsf()->PY);
                scene->addItem(ocho.back());
                //---------------------------------------------------
                //-----------------------------------------------------------------------------------------------
            }
        }
        else{
            val = "";
            val += "No existen ningun disparo posible\na ejecutar en la scena.";
            QMessageBox::about (this,"Parcial Final", val);
        }
    }
    else if (avanzar == false){
        val = "";
        val += "La scena todavia no ha sido lanzada\nlance primero la scena.";
        QMessageBox::about (this,"Parcial Final", val);
    }
}

void MainWindow::on_simple_clicked()
{
    if (avanzar == true){
        //-----------------------------------------------------------------------------------------------
        boton = 3;
        tipo = 0.05;
        time = 0;
        radio = distancia * tipo;
        //________Calculo de disparo___________________________
        opciones = disparos(distancia,alt_ofe,alt_def);
        if (opciones.size() > 0){
            valor = opciones.at((opciones.size())/2);
            velocidad_x = stod(valor.substr(0,valor.find(' ')));
            valor = valor.substr(valor.find(' ')+1,valor.find('R'));
            velocidad_y = stod(valor.substr(0,valor.find(' ')));
            //-----------------------------------------------------
            balas.push_back(new bala(suelo_ofe->x + suelo_ofe->w/2,720 - suelo_ofe->y,radio));
            balas.back()->color = 2;
            scene->addItem(balas.back());
            balas.back()->ingreso(velocidad_x*(1),velocidad_y);//Aqui ingreso una velocidad en X y una velocidad en Y
            timer->start(ui->crono->value());
            ui->tiempo->setText(QString::number(time));
            //---------------------------------------------------
            ocho.push_back(new bullet(this));
            ocho.back()->actualizar(balas.back()->getEsf()->PX,balas.back()->getEsf()->PY);
            scene->addItem(ocho.back());
            //-----------------------------------------------Calculo de respuesta----
            tipo = 0.025;
            radio = distancia * tipo;
            opciones.clear();
            //_______________________________Calculo con el retraso_________________
            espia = 2; //Tiempo de retraso
            altura_diparo = alt_ofe + (velocidad_y*espia)-((9.81*pow(time,2))/2);;
            velocidad_y -= (9.81*espia);; //Ecuacion de la velocidad en un determinado tiempo
            distancia_dis = distancia - (velocidad_x*espia); //distanacia al tiempo espia
            //______________________________________________________________________
            opciones = contrataque(velocidad_x,velocidad_y,distancia_dis,altura_diparo,alt_def,espia);
            if (opciones.size() > 0){
                valor = opciones.at(opciones.size() * 0.1);
                velocidad_x = stod(valor.substr(0,valor.find(' ')));
                valor = valor.substr(valor.find(' ')+1,valor.find('R'));
                velocidad_y = stod(valor.substr(0,valor.find(' ')));
                //-----------------------------------------------------
                balas.push_back(new bala(suelo_def->x + suelo_def->w/2,720 - suelo_def->y,radio));
                balas.back()->color = 3;
                balas.back()->setPos(suelo_def->x + suelo_def->w/2,720 - suelo_def->h);
                scene->addItem(balas.back());
                balas.back()->ingreso(velocidad_x*(-1),velocidad_y);//Aqui ingreso una velocidad en X y una velocidad en Y
                timer->start(ui->crono->value());
                ui->tiempo->setText(QString::number(time));
                //---------------------------------------------------
                ocho.push_back(new bullet(this));
                ocho.back()->actualizar(balas.back()->getEsf()->PX,balas.back()->getEsf()->PY);
                scene->addItem(ocho.back());
                //---------------------------------------------------
            }
            //-----------------------------------------------------------------------------------------------
        }
        else{
            val = "";
            val += "No existen ningun disparo posible\na ejecutar en la scena.";
            QMessageBox::about (this,"Parcial Final", val);
        }
    }
    else if (avanzar == false){
        val = "";
        val += "La scena todavia no ha sido lanzada\nlance primero la scena.";
        QMessageBox::about (this,"Parcial Final", val);
    }
}

void MainWindow::on_contrataque_clicked()
{
    if (avanzar == true){
        //-----------------------------------------------------------------------------------------------
        boton = 3;
        tipo = 0.05;
        time = 0;
        radio = distancia * tipo;
        //________Calculo de disparo___________________________
        opciones.clear();
        opciones = disparos(distancia,alt_ofe,alt_def);
        if (opciones.size() > 0){
            valor = opciones.at((opciones.size())/2);
            velocidad_x = stod(valor.substr(0,valor.find(' ')));
            valor = valor.substr(valor.find(' ')+1,valor.find('R'));
            velocidad_y = stod(valor.substr(0,valor.find(' ')));
            //-----------------------------------------------------
            balas.push_back(new bala(suelo_ofe->x + suelo_ofe->w/2,720 - suelo_ofe->y,radio));
            balas.back()->color = 2;
            scene->addItem(balas.back());
            balas.back()->ingreso(velocidad_x*(1),velocidad_y);//Aqui ingreso una velocidad en X y una velocidad en Y
            timer->start(ui->crono->value());
            ui->tiempo->setText(QString::number(time));
            //---------------------------------------------------
            ocho.push_back(new bullet(this));
            ocho.back()->actualizar(balas.back()->getEsf()->PX,balas.back()->getEsf()->PY);
            scene->addItem(ocho.back());
            //-----------------------------------------------Calculo de respuesta----
            tipo = 0.025;
            radio = distancia * tipo;
            opciones.clear();
            //_______________________________Calculo con el retraso_________________
            espia = 2; //Tiempo de retraso
            altura_diparo = alt_ofe + (velocidad_y*espia)-((9.81*pow(espia,2))/2);;
            velocidad_y -= (9.81*espia);; //Ecuacion de la velocidad en un determinado tiempo
            distancia_dis = distancia - (velocidad_x*espia); //distanacia al tiempo espia
            //______________________________________________________________________
            opciones = contrataque(velocidad_x,velocidad_y,distancia_dis,altura_diparo,alt_def,espia);
            if (opciones.size() > 0){
                valor = opciones.at(opciones.size() * 0.1);
                velocidad_x = stod(valor.substr(0,valor.find(' ')));
                valor = valor.substr(valor.find(' ')+1,valor.find('R'));
                velocidad_y = stod(valor.substr(0,valor.find(' ')));
                //-----------------------------------------------------
                balas.push_back(new bala(suelo_def->x + suelo_def->w/2,720 - suelo_def->y,radio));
                balas.back()->color = 3;
                balas.back()->setPos(suelo_def->x + suelo_def->w/2,720 - suelo_def->h);
                scene->addItem(balas.back());
                balas.back()->ingreso(velocidad_x*(-1),velocidad_y);//Aqui ingreso una velocidad en X y una velocidad en Y
                timer->start(ui->crono->value());
                ui->tiempo->setText(QString::number(time));
                //---------------------------------------------------
                ocho.push_back(new bullet(this));
                ocho.back()->actualizar(balas.back()->getEsf()->PX,balas.back()->getEsf()->PY);
                scene->addItem(ocho.back());
                //---------------------------------------------------
            }
            opciones.clear();
            opciones = disparos(distancia,alt_def,alt_ofe);
            if (opciones.size() > 0){
                valor = opciones.at((opciones.size())*0.2);
                velocidad_x = stod(valor.substr(0,valor.find(' ')));
                valor = valor.substr(valor.find(' ')+1,valor.find('R'));
                velocidad_y = stod(valor.substr(0,valor.find(' ')));
                //-----------------------------------------------------
                balas.push_back(new bala(suelo_def->x + suelo_def->w/2,720 - suelo_def->y,radio));
                balas.back()->color = 3;
                balas.back()->setPos(suelo_def->x + suelo_def->w/2,720 - suelo_def->h);
                scene->addItem(balas.back());
                balas.back()->ingreso(velocidad_x*(-1),velocidad_y);//Aqui ingreso una velocidad en X y una velocidad en Y
                timer->start(ui->crono->value());
                ui->tiempo->setText(QString::number(time));
                //---------------------------------------------------
                ocho.push_back(new bullet(this));
                ocho.back()->actualizar(balas.back()->getEsf()->PX,balas.back()->getEsf()->PY);
                scene->addItem(ocho.back());
                //__________________________________________________________________________________
                //______________________Dos disparos________________________________________________
                valor = opciones.at((opciones.size())*0.8);
                velocidad_x = stod(valor.substr(0,valor.find(' ')));
                valor = valor.substr(valor.find(' ')+1,valor.find('R'));
                velocidad_y = stod(valor.substr(0,valor.find(' ')));
                //-----------------------------------------------------
                balas.push_back(new bala(suelo_def->x + suelo_def->w/2,720 - suelo_def->y,radio));
                balas.back()->color = 3;
                balas.back()->setPos(suelo_def->x + suelo_def->w/2,720 - suelo_def->h);
                scene->addItem(balas.back());
                balas.back()->ingreso(velocidad_x*(-1),velocidad_y);//Aqui ingreso una velocidad en X y una velocidad en Y
                timer->start(ui->crono->value());
                ui->tiempo->setText(QString::number(time));
                //---------------------------------------------------
                ocho.push_back(new bullet(this));
                ocho.back()->actualizar(balas.back()->getEsf()->PX,balas.back()->getEsf()->PY);
                scene->addItem(ocho.back());
                //__________________________________________________________________________________
            }
            //-----------------------------------------------------------------------------------------------
        }
        else{
            val = "";
            val += "No existen ningun disparo posible\na ejecutar en la scena.";
            QMessageBox::about (this,"Parcial Final", val);
        }
    }
    else if (avanzar == false){
        val = "";
        val += "La scena todavia no ha sido lanzada\nlance primero la scena.";
        QMessageBox::about (this,"Parcial Final", val);
    }
}

void MainWindow::on_neutralizar_clicked()
{
    if (avanzar == true){
        //-----------------------------------------------------------------------------------------------
        boton = 4;
        time = 0;
        tipo = 0.05;
        radio = distancia * tipo;
        //________Calculo de disparo___________________________
        opciones = disparos(distancia,alt_ofe,alt_def);
        if (opciones.size() > 0){
            valor = opciones.at((opciones.size())/2);
            velocidad_x = stod(valor.substr(0,valor.find(' ')));
            valor = valor.substr(valor.find(' ')+1,valor.find('R'));
            velocidad_y = stod(valor.substr(0,valor.find(' ')));
            //-----------------------------------------------------
            balas.push_back(new bala(suelo_ofe->x + suelo_ofe->w/2,720 - suelo_ofe->y,radio));
            balas.back()->color = 2;
            scene->addItem(balas.back());
            balas.back()->ingreso(velocidad_x*(1),velocidad_y);//Aqui ingreso una velocidad en X y una velocidad en Y
            timer->start(ui->crono->value());
            ui->tiempo->setText(QString::number(time));
            //---------------------------------------------------
            ocho.push_back(new bullet(this));
            ocho.back()->actualizar(balas.back()->getEsf()->PX,balas.back()->getEsf()->PY);
            scene->addItem(ocho.back());
            //-----------------------------------------------Calculo de respuesta----
            tipo = 0.025;
            radio = distancia * tipo;
            opciones.clear();
            //_______________________________Calculo con el retraso_________________
            espia = 2; //Tiempo de retraso
            altura_diparo = alt_ofe + (velocidad_y*espia)-((9.81*pow(espia,2))/2);;
            velocidad_y -= (9.81*espia);; //Ecuacion de la velocidad en un determinado tiempo
            distancia_dis = distancia - (velocidad_x*espia); //distanacia al tiempo espia
            //______________________________________________________________________
            opciones = contrataque(velocidad_x,velocidad_y,distancia_dis,altura_diparo,alt_def,espia);
            if (opciones.size() > 0){
                valor = opciones.at(opciones.size() * 0.1);
                velocidad_x = stod(valor.substr(0,valor.find(' ')));
                valor = valor.substr(valor.find(' ')+1,valor.find('R'));
                velocidad_y = stod(valor.substr(0,valor.find(' ')));
                //-----------------------------------------------------
                balas.push_back(new bala(suelo_def->x + suelo_def->w/2,720 - suelo_def->y,radio));
                balas.back()->color = 3;
                balas.back()->setPos(suelo_def->x + suelo_def->w/2,720 - suelo_def->h);
                scene->addItem(balas.back());
                balas.back()->ingreso(velocidad_x*(-1),velocidad_y);//Aqui ingreso una velocidad en X y una velocidad en Y
                timer->start(ui->crono->value());
                ui->tiempo->setText(QString::number(time));
                //---------------------------------------------------
                ocho.push_back(new bullet(this));
                ocho.back()->actualizar(balas.back()->getEsf()->PX,balas.back()->getEsf()->PY);
                scene->addItem(ocho.back());
                //---------------------------------------------------
            }
            //-----------------------------------------------Calculo de respuesta _NEURALIZADOR_----
            tipo = 0.005;
            radio = distancia * tipo;
            opciones.clear();
            //_______________________________Calculo con el retraso_________________
            espia = 1; //Tiempo de retraso
            altura_diparo = alt_def + (velocidad_y*espia)-((9.81*pow(espia,2))/2);;
            velocidad_y -= (9.81*espia);; //Ecuacion de la velocidad en un determinado tiempo
            distancia_dis = distancia - (velocidad_x*espia); //distanacia al tiempo espia
            //______________________________________________________________________
            opciones = contrataque(velocidad_x,velocidad_y,distancia_dis,altura_diparo,alt_def,espia);
            if (opciones.size() > 0){
                valor = opciones.at(opciones.size() * 0.1);
                velocidad_x = stod(valor.substr(0,valor.find(' ')));
                valor = valor.substr(valor.find(' ')+1,valor.find('R'));
                velocidad_y = stod(valor.substr(0,valor.find(' ')));
                //-----------------------------------------------------
                balas.push_back(new bala(suelo_ofe->x + suelo_ofe->w/2,720 - suelo_ofe->y,radio));
                balas.back()->color = 1;
                balas.back()->setPos(suelo_ofe->x + suelo_ofe->w/2,720 - suelo_ofe->h);
                scene->addItem(balas.back());
                balas.back()->ingreso(velocidad_x*(1),velocidad_y);//Aqui ingreso una velocidad en X y una velocidad en Y
                timer->start(ui->crono->value());
                ui->tiempo->setText(QString::number(time));
                //---------------------------------------------------
                ocho.push_back(new bullet(this));
                ocho.back()->actualizar(balas.back()->getEsf()->PX,balas.back()->getEsf()->PY);
                scene->addItem(ocho.back());
                //---------------------------------------------------
            }
            //-----------------------------------------------------------------------------------------------
        }
        else{
            val = "";
            val += "No existen ningun disparo posible\na ejecutar en la scena.";
            QMessageBox::about (this,"Parcial Final", val);
        }
    }
    else if (avanzar == false){
        val = "";
        val += "La scena todavia no ha sido lanzada\nlance primero la scena.";
        QMessageBox::about (this,"Parcial Final", val);
    }
}

void MainWindow::on_simulacion_clicked()
{
    if (avanzar == true){
        //-----------------------------------------------------------------------------------------------
        boton = 5;
        time = 0;
        tipo = 0.05;
        radio = distancia * tipo;
        //________Calculo de disparo___________________________
        opciones = disparos(distancia,alt_ofe,alt_def);
        if (opciones.size() > 0){
            valor = opciones.at((opciones.size())/2);
            velocidad_x = stod(valor.substr(0,valor.find(' ')));
            valor = valor.substr(valor.find(' ')+1,valor.find('R'));
            velocidad_y = stod(valor.substr(0,valor.find(' ')));
            //-----------------------------------------------------
            balas.push_back(new bala(suelo_ofe->x + suelo_ofe->w/2,720 - suelo_ofe->y,radio));
            balas.back()->color = 2;
            scene->addItem(balas.back());
            balas.back()->ingreso(velocidad_x*(1),velocidad_y);//Aqui ingreso una velocidad en X y una velocidad en Y
            timer->start(ui->crono->value());
            ui->tiempo->setText(QString::number(time));
            //---------------------------------------------------
            ocho.push_back(new bullet(this));
            ocho.back()->actualizar(balas.back()->getEsf()->PX,balas.back()->getEsf()->PY);
            scene->addItem(ocho.back());
            //-----------------------------------------------Calculo de respuesta----
            tipo = 0.025;
            radio = distancia * tipo;
            opciones.clear();
            //_______________________________Calculo con el retraso_________________
            espia = 2; //Tiempo de retraso
            altura_diparo = alt_ofe + (velocidad_y*espia)-((9.81*pow(espia,2))/2);;
            velocidad_y -= (9.81*espia);; //Ecuacion de la velocidad en un determinado tiempo
            distancia_dis = distancia - (velocidad_x*espia); //distanacia al tiempo espia
            //______________________________________________________________________
            opciones = contrataque(velocidad_x,velocidad_y,distancia_dis,altura_diparo,alt_def,espia);
            if (opciones.size() > 0){
                valor = opciones.at(opciones.size() * 0.1);
                velocidad_x = stod(valor.substr(0,valor.find(' ')));
                valor = valor.substr(valor.find(' ')+1,valor.find('R'));
                velocidad_y = stod(valor.substr(0,valor.find(' ')));
                //-----------------------------------------------------
                balas.push_back(new bala(suelo_def->x + suelo_def->w/2,720 - suelo_def->y,radio));
                balas.back()->color = 2;
                balas.back()->setPos(suelo_def->x + suelo_def->w/2,720 - suelo_def->h);
                scene->addItem(balas.back());
                balas.back()->ingreso(velocidad_x*(-1),velocidad_y);//Aqui ingreso una velocidad en X y una velocidad en Y
                timer->start(ui->crono->value());
                ui->tiempo->setText(QString::number(time));
                //---------------------------------------------------
                ocho.push_back(new bullet(this));
                ocho.back()->actualizar(balas.back()->getEsf()->PX,balas.back()->getEsf()->PY);
                scene->addItem(ocho.back());
                //---------------------------------------------------
            }
            //-----------------------------------------------Calculo de respuesta _NEURALIZADOR_----
            tipo = 0.005;
            radio = distancia * tipo;
            opciones.clear();
            //_______________________________Calculo con el retraso_________________
            espia = 1; //Tiempo de retraso
            altura_diparo = alt_def + (velocidad_y*espia)-((9.81*pow(espia,2))/2);;
            velocidad_y -= (9.81*espia);; //Ecuacion de la velocidad en un determinado tiempo
            distancia_dis = distancia - (velocidad_x*espia); //distanacia al tiempo espia
            //______________________________________________________________________
            opciones = contrataque(velocidad_x,velocidad_y,distancia_dis,altura_diparo,alt_def,espia);
            if (opciones.size() > 0){
                valor = opciones.at(opciones.size() * 0.1);
                velocidad_x = stod(valor.substr(0,valor.find(' ')));
                valor = valor.substr(valor.find(' ')+1,valor.find('R'));
                velocidad_y = stod(valor.substr(0,valor.find(' ')));
                //-----------------------------------------------------
                balas.push_back(new bala(suelo_ofe->x + suelo_ofe->w/2,720 - suelo_ofe->y,radio));
                balas.back()->color = 2;
                balas.back()->setPos(suelo_ofe->x + suelo_ofe->w/2,720 - suelo_ofe->h);
                scene->addItem(balas.back());
                balas.back()->ingreso(velocidad_x*(1),velocidad_y);//Aqui ingreso una velocidad en X y una velocidad en Y
                timer->start(ui->crono->value());
                ui->tiempo->setText(QString::number(time));
                //---------------------------------------------------
                ocho.push_back(new bullet(this));
                ocho.back()->actualizar(balas.back()->getEsf()->PX,balas.back()->getEsf()->PY);
                scene->addItem(ocho.back());
                //---------------------------------------------------
            }
            //-----------------------------------------------------------------------------------------------
        }
        else{
            val = "";
            val += "No existen ningun disparo posible\na ejecutar en la scena.";
            QMessageBox::about (this,"Parcial Final", val);
        }
    }
    else if (avanzar == false){
        val = "";
        val += "La scena todavia no ha sido lanzada\nlance primero la scena.";
        QMessageBox::about (this,"Parcial Final", val);
    }
}

void MainWindow::on_actionPausa_triggered()
{
    if (timer->isActive()){
        timer->stop();
    }
    else {
        timer->start(ui->crono->value());
    }
}

void MainWindow::on_pushButton_clicked()
{
    if (avanzar == true){
        boton = 1;
        //-----------------------------------------------------------------------------------------------
        velocidad_x = cos((ui->ang->value()*PI)/180) * ui->vel->value();
        velocidad_y = sin((ui->ang->value()*PI)/180) * ui->vel->value();
        if (ui->man_ofe->isChecked()){
            tipo = 0.05;
            time = 0;
            radio = distancia * tipo;
            balas.push_back(new bala(suelo_ofe->x + suelo_ofe->w/2,720 - suelo_ofe->y,radio));
            balas.back()->color = 2;
            scene->addItem(balas.back());
            balas.back()->ingreso(velocidad_x*(1),velocidad_y);//Aqui ingreso una velocidad en X y una velocidad en Y
            timer->start(ui->crono->value());
            ui->tiempo->setText(QString::number(time));
            //---------------------------------------------------
            ocho.push_back(new bullet(this));
            ocho.back()->actualizar(balas.back()->getEsf()->PX,balas.back()->getEsf()->PY);
            scene->addItem(ocho.back());
        }
        else if (ui->man_def->isChecked()){
            tipo = 0.025;
            time = 0;
            radio = distancia * tipo;
            balas.push_back(new bala(suelo_def->x + suelo_def->w/2,720 - suelo_def->y,radio));
            balas.back()->color = 3;
            scene->addItem(balas.back());
            balas.back()->ingreso(velocidad_x*(-1),velocidad_y);//Aqui ingreso una velocidad en X y una velocidad en Y
            timer->start(ui->crono->value());
            ui->tiempo->setText(QString::number(time));
            //---------------------------------------------------
            ocho.push_back(new bullet(this));
            ocho.back()->actualizar(balas.back()->getEsf()->PX,balas.back()->getEsf()->PY);
            scene->addItem(ocho.back());
        }
        else {
            val = "";
            val += "Seleccione desde cual de los dos cañones quiere disparar";
            QMessageBox::about (this,"Parcial Final", val);
        }
        //-----------------------------------------------------------------------------------------------
    }
    else if (avanzar == false){
        val = "";
        val += "La scena todavia no ha sido lanzada\nlance primero la scena.";
        QMessageBox::about (this,"Parcial Final", val);
    }
}
