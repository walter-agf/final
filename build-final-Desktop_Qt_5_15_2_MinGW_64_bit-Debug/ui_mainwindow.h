/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QDoubleSpinBox *distancia;
    QLabel *label_2;
    QDoubleSpinBox *alt_def;
    QLabel *label_3;
    QDoubleSpinBox *alt_ofe;
    QLabel *label_4;
    QLabel *tiempo;
    QPushButton *lanzar;
    QSplitter *splitter;
    QPushButton *defensivo;
    QPushButton *ofensivo;
    QPushButton *simple;
    QPushButton *contrataque;
    QPushButton *neutralizar;
    QPushButton *simulacion;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1600, 750);
        MainWindow->setMaximumSize(QSize(1600, 750));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pictures/canon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setIconSize(QSize(48, 48));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 1282, 722));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(1300, 20, 291, 289));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Verdana"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout->addWidget(label);

        distancia = new QDoubleSpinBox(widget);
        distancia->setObjectName(QString::fromUtf8("distancia"));
        distancia->setMaximum(1000000000000000044885712678075916785549312.000000000000000);

        verticalLayout->addWidget(distancia);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        alt_def = new QDoubleSpinBox(widget);
        alt_def->setObjectName(QString::fromUtf8("alt_def"));
        alt_def->setMaximum(1000000000000000042420637374017961984.000000000000000);

        verticalLayout->addWidget(alt_def);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        verticalLayout->addWidget(label_3);

        alt_ofe = new QDoubleSpinBox(widget);
        alt_ofe->setObjectName(QString::fromUtf8("alt_ofe"));
        alt_ofe->setMaximum(9999999999999999438119489974413630815797154428513196965888.000000000000000);

        verticalLayout->addWidget(alt_ofe);


        verticalLayout_2->addLayout(verticalLayout);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        verticalLayout_2->addWidget(label_4);

        tiempo = new QLabel(widget);
        tiempo->setObjectName(QString::fromUtf8("tiempo"));
        tiempo->setFont(font);

        verticalLayout_2->addWidget(tiempo);

        lanzar = new QPushButton(widget);
        lanzar->setObjectName(QString::fromUtf8("lanzar"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Verdana"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        lanzar->setFont(font1);

        verticalLayout_2->addWidget(lanzar);

        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(1301, 320, 291, 391));
        splitter->setOrientation(Qt::Vertical);
        defensivo = new QPushButton(splitter);
        defensivo->setObjectName(QString::fromUtf8("defensivo"));
        defensivo->setFont(font1);
        splitter->addWidget(defensivo);
        ofensivo = new QPushButton(splitter);
        ofensivo->setObjectName(QString::fromUtf8("ofensivo"));
        ofensivo->setFont(font1);
        splitter->addWidget(ofensivo);
        simple = new QPushButton(splitter);
        simple->setObjectName(QString::fromUtf8("simple"));
        simple->setFont(font1);
        splitter->addWidget(simple);
        contrataque = new QPushButton(splitter);
        contrataque->setObjectName(QString::fromUtf8("contrataque"));
        contrataque->setFont(font1);
        splitter->addWidget(contrataque);
        neutralizar = new QPushButton(splitter);
        neutralizar->setObjectName(QString::fromUtf8("neutralizar"));
        neutralizar->setFont(font1);
        splitter->addWidget(neutralizar);
        simulacion = new QPushButton(splitter);
        simulacion->setObjectName(QString::fromUtf8("simulacion"));
        simulacion->setFont(font1);
        splitter->addWidget(simulacion);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1600, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Parcial Final", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Distanacia:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Altura Defensiva:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Altura Ofensiva:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Tiempo", nullptr));
        tiempo->setText(QCoreApplication::translate("MainWindow", "00:00", nullptr));
        lanzar->setText(QCoreApplication::translate("MainWindow", "Lanzar scena", nullptr));
        defensivo->setText(QCoreApplication::translate("MainWindow", "Generar disparo defensivo", nullptr));
        ofensivo->setText(QCoreApplication::translate("MainWindow", "Generar disparo ofensivo", nullptr));
        simple->setText(QCoreApplication::translate("MainWindow", "Defensa simple", nullptr));
        contrataque->setText(QCoreApplication::translate("MainWindow", "Defensa con contrataque", nullptr));
        neutralizar->setText(QCoreApplication::translate("MainWindow", "Neutralizacion efectiva", nullptr));
        simulacion->setText(QCoreApplication::translate("MainWindow", "Simulacion", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
