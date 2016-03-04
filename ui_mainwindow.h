/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionAboutQt;
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionConfigure;
    QAction *actionClear;
    QAction *actionQuit;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_6;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *verticalSpacer_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *STARTBT;
    QPushButton *pushButton_13;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QFormLayout *formLayout;
    QLabel *labelNumberR;
    QLabel *NumberOfRobotics_label;
    QLabel *labelNumberR_2;
    QLabel *NumberOfRobotics_label_2;
    QListWidget *listWidget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_15;
    QPushButton *save_bt;
    QPushButton *del_bt;
    QPushButton *cleartrain_bt;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *labelNumberR_3;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *lineEdit;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;
    QMenuBar *menuBar;
    QMenu *menuCalls;
    QMenu *menuTools;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/six-axis-robot.gif"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setWindowOpacity(1);
        MainWindow->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionAboutQt = new QAction(MainWindow);
        actionAboutQt->setObjectName(QStringLiteral("actionAboutQt"));
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnect->setIcon(icon1);
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName(QStringLiteral("actionDisconnect"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/disconnect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDisconnect->setIcon(icon2);
        actionConfigure = new QAction(MainWindow);
        actionConfigure->setObjectName(QStringLiteral("actionConfigure"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConfigure->setIcon(icon3);
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear->setIcon(icon4);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/application-exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon5);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMaximumSize(QSize(16777215, 40));

        gridLayout_2->addWidget(pushButton_3, 0, 0, 1, 1);

        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setMaximumSize(QSize(16777215, 40));

        gridLayout_2->addWidget(pushButton_7, 4, 0, 1, 1);

        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setMaximumSize(QSize(16777215, 40));

        gridLayout_2->addWidget(pushButton_8, 5, 0, 1, 1);

        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setMaximumSize(QSize(16777215, 40));

        gridLayout_2->addWidget(pushButton_6, 3, 0, 1, 1);

        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMaximumSize(QSize(16777215, 40));

        gridLayout_2->addWidget(pushButton_4, 1, 0, 1, 1);

        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setMaximumSize(QSize(16777215, 40));

        gridLayout_2->addWidget(pushButton_5, 2, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 6, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 6, 2, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 15, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(verticalSpacer_4);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(100, 30));

        horizontalLayout_3->addWidget(pushButton);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(100, 30));

        horizontalLayout_3->addWidget(pushButton_2);


        gridLayout->addLayout(horizontalLayout_3, 10, 0, 1, 1);

        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setMinimumSize(QSize(300, 0));

        gridLayout->addWidget(listWidget, 6, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        STARTBT = new QPushButton(centralWidget);
        STARTBT->setObjectName(QStringLiteral("STARTBT"));
        STARTBT->setMinimumSize(QSize(150, 60));
        STARTBT->setMaximumSize(QSize(16777215, 100));

        verticalLayout_2->addWidget(STARTBT);

        pushButton_13 = new QPushButton(centralWidget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setMinimumSize(QSize(0, 50));

        verticalLayout_2->addWidget(pushButton_13);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        gridLayout->addLayout(verticalLayout_2, 6, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        labelNumberR = new QLabel(centralWidget);
        labelNumberR->setObjectName(QStringLiteral("labelNumberR"));
        labelNumberR->setMinimumSize(QSize(110, 20));
        labelNumberR->setMaximumSize(QSize(110, 20));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelNumberR);

        NumberOfRobotics_label = new QLabel(centralWidget);
        NumberOfRobotics_label->setObjectName(QStringLiteral("NumberOfRobotics_label"));
        NumberOfRobotics_label->setMinimumSize(QSize(40, 20));

        formLayout->setWidget(0, QFormLayout::FieldRole, NumberOfRobotics_label);

        labelNumberR_2 = new QLabel(centralWidget);
        labelNumberR_2->setObjectName(QStringLiteral("labelNumberR_2"));
        labelNumberR_2->setMinimumSize(QSize(110, 20));
        labelNumberR_2->setMaximumSize(QSize(110, 20));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelNumberR_2);

        NumberOfRobotics_label_2 = new QLabel(centralWidget);
        NumberOfRobotics_label_2->setObjectName(QStringLiteral("NumberOfRobotics_label_2"));
        NumberOfRobotics_label_2->setMinimumSize(QSize(50, 20));

        formLayout->setWidget(1, QFormLayout::FieldRole, NumberOfRobotics_label_2);


        horizontalLayout_4->addLayout(formLayout);


        gridLayout->addLayout(horizontalLayout_4, 3, 0, 1, 1);

        listWidget_2 = new QListWidget(centralWidget);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));

        gridLayout->addWidget(listWidget_2, 6, 3, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_15 = new QPushButton(centralWidget);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));

        horizontalLayout->addWidget(pushButton_15);

        save_bt = new QPushButton(centralWidget);
        save_bt->setObjectName(QStringLiteral("save_bt"));

        horizontalLayout->addWidget(save_bt);

        del_bt = new QPushButton(centralWidget);
        del_bt->setObjectName(QStringLiteral("del_bt"));

        horizontalLayout->addWidget(del_bt);

        cleartrain_bt = new QPushButton(centralWidget);
        cleartrain_bt->setObjectName(QStringLiteral("cleartrain_bt"));

        horizontalLayout->addWidget(cleartrain_bt);


        gridLayout->addLayout(horizontalLayout, 10, 3, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        labelNumberR_3 = new QLabel(centralWidget);
        labelNumberR_3->setObjectName(QStringLiteral("labelNumberR_3"));
        labelNumberR_3->setMinimumSize(QSize(110, 20));
        labelNumberR_3->setMaximumSize(QSize(110, 20));

        horizontalLayout_7->addWidget(labelNumberR_3);

        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout_7->addWidget(lineEdit_2);


        gridLayout_4->addLayout(horizontalLayout_7, 0, 0, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_4);


        gridLayout->addLayout(horizontalLayout_2, 3, 3, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout_5->addWidget(label_3);


        gridLayout->addLayout(horizontalLayout_5, 1, 3, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));

        gridLayout->addLayout(horizontalLayout_6, 15, 3, 1, 1);


        verticalLayout->addLayout(gridLayout);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 20));
        menuCalls = new QMenu(menuBar);
        menuCalls->setObjectName(QStringLiteral("menuCalls"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);

        mainToolBar->addAction(actionConnect);
        mainToolBar->addAction(actionDisconnect);
        mainToolBar->addAction(actionConfigure);
        mainToolBar->addAction(actionClear);
        menuBar->addAction(menuCalls->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuCalls->addAction(actionConnect);
        menuCalls->addAction(actionDisconnect);
        menuCalls->addSeparator();
        menuCalls->addAction(actionQuit);
        menuTools->addAction(actionConfigure);
        menuTools->addAction(actionClear);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionAboutQt);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\340\270\212\340\270\270\340\270\224\340\271\202\340\270\233\340\270\243\340\271\201\340\270\201\340\270\243\340\270\241\340\270\204\340\270\247\340\270\232\340\270\204\340\270\270\340\270\241 \340\270\253\340\270\270\340\271\210\340\270\231\340\270\242\340\270\231\340\270\225\340\271\214\340\270\255\340\270\270\340\270\225\340\270\252\340\270\262\340\270\253\340\270\201\340\270\243\340\270\243\340\270\241\340\271\200\340\270\236\340\270\267\340\271\210\340\270\255\340\270\230\340\270\270\340\270\243\340\270\201\340\270\264\340\270\210 SME", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "&About", 0));
#ifndef QT_NO_TOOLTIP
        actionAbout->setToolTip(QApplication::translate("MainWindow", "About program", 0));
#endif // QT_NO_TOOLTIP
        actionAbout->setShortcut(QApplication::translate("MainWindow", "Alt+A", 0));
        actionAboutQt->setText(QApplication::translate("MainWindow", "About Qt", 0));
        actionConnect->setText(QApplication::translate("MainWindow", "C&onnect", 0));
#ifndef QT_NO_TOOLTIP
        actionConnect->setToolTip(QApplication::translate("MainWindow", "Connect to serial port", 0));
#endif // QT_NO_TOOLTIP
        actionConnect->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionDisconnect->setText(QApplication::translate("MainWindow", "&Disconnect", 0));
#ifndef QT_NO_TOOLTIP
        actionDisconnect->setToolTip(QApplication::translate("MainWindow", "Disconnect from serial port", 0));
#endif // QT_NO_TOOLTIP
        actionDisconnect->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", 0));
        actionConfigure->setText(QApplication::translate("MainWindow", "&Configure", 0));
#ifndef QT_NO_TOOLTIP
        actionConfigure->setToolTip(QApplication::translate("MainWindow", "Configure serial port", 0));
#endif // QT_NO_TOOLTIP
        actionConfigure->setShortcut(QApplication::translate("MainWindow", "Alt+C", 0));
        actionClear->setText(QApplication::translate("MainWindow", "C&lear", 0));
#ifndef QT_NO_TOOLTIP
        actionClear->setToolTip(QApplication::translate("MainWindow", "Clear data", 0));
#endif // QT_NO_TOOLTIP
        actionClear->setShortcut(QApplication::translate("MainWindow", "Alt+L", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "&Quit", 0));
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "\340\270\204\340\270\247\340\270\232\340\270\204\340\270\270\340\270\241\340\270\202\340\271\211\340\270\255\340\270\225\340\271\210\340\270\255 1", 0));
        pushButton_7->setText(QApplication::translate("MainWindow", "\340\270\204\340\270\247\340\270\232\340\270\204\340\270\270\340\270\241\340\270\202\340\271\211\340\270\255\340\270\225\340\271\210\340\270\255 5", 0));
        pushButton_8->setText(QApplication::translate("MainWindow", "\340\270\204\340\270\247\340\270\232\340\270\204\340\270\270\340\270\241\340\270\202\340\271\211\340\270\255\340\270\225\340\271\210\340\270\255 6", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "\340\270\204\340\270\247\340\270\232\340\270\204\340\270\270\340\270\241\340\270\202\340\271\211\340\270\255\340\270\225\340\271\210\340\270\255 4", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "\340\270\204\340\270\247\340\270\232\340\270\204\340\270\270\340\270\241\340\270\202\340\271\211\340\270\255\340\270\225\340\271\210\340\270\255 2", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "\340\270\204\340\270\247\340\270\232\340\270\204\340\270\270\340\270\241\340\270\202\340\271\211\340\270\255\340\270\225\340\271\210\340\270\255 3", 0));
        label_2->setText(QApplication::translate("MainWindow", "\340\270\212\340\270\270\340\270\224\340\270\204\340\270\263\340\270\252\340\270\261\340\271\210\340\270\207\340\270\253\340\270\270\340\271\210\340\270\231\340\270\242\340\270\231\340\270\225\340\271\214\340\271\202\340\270\253\340\270\241\340\270\224\340\270\227\340\270\263\340\270\207\340\270\262\340\270\231\340\270\255\340\270\261\340\270\225\340\271\202\340\270\231\340\270\241\340\270\261\340\270\225\340\270\264", 0));
        label->setText(QApplication::translate("MainWindow", "\340\270\233\340\271\211\340\270\255\340\270\231\340\270\204\340\270\263\340\270\252\340\270\261\340\271\210\340\270\207\340\270\253\340\270\270\340\271\210\340\270\231\340\270\242\340\270\231\340\270\225\340\271\214", 0));
        pushButton->setText(QApplication::translate("MainWindow", "\340\270\255\340\270\261\340\270\236\340\271\202\340\270\253\340\270\245\340\270\224", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "\340\271\200\340\270\204\340\270\245\340\270\265\340\270\242\340\270\243\340\271\214", 0));
        STARTBT->setText(QApplication::translate("MainWindow", "\340\271\200\340\270\243\340\270\264\340\271\210\340\270\241\340\270\201\340\270\262\340\270\243\340\270\227\340\270\263\340\270\207\340\270\262\340\270\231", 0));
        pushButton_13->setText(QApplication::translate("MainWindow", "Return to home", 0));
        labelNumberR->setText(QApplication::translate("MainWindow", "\340\270\210\340\270\263\340\270\231\340\270\247\340\270\231\340\270\212\340\270\270\340\270\224\340\270\204\340\270\263\340\270\252\340\270\261\340\271\210\340\270\207 : ", 0));
        NumberOfRobotics_label->setText(QApplication::translate("MainWindow", "0", 0));
        labelNumberR_2->setText(QApplication::translate("MainWindow", "\340\270\204\340\270\263\340\270\252\340\270\261\340\271\210\340\270\207\340\270\245\340\270\263\340\270\224\340\270\261\340\270\232\340\270\227\340\270\265\340\271\210", 0));
        NumberOfRobotics_label_2->setText(QApplication::translate("MainWindow", "0", 0));
        pushButton_15->setText(QApplication::translate("MainWindow", "\340\270\210\340\270\224\340\270\210\340\270\263\340\270\225\340\270\263\340\271\201\340\270\253\340\270\231\340\271\210\340\270\207\340\270\233\340\270\261\340\270\210\340\270\210\340\270\270\340\270\232\340\270\261\340\270\231", 0));
        save_bt->setText(QApplication::translate("MainWindow", "\340\270\232\340\270\261\340\270\231\340\270\227\340\270\266\340\270\201", 0));
        del_bt->setText(QApplication::translate("MainWindow", "\340\270\245\340\270\232\340\270\204\340\270\263\340\270\252\340\270\261\340\271\210\340\270\207", 0));
        cleartrain_bt->setText(QApplication::translate("MainWindow", "\340\271\200\340\270\204\340\270\245\340\270\265\340\270\242\340\270\243\340\271\214", 0));
        labelNumberR_3->setText(QApplication::translate("MainWindow", "\340\271\200\340\270\236\340\270\264\340\271\210\340\270\241\340\270\204\340\270\263\340\270\252\340\270\261\340\271\210\340\270\207 : ", 0));
        label_3->setText(QApplication::translate("MainWindow", "\340\270\201\340\270\262\340\270\243\340\270\252\340\270\255\340\270\231\340\270\253\340\270\270\340\271\210\340\270\231\340\270\242\340\270\231\340\270\225\340\271\214", 0));
        menuCalls->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
