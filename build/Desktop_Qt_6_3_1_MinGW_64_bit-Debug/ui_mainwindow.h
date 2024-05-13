/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *CPUCards;
    QWidget *layoutWidget_2;
    QHBoxLayout *PlayerCards;
    QFrame *Controls;
    QPushButton *PlayButton;
    QCheckBox *DeBugMode;
    QLabel *roundCount_3;
    QFrame *GameControls;
    QPushButton *next;
    QPushButton *swapCard;
    QPushButton *sortByGroup;
    QPushButton *sortByValue;
    QPushButton *Restart;
    QLabel *swapsLeft;
    QLabel *round;
    QFrame *Results;
    QLabel *roundCount_2;
    QLabel *winner;
    QLabel *playerScore;
    QLabel *cpuScore;
    QFrame *display;
    QPushButton *skip;
    QLabel *roundCount;
    QLabel *cpuScore_2;
    QLabel *playerScore_2;
    QLabel *roundInfo;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1283, 560);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 741, 261));
        CPUCards = new QHBoxLayout(layoutWidget);
        CPUCards->setSpacing(5);
        CPUCards->setObjectName(QString::fromUtf8("CPUCards"));
        CPUCards->setContentsMargins(0, 0, 0, 0);
        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(0, 280, 741, 271));
        PlayerCards = new QHBoxLayout(layoutWidget_2);
        PlayerCards->setSpacing(5);
        PlayerCards->setObjectName(QString::fromUtf8("PlayerCards"));
        PlayerCards->setContentsMargins(0, 0, 0, 0);
        Controls = new QFrame(centralwidget);
        Controls->setObjectName(QString::fromUtf8("Controls"));
        Controls->setGeometry(QRect(830, 20, 351, 211));
        Controls->setFrameShape(QFrame::Box);
        Controls->setFrameShadow(QFrame::Raised);
        PlayButton = new QPushButton(Controls);
        PlayButton->setObjectName(QString::fromUtf8("PlayButton"));
        PlayButton->setGeometry(QRect(130, 130, 91, 31));
        DeBugMode = new QCheckBox(Controls);
        DeBugMode->setObjectName(QString::fromUtf8("DeBugMode"));
        DeBugMode->setGeometry(QRect(140, 170, 78, 22));
        roundCount_3 = new QLabel(Controls);
        roundCount_3->setObjectName(QString::fromUtf8("roundCount_3"));
        roundCount_3->setGeometry(QRect(30, 20, 301, 91));
        QFont font;
        font.setPointSize(72);
        roundCount_3->setFont(font);
        GameControls = new QFrame(centralwidget);
        GameControls->setObjectName(QString::fromUtf8("GameControls"));
        GameControls->setEnabled(true);
        GameControls->setGeometry(QRect(830, 270, 351, 211));
        GameControls->setFrameShape(QFrame::StyledPanel);
        GameControls->setFrameShadow(QFrame::Raised);
        next = new QPushButton(GameControls);
        next->setObjectName(QString::fromUtf8("next"));
        next->setGeometry(QRect(10, 10, 91, 31));
        swapCard = new QPushButton(GameControls);
        swapCard->setObjectName(QString::fromUtf8("swapCard"));
        swapCard->setGeometry(QRect(10, 50, 91, 31));
        sortByGroup = new QPushButton(GameControls);
        sortByGroup->setObjectName(QString::fromUtf8("sortByGroup"));
        sortByGroup->setGeometry(QRect(10, 110, 91, 31));
        sortByValue = new QPushButton(GameControls);
        sortByValue->setObjectName(QString::fromUtf8("sortByValue"));
        sortByValue->setGeometry(QRect(10, 150, 91, 31));
        Restart = new QPushButton(GameControls);
        Restart->setObjectName(QString::fromUtf8("Restart"));
        Restart->setGeometry(QRect(120, 130, 221, 51));
        swapsLeft = new QLabel(GameControls);
        swapsLeft->setObjectName(QString::fromUtf8("swapsLeft"));
        swapsLeft->setGeometry(QRect(120, 70, 221, 51));
        QFont font1;
        font1.setPointSize(11);
        swapsLeft->setFont(font1);
        round = new QLabel(GameControls);
        round->setObjectName(QString::fromUtf8("round"));
        round->setGeometry(QRect(120, 20, 221, 51));
        round->setFont(font1);
        Results = new QFrame(centralwidget);
        Results->setObjectName(QString::fromUtf8("Results"));
        Results->setGeometry(QRect(830, 250, 351, 261));
        Results->setFrameShape(QFrame::StyledPanel);
        Results->setFrameShadow(QFrame::Raised);
        roundCount_2 = new QLabel(Results);
        roundCount_2->setObjectName(QString::fromUtf8("roundCount_2"));
        roundCount_2->setGeometry(QRect(30, 10, 301, 51));
        QFont font2;
        font2.setPointSize(36);
        roundCount_2->setFont(font2);
        winner = new QLabel(Results);
        winner->setObjectName(QString::fromUtf8("winner"));
        winner->setGeometry(QRect(30, 70, 301, 51));
        QFont font3;
        font3.setPointSize(24);
        winner->setFont(font3);
        playerScore = new QLabel(Results);
        playerScore->setObjectName(QString::fromUtf8("playerScore"));
        playerScore->setGeometry(QRect(30, 130, 301, 51));
        playerScore->setFont(font3);
        cpuScore = new QLabel(Results);
        cpuScore->setObjectName(QString::fromUtf8("cpuScore"));
        cpuScore->setGeometry(QRect(30, 190, 301, 51));
        cpuScore->setFont(font3);
        display = new QFrame(centralwidget);
        display->setObjectName(QString::fromUtf8("display"));
        display->setEnabled(true);
        display->setGeometry(QRect(180, 150, 351, 211));
        display->setAutoFillBackground(true);
        display->setFrameShape(QFrame::Box);
        display->setFrameShadow(QFrame::Plain);
        display->setMidLineWidth(1);
        skip = new QPushButton(display);
        skip->setObjectName(QString::fromUtf8("skip"));
        skip->setGeometry(QRect(140, 160, 81, 31));
        roundCount = new QLabel(display);
        roundCount->setObjectName(QString::fromUtf8("roundCount"));
        roundCount->setGeometry(QRect(150, 30, 191, 20));
        cpuScore_2 = new QLabel(display);
        cpuScore_2->setObjectName(QString::fromUtf8("cpuScore_2"));
        cpuScore_2->setGeometry(QRect(230, 130, 101, 71));
        cpuScore_2->setFont(font1);
        playerScore_2 = new QLabel(display);
        playerScore_2->setObjectName(QString::fromUtf8("playerScore_2"));
        playerScore_2->setGeometry(QRect(20, 130, 121, 71));
        playerScore_2->setFont(font1);
        roundInfo = new QLabel(display);
        roundInfo->setObjectName(QString::fromUtf8("roundInfo"));
        roundInfo->setGeometry(QRect(20, 60, 301, 71));
        QFont font4;
        font4.setPointSize(14);
        roundInfo->setFont(font4);
        MainWindow->setCentralWidget(centralwidget);
        layoutWidget->raise();
        layoutWidget_2->raise();
        Controls->raise();
        Results->raise();
        GameControls->raise();
        display->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Poker Game", nullptr));
        PlayButton->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
        DeBugMode->setText(QCoreApplication::translate("MainWindow", "Debug", nullptr));
        roundCount_3->setText(QCoreApplication::translate("MainWindow", "POKER", nullptr));
        next->setText(QCoreApplication::translate("MainWindow", "Play Round", nullptr));
        swapCard->setText(QCoreApplication::translate("MainWindow", "Swap", nullptr));
        sortByGroup->setText(QCoreApplication::translate("MainWindow", "Sort by Group", nullptr));
        sortByValue->setText(QCoreApplication::translate("MainWindow", "Sort by Value", nullptr));
        Restart->setText(QCoreApplication::translate("MainWindow", "END", nullptr));
        swapsLeft->setText(QCoreApplication::translate("MainWindow", "SWAPS", nullptr));
        round->setText(QCoreApplication::translate("MainWindow", "ROUND", nullptr));
        roundCount_2->setText(QCoreApplication::translate("MainWindow", "FINAL SCORE", nullptr));
        winner->setText(QCoreApplication::translate("MainWindow", "FINAL SCORE", nullptr));
        playerScore->setText(QCoreApplication::translate("MainWindow", "FINAL SCORE", nullptr));
        cpuScore->setText(QCoreApplication::translate("MainWindow", "FINAL SCORE", nullptr));
        skip->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        roundCount->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        cpuScore_2->setText(QCoreApplication::translate("MainWindow", "CPU SCORE", nullptr));
        playerScore_2->setText(QCoreApplication::translate("MainWindow", "PLAYER SCORE", nullptr));
        roundInfo->setText(QCoreApplication::translate("MainWindow", "CPU SCORE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
