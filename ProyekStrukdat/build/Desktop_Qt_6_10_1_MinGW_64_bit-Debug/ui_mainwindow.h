/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *header;
    QFrame *wadah_logo;
    QFrame *logo;
    QLabel *label_2;
    QLabel *label;
    QFrame *main;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(1366, 768);
        MainWindow->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setFamilies({QString::fromUtf8("Sans Serif Collection")});
        font.setPointSize(12);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0.264045 rgba(239, 246, 255, 255), stop:1 rgba(207, 250, 254, 255));"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setEnabled(true);
        header = new QFrame(centralwidget);
        header->setObjectName("header");
        header->setGeometry(QRect(0, 0, 1366, 100));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Ignored, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(header->sizePolicy().hasHeightForWidth());
        header->setSizePolicy(sizePolicy);
        header->setFont(font);
        header->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        header->setFrameShape(QFrame::Shape::StyledPanel);
        header->setFrameShadow(QFrame::Shadow::Raised);
        header->setLineWidth(10);
        wadah_logo = new QFrame(header);
        wadah_logo->setObjectName("wadah_logo");
        wadah_logo->setGeometry(QRect(40, 15, 721, 70));
        wadah_logo->setFrameShape(QFrame::Shape::StyledPanel);
        wadah_logo->setFrameShadow(QFrame::Shadow::Raised);
        wadah_logo->setLineWidth(0);
        logo = new QFrame(wadah_logo);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(5, 5, 60, 60));
        logo->setBaseSize(QSize(0, 0));
        logo->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"\n"
""));
        logo->setFrameShape(QFrame::Shape::StyledPanel);
        logo->setFrameShadow(QFrame::Shadow::Raised);
        logo->setLineWidth(0);
        label_2 = new QLabel(wadah_logo);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 0, 500, 45));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label = new QLabel(wadah_logo);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 45, 500, 20));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label->setScaledContents(true);
        label->setWordWrap(true);
        main = new QFrame(centralwidget);
        main->setObjectName("main");
        main->setGeometry(QRect(0, 758, 1366, 261));
        main->setFrameShape(QFrame::Shape::StyledPanel);
        main->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout = new QVBoxLayout(main);
        verticalLayout->setObjectName("verticalLayout");
        scrollArea = new QScrollArea(main);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1344, 239));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Mikie Funland Navigator", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Mikie Funland Navigator", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Smart Navigation for a Better Funland Experience", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
