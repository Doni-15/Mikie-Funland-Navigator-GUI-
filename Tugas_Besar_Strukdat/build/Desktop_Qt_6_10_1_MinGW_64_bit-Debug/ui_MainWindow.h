/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
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
#include <QtWidgets/QHBoxLayout>
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
    QVBoxLayout *verticalLayout;
    QScrollArea *main_content;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QFrame *header;
    QHBoxLayout *horizontalLayout;
    QFrame *logo;
    QFrame *nama_grup;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QLabel *label_2;
    QFrame *main_layout;
    QVBoxLayout *verticalLayout_2;
    QFrame *cari_rute;
    QFrame *telusuri_wahana;
    QFrame *footer;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(800, 600);
        QFont font;
        font.setFamilies({QString::fromUtf8("Sans Serif Collection")});
        font.setPointSize(12);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setEnabled(true);
        centralwidget->setFont(font);
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        main_content = new QScrollArea(centralwidget);
        main_content->setObjectName("main_content");
        main_content->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        main_content->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 798, 598));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        header = new QFrame(scrollAreaWidgetContents);
        header->setObjectName("header");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(header->sizePolicy().hasHeightForWidth());
        header->setSizePolicy(sizePolicy);
        header->setMaximumSize(QSize(16777215, 100));
        header->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        header->setFrameShape(QFrame::Shape::StyledPanel);
        header->setFrameShadow(QFrame::Shadow::Raised);
        header->setLineWidth(0);
        horizontalLayout = new QHBoxLayout(header);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
        horizontalLayout->setContentsMargins(30, 10, 30, 10);
        logo = new QFrame(header);
        logo->setObjectName("logo");
        logo->setMaximumSize(QSize(60, 60));
        logo->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        logo->setFrameShape(QFrame::Shape::StyledPanel);
        logo->setFrameShadow(QFrame::Shadow::Raised);

        horizontalLayout->addWidget(logo);

        nama_grup = new QFrame(header);
        nama_grup->setObjectName("nama_grup");
        nama_grup->setMaximumSize(QSize(16777215, 70));
        nama_grup->setFont(font);
        nama_grup->setFrameShape(QFrame::Shape::StyledPanel);
        nama_grup->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_4 = new QVBoxLayout(nama_grup);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, -1, 0);
        label = new QLabel(nama_grup);
        label->setObjectName("label");
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_4->addWidget(label);

        label_2 = new QLabel(nama_grup);
        label_2->setObjectName("label_2");
        QFont font2;
        font2.setPointSize(12);
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_4->addWidget(label_2);


        horizontalLayout->addWidget(nama_grup);


        verticalLayout_3->addWidget(header);

        main_layout = new QFrame(scrollAreaWidgetContents);
        main_layout->setObjectName("main_layout");
        main_layout->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        main_layout->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:1, stop:0 rgba(239, 246, 255, 255), stop:0.337079 rgba(207, 250, 254, 255))"));
        main_layout->setFrameShape(QFrame::Shape::StyledPanel);
        main_layout->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_2 = new QVBoxLayout(main_layout);
        verticalLayout_2->setSpacing(30);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(30, 30, 30, 30);
        cari_rute = new QFrame(main_layout);
        cari_rute->setObjectName("cari_rute");
        cari_rute->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        cari_rute->setFrameShape(QFrame::Shape::StyledPanel);
        cari_rute->setFrameShadow(QFrame::Shadow::Raised);

        verticalLayout_2->addWidget(cari_rute);

        telusuri_wahana = new QFrame(main_layout);
        telusuri_wahana->setObjectName("telusuri_wahana");
        telusuri_wahana->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        telusuri_wahana->setFrameShape(QFrame::Shape::StyledPanel);
        telusuri_wahana->setFrameShadow(QFrame::Shadow::Raised);

        verticalLayout_2->addWidget(telusuri_wahana);

        footer = new QFrame(main_layout);
        footer->setObjectName("footer");
        footer->setMaximumSize(QSize(16777215, 80));
        footer->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        footer->setStyleSheet(QString::fromUtf8(""));
        footer->setFrameShape(QFrame::Shape::StyledPanel);
        footer->setFrameShadow(QFrame::Shadow::Raised);

        verticalLayout_2->addWidget(footer);


        verticalLayout_3->addWidget(main_layout);

        main_content->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(main_content);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Mikei Funland Navigator", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Mikie Funland Navigator", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Smart Navigation for a Better Funland Experience", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
