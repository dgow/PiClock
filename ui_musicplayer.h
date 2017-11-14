/********************************************************************************
** Form generated from reading UI file 'musicplayer.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
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
    QPushButton *gongButton;
    QPushButton *mixTapeButton;
    QPushButton *lightButton;
    QPushButton *okButton;

    void setupUi(QWidget *MusicPlayer)
    {
        if (MusicPlayer->objectName().isEmpty())
            MusicPlayer->setObjectName(QStringLiteral("MusicPlayer"));
        MusicPlayer->resize(480, 322);
        verticalLayout = new QVBoxLayout(MusicPlayer);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        HDMButton = new QPushButton(MusicPlayer);
        HDMButton->setObjectName(QStringLiteral("HDMButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(HDMButton->sizePolicy().hasHeightForWidth());
        HDMButton->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(30);
        HDMButton->setFont(font);
        HDMButton->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        HDMButton->setFlat(false);

        verticalLayout->addWidget(HDMButton);

        chillOutButton = new QPushButton(MusicPlayer);
        chillOutButton->setObjectName(QStringLiteral("chillOutButton"));
        sizePolicy.setHeightForWidth(chillOutButton->sizePolicy().hasHeightForWidth());
        chillOutButton->setSizePolicy(sizePolicy);
        chillOutButton->setFont(font);
        chillOutButton->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        chillOutButton->setFlat(false);

        verticalLayout->addWidget(chillOutButton);

        gongButton = new QPushButton(MusicPlayer);
        gongButton->setObjectName(QStringLiteral("gongButton"));
        sizePolicy.setHeightForWidth(gongButton->sizePolicy().hasHeightForWidth());
        gongButton->setSizePolicy(sizePolicy);
        gongButton->setFont(font);
        gongButton->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        gongButton->setFlat(false);

        verticalLayout->addWidget(gongButton);

        mixTapeButton = new QPushButton(MusicPlayer);
        mixTapeButton->setObjectName(QStringLiteral("mixTapeButton"));
        mixTapeButton->setFont(font);
        mixTapeButton->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        mixTapeButton->setFlat(false);

        verticalLayout->addWidget(mixTapeButton);

        lightButton = new QPushButton(MusicPlayer);
        lightButton->setObjectName(QStringLiteral("lightButton"));
        sizePolicy.setHeightForWidth(lightButton->sizePolicy().hasHeightForWidth());
        lightButton->setSizePolicy(sizePolicy);
        lightButton->setFont(font);
        lightButton->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(lightButton);

        okButton = new QPushButton(MusicPlayer);
        okButton->setObjectName(QStringLiteral("okButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(okButton->sizePolicy().hasHeightForWidth());
        okButton->setSizePolicy(sizePolicy1);
        okButton->setFont(font);
        okButton->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        okButton->setFlat(false);

        verticalLayout->addWidget(okButton);


        retranslateUi(MusicPlayer);

        HDMButton->setDefault(false);
        chillOutButton->setDefault(false);
        gongButton->setDefault(false);
        mixTapeButton->setDefault(false);
        okButton->setDefault(false);


        QMetaObject::connectSlotsByName(MusicPlayer);
    } // setupUi

    void retranslateUi(QWidget *MusicPlayer)
    {
        MusicPlayer->setWindowTitle(QApplication::translate("MusicPlayer", "Form", Q_NULLPTR));
        HDMButton->setText(QApplication::translate("MusicPlayer", "HDM", Q_NULLPTR));
        chillOutButton->setText(QApplication::translate("MusicPlayer", "ChillOut++", Q_NULLPTR));
        gongButton->setText(QApplication::translate("MusicPlayer", "Gong", Q_NULLPTR));
        mixTapeButton->setText(QApplication::translate("MusicPlayer", "MixTape", Q_NULLPTR));
        lightButton->setText(QApplication::translate("MusicPlayer", "Light", Q_NULLPTR));
        okButton->setText(QApplication::translate("MusicPlayer", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MusicPlayer: public Ui_MusicPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICPLAYER_H
