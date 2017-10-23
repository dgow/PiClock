/********************************************************************************
** Form generated from reading UI file 'musicplayer.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSICPLAYER_H
#define UI_MUSICPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MusicPlayer
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *HDMButton;
    QPushButton *chillOutButton;
    QPushButton *lightButton;
    QPushButton *okButton;

    void setupUi(QWidget *MusicPlayer)
    {
        if (MusicPlayer->objectName().isEmpty())
            MusicPlayer->setObjectName(QStringLiteral("MusicPlayer"));
        MusicPlayer->resize(480, 320);
        verticalLayout = new QVBoxLayout(MusicPlayer);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        HDMButton = new QPushButton(MusicPlayer);
        HDMButton->setObjectName(QStringLiteral("HDMButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(HDMButton->sizePolicy().hasHeightForWidth());
        HDMButton->setSizePolicy(sizePolicy);
        HDMButton->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        HDMButton->setDefault(false);
        HDMButton->setFlat(false);

        verticalLayout->addWidget(HDMButton);

        chillOutButton = new QPushButton(MusicPlayer);
        chillOutButton->setObjectName(QStringLiteral("chillOutButton"));
        sizePolicy.setHeightForWidth(chillOutButton->sizePolicy().hasHeightForWidth());
        chillOutButton->setSizePolicy(sizePolicy);
        chillOutButton->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        chillOutButton->setDefault(false);
        chillOutButton->setFlat(false);

        verticalLayout->addWidget(chillOutButton);

        lightButton = new QPushButton(MusicPlayer);
        lightButton->setObjectName(QStringLiteral("lightButton"));
        sizePolicy.setHeightForWidth(lightButton->sizePolicy().hasHeightForWidth());
        lightButton->setSizePolicy(sizePolicy);
        lightButton->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(lightButton);

        okButton = new QPushButton(MusicPlayer);
        okButton->setObjectName(QStringLiteral("okButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(okButton->sizePolicy().hasHeightForWidth());
        okButton->setSizePolicy(sizePolicy1);
        okButton->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        okButton->setDefault(false);
        okButton->setFlat(false);

        verticalLayout->addWidget(okButton);


        retranslateUi(MusicPlayer);

        QMetaObject::connectSlotsByName(MusicPlayer);
    } // setupUi

    void retranslateUi(QWidget *MusicPlayer)
    {
        MusicPlayer->setWindowTitle(QApplication::translate("MusicPlayer", "Form", 0));
        HDMButton->setText(QApplication::translate("MusicPlayer", "HDM", 0));
        chillOutButton->setText(QApplication::translate("MusicPlayer", "ChillOut++", 0));
        lightButton->setText(QApplication::translate("MusicPlayer", "Light", 0));
        okButton->setText(QApplication::translate("MusicPlayer", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class MusicPlayer: public Ui_MusicPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICPLAYER_H
