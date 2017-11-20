/********************************************************************************
** Form generated from reading UI file 'alarmsettings.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALARMSETTINGS_H
#define UI_ALARMSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>
#include "weekdaybutton.h"

QT_BEGIN_NAMESPACE

class Ui_AlarmSettings
{
public:
    QPushButton *pushButton;
    QLabel *timeLabel;
    QSplitter *splitter;
    WeekDayButton *mo_button;
    WeekDayButton *di_button;
    WeekDayButton *mi_button;
    WeekDayButton *do_button;
    WeekDayButton *fr_button;
    WeekDayButton *sa_button;
    WeekDayButton *so_button;
    QSplitter *splitter_2;
    QPushButton *hourDown;
    QPushButton *hourUp;
    QPushButton *minuteDown;
    QPushButton *minuteUp;

    void setupUi(QWidget *AlarmSettings)
    {
        if (AlarmSettings->objectName().isEmpty())
            AlarmSettings->setObjectName(QStringLiteral("AlarmSettings"));
        AlarmSettings->resize(480, 320);
        pushButton = new QPushButton(AlarmSettings);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(180, 260, 113, 71));
        pushButton->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        pushButton->setFlat(false);
        timeLabel = new QLabel(AlarmSettings);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));
        timeLabel->setGeometry(QRect(0, 10, 481, 101));
        QFont font;
        font.setPointSize(75);
        font.setBold(true);
        font.setWeight(75);
        timeLabel->setFont(font);
        timeLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        timeLabel->setAlignment(Qt::AlignCenter);
        splitter = new QSplitter(AlarmSettings);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(0, 190, 481, 61));
        splitter->setOrientation(Qt::Horizontal);
        splitter->setOpaqueResize(false);
        splitter->setHandleWidth(0);
        mo_button = new WeekDayButton(splitter);
        mo_button->setObjectName(QStringLiteral("mo_button"));
        mo_button->setCheckable(true);
        mo_button->setFlat(false);
        splitter->addWidget(mo_button);
        di_button = new WeekDayButton(splitter);
        di_button->setObjectName(QStringLiteral("di_button"));
        di_button->setCheckable(true);
        di_button->setFlat(false);
        splitter->addWidget(di_button);
        mi_button = new WeekDayButton(splitter);
        mi_button->setObjectName(QStringLiteral("mi_button"));
        mi_button->setCheckable(true);
        mi_button->setFlat(false);
        splitter->addWidget(mi_button);
        do_button = new WeekDayButton(splitter);
        do_button->setObjectName(QStringLiteral("do_button"));
        do_button->setCheckable(true);
        do_button->setFlat(false);
        splitter->addWidget(do_button);
        fr_button = new WeekDayButton(splitter);
        fr_button->setObjectName(QStringLiteral("fr_button"));
        fr_button->setCheckable(true);
        fr_button->setFlat(false);
        splitter->addWidget(fr_button);
        sa_button = new WeekDayButton(splitter);
        sa_button->setObjectName(QStringLiteral("sa_button"));
        sa_button->setCheckable(true);
        sa_button->setFlat(false);
        splitter->addWidget(sa_button);
        so_button = new WeekDayButton(splitter);
        so_button->setObjectName(QStringLiteral("so_button"));
        so_button->setCheckable(true);
        so_button->setFlat(false);
        splitter->addWidget(so_button);
        splitter_2 = new QSplitter(AlarmSettings);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setGeometry(QRect(30, 110, 411, 71));
        splitter_2->setOrientation(Qt::Horizontal);
        hourDown = new QPushButton(splitter_2);
        hourDown->setObjectName(QStringLiteral("hourDown"));
        hourDown->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        hourDown->setFlat(false);
        splitter_2->addWidget(hourDown);
        hourUp = new QPushButton(splitter_2);
        hourUp->setObjectName(QStringLiteral("hourUp"));
        hourUp->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        hourUp->setFlat(false);
        splitter_2->addWidget(hourUp);
        minuteDown = new QPushButton(splitter_2);
        minuteDown->setObjectName(QStringLiteral("minuteDown"));
        minuteDown->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        minuteDown->setFlat(false);
        splitter_2->addWidget(minuteDown);
        minuteUp = new QPushButton(splitter_2);
        minuteUp->setObjectName(QStringLiteral("minuteUp"));
        minuteUp->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        minuteUp->setFlat(false);
        splitter_2->addWidget(minuteUp);

        retranslateUi(AlarmSettings);

        pushButton->setDefault(false);


        QMetaObject::connectSlotsByName(AlarmSettings);
    } // setupUi

    void retranslateUi(QWidget *AlarmSettings)
    {
        AlarmSettings->setWindowTitle(QApplication::translate("AlarmSettings", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("AlarmSettings", "OK", Q_NULLPTR));
        timeLabel->setText(QApplication::translate("AlarmSettings", "12:30", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        mo_button->setToolTip(QApplication::translate("AlarmSettings", "1", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        mo_button->setText(QApplication::translate("AlarmSettings", "MO", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        di_button->setToolTip(QApplication::translate("AlarmSettings", "2", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        di_button->setText(QApplication::translate("AlarmSettings", "DI", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        mi_button->setToolTip(QApplication::translate("AlarmSettings", "3", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        mi_button->setText(QApplication::translate("AlarmSettings", "MI", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        do_button->setToolTip(QApplication::translate("AlarmSettings", "4", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        do_button->setText(QApplication::translate("AlarmSettings", "DO", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        fr_button->setToolTip(QApplication::translate("AlarmSettings", "5", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        fr_button->setText(QApplication::translate("AlarmSettings", "FR", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        sa_button->setToolTip(QApplication::translate("AlarmSettings", "6", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        sa_button->setText(QApplication::translate("AlarmSettings", "SA", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        so_button->setToolTip(QApplication::translate("AlarmSettings", "7", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        so_button->setText(QApplication::translate("AlarmSettings", "SO", Q_NULLPTR));
        hourDown->setText(QApplication::translate("AlarmSettings", "<", Q_NULLPTR));
        hourUp->setText(QApplication::translate("AlarmSettings", ">", Q_NULLPTR));
        minuteDown->setText(QApplication::translate("AlarmSettings", "<", Q_NULLPTR));
        minuteUp->setText(QApplication::translate("AlarmSettings", ">", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AlarmSettings: public Ui_AlarmSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALARMSETTINGS_H
