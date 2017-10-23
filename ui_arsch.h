/********************************************************************************
** Form generated from reading UI file 'arsch.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARSCH_H
#define UI_ARSCH_H

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

class Ui_Arsch
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

    void setupUi(QWidget *Arsch)
    {
        if (Arsch->objectName().isEmpty())
            Arsch->setObjectName(QStringLiteral("Arsch"));
        Arsch->resize(480, 320);
        pushButton = new QPushButton(Arsch);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(180, 260, 113, 71));
        pushButton->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        pushButton->setDefault(false);
        pushButton->setFlat(false);
        timeLabel = new QLabel(Arsch);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));
        timeLabel->setGeometry(QRect(0, 10, 481, 101));
        QFont font;
        font.setPointSize(75);
        font.setBold(true);
        font.setWeight(75);
        timeLabel->setFont(font);
        timeLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        timeLabel->setAlignment(Qt::AlignCenter);
        splitter = new QSplitter(Arsch);
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
        splitter_2 = new QSplitter(Arsch);
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

        retranslateUi(Arsch);

        QMetaObject::connectSlotsByName(Arsch);
    } // setupUi

    void retranslateUi(QWidget *Arsch)
    {
        Arsch->setWindowTitle(QApplication::translate("Arsch", "Form", 0));
        pushButton->setText(QApplication::translate("Arsch", "OK", 0));
        timeLabel->setText(QApplication::translate("Arsch", "12:30", 0));
#ifndef QT_NO_TOOLTIP
        mo_button->setToolTip(QApplication::translate("Arsch", "1", 0));
#endif // QT_NO_TOOLTIP
        mo_button->setText(QApplication::translate("Arsch", "MO", 0));
#ifndef QT_NO_TOOLTIP
        di_button->setToolTip(QApplication::translate("Arsch", "2", 0));
#endif // QT_NO_TOOLTIP
        di_button->setText(QApplication::translate("Arsch", "DI", 0));
#ifndef QT_NO_TOOLTIP
        mi_button->setToolTip(QApplication::translate("Arsch", "3", 0));
#endif // QT_NO_TOOLTIP
        mi_button->setText(QApplication::translate("Arsch", "MI", 0));
#ifndef QT_NO_TOOLTIP
        do_button->setToolTip(QApplication::translate("Arsch", "4", 0));
#endif // QT_NO_TOOLTIP
        do_button->setText(QApplication::translate("Arsch", "DO", 0));
#ifndef QT_NO_TOOLTIP
        fr_button->setToolTip(QApplication::translate("Arsch", "5", 0));
#endif // QT_NO_TOOLTIP
        fr_button->setText(QApplication::translate("Arsch", "FR", 0));
#ifndef QT_NO_TOOLTIP
        sa_button->setToolTip(QApplication::translate("Arsch", "6", 0));
#endif // QT_NO_TOOLTIP
        sa_button->setText(QApplication::translate("Arsch", "SA", 0));
#ifndef QT_NO_TOOLTIP
        so_button->setToolTip(QApplication::translate("Arsch", "7", 0));
#endif // QT_NO_TOOLTIP
        so_button->setText(QApplication::translate("Arsch", "SO", 0));
        hourDown->setText(QApplication::translate("Arsch", "<", 0));
        hourUp->setText(QApplication::translate("Arsch", ">", 0));
        minuteDown->setText(QApplication::translate("Arsch", "<", 0));
        minuteUp->setText(QApplication::translate("Arsch", ">", 0));
    } // retranslateUi

};

namespace Ui {
    class Arsch: public Ui_Arsch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARSCH_H
