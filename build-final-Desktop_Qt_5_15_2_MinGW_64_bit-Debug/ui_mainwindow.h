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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionPausa;
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLabel *label_7;
    QSpinBox *crono;
    QLabel *tiempo;
    QLabel *label_6;
    QLabel *label_4;
    QPushButton *lanzar;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QDoubleSpinBox *distancia;
    QLabel *label_2;
    QDoubleSpinBox *alt_def;
    QLabel *label_3;
    QDoubleSpinBox *alt_ofe;
    QSplitter *splitter;
    QPushButton *defensivo;
    QPushButton *ofensivo;
    QPushButton *simple;
    QPushButton *contrataque;
    QPushButton *neutralizar;
    QPushButton *simulacion;
    QMenuBar *menubar;
    QMenu *menuOpciones;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1600, 800);
        MainWindow->setMaximumSize(QSize(1600, 800));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pictures/canon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setIconSize(QSize(48, 48));
        actionPausa = new QAction(MainWindow);
        actionPausa->setObjectName(QString::fromUtf8("actionPausa"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 1280, 740));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(1290, 200, 291, 163));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(10);
        gridLayout->setVerticalSpacing(7);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font;
        font.setFamily(QString::fromUtf8("Verdana"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 2, 0, 1, 2);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        gridLayout->addWidget(label_7, 1, 1, 1, 1);

        crono = new QSpinBox(widget);
        crono->setObjectName(QString::fromUtf8("crono"));
        crono->setMaximum(1000);
        crono->setValue(10);

        gridLayout->addWidget(crono, 3, 0, 1, 1);

        tiempo = new QLabel(widget);
        tiempo->setObjectName(QString::fromUtf8("tiempo"));
        tiempo->setFont(font);

        gridLayout->addWidget(tiempo, 1, 0, 1, 1);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 3, 1, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 0, 0, 1, 2);

        lanzar = new QPushButton(widget);
        lanzar->setObjectName(QString::fromUtf8("lanzar"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Verdana"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        lanzar->setFont(font1);

        gridLayout->addWidget(lanzar, 4, 0, 1, 2);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(1290, 11, 297, 187));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        verticalLayout->addWidget(label);

        distancia = new QDoubleSpinBox(widget1);
        distancia->setObjectName(QString::fromUtf8("distancia"));
        distancia->setMinimum(102.000000000000000);
        distancia->setMaximum(4800.000000000000000);
        distancia->setValue(300.000000000000000);

        verticalLayout->addWidget(distancia);

        label_2 = new QLabel(widget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        alt_def = new QDoubleSpinBox(widget1);
        alt_def->setObjectName(QString::fromUtf8("alt_def"));
        alt_def->setMaximum(720.000000000000000);
        alt_def->setValue(300.000000000000000);

        verticalLayout->addWidget(alt_def);

        label_3 = new QLabel(widget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        verticalLayout->addWidget(label_3);

        alt_ofe = new QDoubleSpinBox(widget1);
        alt_ofe->setObjectName(QString::fromUtf8("alt_ofe"));
        alt_ofe->setMaximum(720.000000000000000);
        alt_ofe->setValue(300.000000000000000);

        verticalLayout->addWidget(alt_ofe);

        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(1291, 371, 301, 341));
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
        menuOpciones = new QMenu(menubar);
        menuOpciones->setObjectName(QString::fromUtf8("menuOpciones"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuOpciones->menuAction());
        menuOpciones->addAction(actionPausa);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Parcial Final", nullptr));
        actionPausa->setText(QCoreApplication::translate("MainWindow", "Pausa", nullptr));
#if QT_CONFIG(shortcut)
        actionPausa->setShortcut(QCoreApplication::translate("MainWindow", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        label_5->setText(QCoreApplication::translate("MainWindow", "Velocidad", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Segundos", nullptr));
        tiempo->setText(QCoreApplication::translate("MainWindow", "00:00", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Milisegundos", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Tiempo del disparo", nullptr));
        lanzar->setText(QCoreApplication::translate("MainWindow", "Lanzar scena", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Distanacia(metros):", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Altura Defensiva(metros):", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Altura Ofensiva(metros):", nullptr));
        defensivo->setText(QCoreApplication::translate("MainWindow", "Generar disparo defensivo", nullptr));
        ofensivo->setText(QCoreApplication::translate("MainWindow", "Generar disparo ofensivo", nullptr));
        simple->setText(QCoreApplication::translate("MainWindow", "Defensa simple", nullptr));
        contrataque->setText(QCoreApplication::translate("MainWindow", "Defensa con contrataque", nullptr));
        neutralizar->setText(QCoreApplication::translate("MainWindow", "Neutralizacion efectiva", nullptr));
        simulacion->setText(QCoreApplication::translate("MainWindow", "Simulacion", nullptr));
        menuOpciones->setTitle(QCoreApplication::translate("MainWindow", "Opciones", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
