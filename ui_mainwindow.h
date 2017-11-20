/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "alarmsettings.h"
#include "musicplayer.h"
#include "scrolltext.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_3;
    QStackedWidget *stackedWidget;
    QWidget *clock;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *songLabel;
    ScrollText *fancyWidget;
    QLabel *playStateLabel;
    QProgressBar *volumeBar;
    QFrame *line;
    QLabel *timeLabel;
    QHBoxLayout *horizontalLayout;
    QLabel *volumeIcon;
    QLabel *volumeLabel;
    QLabel *weatherLabel;
    QLabel *weatherIcon;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *soundButton;
    QLabel *dateLabel;
    QPushButton *alarmButton;
    AlarmSettings *arschPage;
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
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(5, 5, 5, 5);
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        clock = new QWidget();
        clock->setObjectName(QStringLiteral("clock"));
        verticalLayout = new QVBoxLayout(clock);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        songLabel = new QLabel(clock);
        songLabel->setObjectName(QStringLiteral("songLabel"));
        songLabel->setMinimumSize(QSize(1, 0));
        songLabel->setMaximumSize(QSize(0, 16777215));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(10);
        songLabel->setFont(font);
        songLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        songLabel->setAlignment(Qt::AlignCenter);
        songLabel->setIndent(-1);

        horizontalLayout_4->addWidget(songLabel);

        fancyWidget = new ScrollText(clock);
        fancyWidget->setObjectName(QStringLiteral("fancyWidget"));
        fancyWidget->setMinimumSize(QSize(100, 28));
        QFont font1;
        font1.setFamily(QStringLiteral("Helvetica"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        fancyWidget->setFont(font1);
        fancyWidget->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_4->addWidget(fancyWidget);

        playStateLabel = new QLabel(clock);
        playStateLabel->setObjectName(QStringLiteral("playStateLabel"));
        QFont font2;
        font2.setPointSize(17);
        playStateLabel->setFont(font2);
        playStateLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        playStateLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        playStateLabel->setMargin(3);
        playStateLabel->setIndent(-10);

        horizontalLayout_4->addWidget(playStateLabel);

        horizontalLayout_4->setStretch(1, 10);

        verticalLayout->addLayout(horizontalLayout_4);

        volumeBar = new QProgressBar(clock);
        volumeBar->setObjectName(QStringLiteral("volumeBar"));
        volumeBar->setMaximumSize(QSize(16777215, 3));
        volumeBar->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        volumeBar->setValue(0);
        volumeBar->setTextVisible(false);

        verticalLayout->addWidget(volumeBar);

        line = new QFrame(clock);
        line->setObjectName(QStringLiteral("line"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy);
        line->setMinimumSize(QSize(0, 15));
        line->setFrameShadow(QFrame::Sunken);
        line->setLineWidth(0);
        line->setFrameShape(QFrame::HLine);

        verticalLayout->addWidget(line);

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
        QFont font3;
        font3.setFamily(QStringLiteral("DecoType Naskh"));
        font3.setPointSize(100);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        font3.setStrikeOut(false);
        timeLabel->setFont(font3);
        timeLabel->setAlignment(Qt::AlignCenter);
        timeLabel->setMargin(5);

        verticalLayout->addWidget(timeLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, -1, -1, -1);
        volumeIcon = new QLabel(clock);
        volumeIcon->setObjectName(QStringLiteral("volumeIcon"));
        volumeIcon->setMaximumSize(QSize(40, 40));
        volumeIcon->setPixmap(QPixmap(QString::fromUtf8(":/images/loud_sound.png")));
        volumeIcon->setScaledContents(true);
        volumeIcon->setMargin(0);

        horizontalLayout->addWidget(volumeIcon);

        volumeLabel = new QLabel(clock);
        volumeLabel->setObjectName(QStringLiteral("volumeLabel"));
        QFont font4;
        font4.setPointSize(25);
        volumeLabel->setFont(font4);
        volumeLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(volumeLabel);

        weatherLabel = new QLabel(clock);
        weatherLabel->setObjectName(QStringLiteral("weatherLabel"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        weatherLabel->setPalette(palette1);
        QFont font5;
        font5.setPointSize(30);
        weatherLabel->setFont(font5);
        weatherLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(weatherLabel);

        weatherIcon = new QLabel(clock);
        weatherIcon->setObjectName(QStringLiteral("weatherIcon"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(weatherIcon->sizePolicy().hasHeightForWidth());
        weatherIcon->setSizePolicy(sizePolicy1);
        weatherIcon->setMaximumSize(QSize(50, 50));
        weatherIcon->setPixmap(QPixmap(QString::fromUtf8(":/weather/weatherIcons/01d.png")));
        weatherIcon->setScaledContents(true);

        horizontalLayout->addWidget(weatherIcon);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        soundButton = new QPushButton(clock);
        soundButton->setObjectName(QStringLiteral("soundButton"));
        soundButton->setMinimumSize(QSize(0, 60));
        QFont font6;
        font6.setPointSize(15);
        soundButton->setFont(font6);
        soundButton->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(soundButton);

        dateLabel = new QLabel(clock);
        dateLabel->setObjectName(QStringLiteral("dateLabel"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        dateLabel->setPalette(palette2);
        QFont font7;
        font7.setFamily(QStringLiteral("Helvetica"));
        font7.setPointSize(17);
        dateLabel->setFont(font7);
        dateLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(dateLabel);

        alarmButton = new QPushButton(clock);
        alarmButton->setObjectName(QStringLiteral("alarmButton"));
        alarmButton->setMinimumSize(QSize(0, 60));
        alarmButton->setFont(font6);
        alarmButton->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(alarmButton);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 10);
        horizontalLayout_2->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        stackedWidget->addWidget(clock);
        arschPage = new AlarmSettings();
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
        QFont font8;
        font8.setPointSize(100);
        bigAlarmLabel->setFont(font8);
        bigAlarmLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        bigAlarmLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(bigAlarmLabel);

        stopAlarmButton = new QPushButton(page);
        stopAlarmButton->setObjectName(QStringLiteral("stopAlarmButton"));
        stopAlarmButton->setMinimumSize(QSize(0, 100));
        QFont font9;
        font9.setPointSize(50);
        stopAlarmButton->setFont(font9);
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

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        songLabel->setText(QString());
        playStateLabel->setText(QApplication::translate("MainWindow", "***", Q_NULLPTR));
        timeLabel->setText(QApplication::translate("MainWindow", "12:56", Q_NULLPTR));
        volumeIcon->setText(QString());
        volumeLabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        weatherLabel->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        weatherIcon->setText(QString());
        soundButton->setText(QApplication::translate("MainWindow", "Music", Q_NULLPTR));
        dateLabel->setText(QApplication::translate("MainWindow", "-------", Q_NULLPTR));
        alarmButton->setText(QApplication::translate("MainWindow", "Alarm", Q_NULLPTR));
        bigAlarmLabel->setText(QApplication::translate("MainWindow", "ALARM", Q_NULLPTR));
        stopAlarmButton->setText(QApplication::translate("MainWindow", "OK", Q_NULLPTR));
        Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
