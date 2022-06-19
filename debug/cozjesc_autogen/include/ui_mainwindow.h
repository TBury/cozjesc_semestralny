/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *line;
    QStackedWidget *stackedWidget;
    QWidget *main;
    QLabel *label_4;
    QPushButton *viewAll_Button;
    QLabel *label_3;
    QPushButton *viewAll_Button_3;
    QLabel *label_5;
    QPushButton *viewAll_Button_2;
    QPushButton *viewAll_Button_4;
    QLabel *label_2;
    QWidget *page_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *page;
    QLabel *label_31;
    QLineEdit *recipeName;
    QPushButton *addIngredient;
    QPushButton *saveRecipe;
    QLabel *label_42;
    QLabel *label_43;
    QLineEdit *ingredient;
    QLabel *label_44;
    QLabel *addedIngredients;
    QLabel *label_45;
    QPlainTextEdit *recipe;
    QWidget *page_3;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QWidget *page_4;
    QLabel *label_32;
    QLabel *label_46;
    QWidget *central;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *filterButton;
    QLabel *label_33;
    QScrollArea *foundRecipesArea;
    QWidget *scrollAreaWidgetContents_3;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 50, 801, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 60, 801, 511));
        stackedWidget->setAutoFillBackground(false);
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: white;"));
        main = new QWidget();
        main->setObjectName(QString::fromUtf8("main"));
        label_4 = new QLabel(main);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(400, 405, 331, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Montserrat SemiBold")});
        font.setPointSize(14);
        font.setBold(true);
        label_4->setFont(font);
        viewAll_Button = new QPushButton(main);
        viewAll_Button->setObjectName(QString::fromUtf8("viewAll_Button"));
        viewAll_Button->setGeometry(QRect(90, 70, 231, 131));
        viewAll_Button->setLayoutDirection(Qt::LeftToRight);
        viewAll_Button->setAutoFillBackground(false);
        viewAll_Button->setStyleSheet(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/all.png"), QSize(), QIcon::Normal, QIcon::Off);
        viewAll_Button->setIcon(icon);
        viewAll_Button->setIconSize(QSize(100, 118));
        viewAll_Button->setFlat(true);
        label_3 = new QLabel(main);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(450, 205, 201, 31));
        label_3->setFont(font);
        viewAll_Button_3 = new QPushButton(main);
        viewAll_Button_3->setObjectName(QString::fromUtf8("viewAll_Button_3"));
        viewAll_Button_3->setGeometry(QRect(430, 270, 231, 131));
        viewAll_Button_3->setLayoutDirection(Qt::LeftToRight);
        viewAll_Button_3->setAutoFillBackground(false);
        viewAll_Button_3->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/generate.png"), QSize(), QIcon::Normal, QIcon::Off);
        viewAll_Button_3->setIcon(icon1);
        viewAll_Button_3->setIconSize(QSize(100, 118));
        viewAll_Button_3->setFlat(true);
        label_5 = new QLabel(main);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(130, 410, 141, 21));
        label_5->setFont(font);
        viewAll_Button_2 = new QPushButton(main);
        viewAll_Button_2->setObjectName(QString::fromUtf8("viewAll_Button_2"));
        viewAll_Button_2->setGeometry(QRect(430, 70, 231, 131));
        viewAll_Button_2->setLayoutDirection(Qt::LeftToRight);
        viewAll_Button_2->setAutoFillBackground(false);
        viewAll_Button_2->setStyleSheet(QString::fromUtf8(""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        viewAll_Button_2->setIcon(icon2);
        viewAll_Button_2->setIconSize(QSize(100, 118));
        viewAll_Button_2->setFlat(true);
        viewAll_Button_4 = new QPushButton(main);
        viewAll_Button_4->setObjectName(QString::fromUtf8("viewAll_Button_4"));
        viewAll_Button_4->setGeometry(QRect(90, 270, 231, 131));
        viewAll_Button_4->setLayoutDirection(Qt::LeftToRight);
        viewAll_Button_4->setAutoFillBackground(false);
        viewAll_Button_4->setStyleSheet(QString::fromUtf8(""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        viewAll_Button_4->setIcon(icon3);
        viewAll_Button_4->setIconSize(QSize(100, 118));
        viewAll_Button_4->setFlat(true);
        label_2 = new QLabel(main);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 210, 281, 21));
        label_2->setFont(font);
        stackedWidget->addWidget(main);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        scrollArea = new QScrollArea(page_2);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 801, 491));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 799, 489));
        scrollArea->setWidget(scrollAreaWidgetContents);
        stackedWidget->addWidget(page_2);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        label_31 = new QLabel(page);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(30, 20, 221, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Montserrat SemiBold")});
        font1.setPointSize(16);
        font1.setBold(true);
        label_31->setFont(font1);
        recipeName = new QLineEdit(page);
        recipeName->setObjectName(QString::fromUtf8("recipeName"));
        recipeName->setGeometry(QRect(30, 90, 491, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Montserrat Medium")});
        recipeName->setFont(font2);
        addIngredient = new QPushButton(page);
        addIngredient->setObjectName(QString::fromUtf8("addIngredient"));
        addIngredient->setGeometry(QRect(280, 170, 131, 31));
        saveRecipe = new QPushButton(page);
        saveRecipe->setObjectName(QString::fromUtf8("saveRecipe"));
        saveRecipe->setGeometry(QRect(620, 460, 141, 24));
        label_42 = new QLabel(page);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setGeometry(QRect(30, 60, 101, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Montserrat Light")});
        font3.setPointSize(9);
        font3.setBold(false);
        label_42->setFont(font3);
        label_43 = new QLabel(page);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setGeometry(QRect(30, 140, 101, 31));
        label_43->setFont(font3);
        ingredient = new QLineEdit(page);
        ingredient->setObjectName(QString::fromUtf8("ingredient"));
        ingredient->setGeometry(QRect(30, 170, 241, 31));
        ingredient->setFont(font2);
        label_44 = new QLabel(page);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setGeometry(QRect(30, 210, 101, 31));
        label_44->setFont(font3);
        addedIngredients = new QLabel(page);
        addedIngredients->setObjectName(QString::fromUtf8("addedIngredients"));
        addedIngredients->setGeometry(QRect(30, 250, 741, 31));
        addedIngredients->setFont(font3);
        label_45 = new QLabel(page);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setGeometry(QRect(30, 300, 101, 31));
        label_45->setFont(font3);
        recipe = new QPlainTextEdit(page);
        recipe->setObjectName(QString::fromUtf8("recipe"));
        recipe->setGeometry(QRect(20, 340, 751, 101));
        stackedWidget->addWidget(page);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        scrollArea_2 = new QScrollArea(page_3);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(0, 0, 801, 491));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 799, 489));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        label_32 = new QLabel(page_4);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(30, 10, 221, 31));
        label_32->setFont(font1);
        label_46 = new QLabel(page_4);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setGeometry(QRect(30, 60, 61, 21));
        label_46->setFont(font3);
        central = new QWidget(page_4);
        central->setObjectName(QString::fromUtf8("central"));
        central->setGeometry(QRect(30, 90, 621, 81));
        gridLayoutWidget = new QWidget(central);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 621, 81));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        filterButton = new QPushButton(page_4);
        filterButton->setObjectName(QString::fromUtf8("filterButton"));
        filterButton->setGeometry(QRect(540, 180, 111, 24));
        label_33 = new QLabel(page_4);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(30, 240, 151, 31));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Montserrat SemiBold")});
        font4.setPointSize(11);
        font4.setBold(true);
        label_33->setFont(font4);
        foundRecipesArea = new QScrollArea(page_4);
        foundRecipesArea->setObjectName(QString::fromUtf8("foundRecipesArea"));
        foundRecipesArea->setGeometry(QRect(0, 280, 801, 211));
        foundRecipesArea->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 799, 209));
        foundRecipesArea->setWidget(scrollAreaWidgetContents_3);
        stackedWidget->addWidget(page_4);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 10, 131, 31));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/logo.png")));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "co zje\305\233\304\207? Aplikacja", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "wygeneruj przepis ze sk\305\202adnik\303\263w", nullptr));
        viewAll_Button->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "dodaj nowy przepis", nullptr));
        viewAll_Button_3->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "usu\305\204 przepisy", nullptr));
        viewAll_Button_2->setText(QString());
        viewAll_Button_4->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "wy\305\233wietl wszystkie przepisy", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "Dodaj nowy przepis", nullptr));
        addIngredient->setText(QCoreApplication::translate("MainWindow", "Dodaj sk\305\202adnik", nullptr));
        saveRecipe->setText(QCoreApplication::translate("MainWindow", "Zapisz przepis", nullptr));
        label_42->setText(QCoreApplication::translate("MainWindow", "Nazwa przepisu", nullptr));
        label_43->setText(QCoreApplication::translate("MainWindow", "Sk\305\202adniki", nullptr));
        label_44->setText(QCoreApplication::translate("MainWindow", "Dodane sk\305\202adniki:", nullptr));
        addedIngredients->setText(QString());
        label_45->setText(QCoreApplication::translate("MainWindow", "Przepis", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "Znajd\305\272 sw\303\263j przepis", nullptr));
        label_46->setText(QCoreApplication::translate("MainWindow", "Sk\305\202adniki", nullptr));
        filterButton->setText(QCoreApplication::translate("MainWindow", "Filtruj", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "Znalezione przepisy", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
