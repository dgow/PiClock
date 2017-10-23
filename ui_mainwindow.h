/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "arsch.h"
#include "musicplayer.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_3;
    QStackedWidget *stackedWidget;
    QWidget *clock;
    QVBoxLayout *verticalLayout;
    QLabel *timeLabel;
    QHBoxLayout *horizontalLayout;
    QLabel *weatherLabel;
    QLabel *weatherIcon;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *soundButton;
    QLabel *dateLabel;
    QPushButton *alarmButton;
    Arsch *arschPage;
    QWidget *page;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *bigAlarmLabel;
    QPushButton *stopAlarmButton;
    MusicPlayer *musicPlayer;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(480, 320);
        MainWindow->setMinimumSize(QSize(480, 320));
        MainWindow->setMaximumSize(QSize(480, 320));
        MainWindow->setWindowTitle(QStringLiteral("PiClock"));
        MainWindow->setAutoFillBackground(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_3 = new QHBoxLayout(centralWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        clock = new QWidget();
        clock->setObjectName(QStringLiteral("clock"));
        verticalLayout = new QVBoxLayout(clock);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        timeLabel = new QLabel(clock);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(127, 127, 127, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        timeLabel->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("DejaVu Sans Mono for Powerline"));
        font.setPointSize(110);
        font.setItalic(true);
        font.setStrikeOut(false);
        timeLabel->setFont(font);
        timeLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(timeLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(100, -1, 100, -1);
        weatherLabel = new QLabel(clock);
        weatherLabel->setObjectName(QStringLiteral("weatherLabel"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        weatherLabel->setPalette(palette1);
        QFont font1;
        font1.setPointSize(40);
        weatherLabel->setFont(font1);
        weatherLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(weatherLabel);

        weatherIcon = new QLabel(clock);
        weatherIcon->setObjectName(QStringLiteral("weatherIcon"));

        horizontalLayout->addWidget(weatherIcon);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        soundButton = new QPushButton(clock);
        soundButton->setObjectName(QStringLiteral("soundButton"));
        soundButton->setMinimumSize(QSize(0, 60));
        soundButton->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(soundButton);

        dateLabel = new QLabel(clock);
        dateLabel->setObjectName(QStringLiteral("dateLabel"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        dateLabel->setPalette(palette2);
        QFont font2;
        font2.setFamily(QStringLiteral("Helvetica"));
        font2.setPointSize(18);
        dateLabel->setFont(font2);
        dateLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(dateLabel);

        alarmButton = new QPushButton(clock);
        alarmButton->setObjectName(QStringLiteral("alarmButton"));
        alarmButton->setMinimumSize(QSize(0, 60));
        alarmButton->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(alarmButton);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 10);
        horizontalLayout_2->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        stackedWidget->addWidget(clock);
        arschPage = new Arsch();
        arschPage->setObjectName(QStringLiteral("arschPage"));
        stackedWidget->addWidget(arschPage);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        verticalLayout_3 = new QVBoxLayout(page);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        bigAlarmLabel = new QLabel(page);
        bigAlarmLabel->setObjectName(QStringLiteral("bigAlarmLabel"));
        QFont font3;
        font3.setPointSize(100);
        bigAlarmLabel->setFont(font3);
        bigAlarmLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        bigAlarmLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(bigAlarmLabel);

        stopAlarmButton = new QPushButton(page);
        stopAlarmButton->setObjectName(QStringLiteral("stopAlarmButton"));
        stopAlarmButton->setMinimumSize(QSize(0, 100));
        QFont font4;
        font4.setPointSize(50);
        stopAlarmButton->setFont(font4);
        stopAlarmButton->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(stopAlarmButton);

        verticalLayout_2->setStretch(0, 100);
        verticalLayout_2->setStretch(1, 1);

        verticalLayout_3->addLayout(verticalLayout_2);

        stackedWidget->addWidget(page);
        musicPlayer = new MusicPlayer();
        musicPlayer->setObjectName(QStringLiteral("musicPlayer"));
        stackedWidget->addWidget(musicPlayer);

        horizontalLayout_3->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        timeLabel->setText(QApplication::translate("MainWindow", "12:56", 0));
        weatherLabel->setText(QApplication::translate("MainWindow", "-", 0));
        weatherIcon->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        soundButton->setText(QApplication::translate("MainWindow", "Music", 0));
        dateLabel->setText(QApplication::translate("MainWindow", "-------", 0));
        alarmButton->setText(QApplication::translate("MainWindow", "Alarm", 0));
        bigAlarmLabel->setText(QApplication::translate("MainWindow", "ALARM", 0));
        stopAlarmButton->setText(QApplication::translate("MainWindow", "OK", 0));
        Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
