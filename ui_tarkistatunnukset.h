/********************************************************************************
** Form generated from reading UI file 'tarkistatunnukset.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TARKISTATUNNUKSET_H
#define UI_TARKISTATUNNUKSET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tarkistaTunnukset
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *tunnusLaatikko;
    QLabel *label_3;
    QLineEdit *salasanaLaatikko;
    QPushButton *pushButton;

    void setupUi(QDialog *tarkistaTunnukset)
    {
        if (tarkistaTunnukset->objectName().isEmpty())
            tarkistaTunnukset->setObjectName(QStringLiteral("tarkistaTunnukset"));
        tarkistaTunnukset->resize(500, 500);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tarkistaTunnukset->sizePolicy().hasHeightForWidth());
        tarkistaTunnukset->setSizePolicy(sizePolicy);
        tarkistaTunnukset->setMinimumSize(QSize(500, 500));
        tarkistaTunnukset->setMaximumSize(QSize(500, 500));
        QIcon icon;
        icon.addFile(QStringLiteral("resurssit/karsamakivaakuna.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        tarkistaTunnukset->setWindowIcon(icon);
        tarkistaTunnukset->setStyleSheet(QStringLiteral(""));
        widget = new QWidget(tarkistaTunnukset);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(141, 121, 165, 92));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Tahoma"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font1;
        font1.setFamily(QStringLiteral("Tahoma"));
        font1.setPointSize(8);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        tunnusLaatikko = new QLineEdit(widget);
        tunnusLaatikko->setObjectName(QStringLiteral("tunnusLaatikko"));
        tunnusLaatikko->setStyleSheet(QLatin1String("QLineEdit {\n"
"border-radius: 5px;\n"
"}\n"
""));

        gridLayout->addWidget(tunnusLaatikko, 1, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        salasanaLaatikko = new QLineEdit(widget);
        salasanaLaatikko->setObjectName(QStringLiteral("salasanaLaatikko"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(11);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(salasanaLaatikko->sizePolicy().hasHeightForWidth());
        salasanaLaatikko->setSizePolicy(sizePolicy1);
        salasanaLaatikko->setStyleSheet(QLatin1String("QLineEdit {\n"
"border-radius: 5px\n"
"\n"
"}"));
        salasanaLaatikko->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(salasanaLaatikko, 2, 1, 1, 1);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QLatin1String("QPushButton {\n"
"\n"
"}\n"
""));

        gridLayout->addWidget(pushButton, 3, 1, 1, 1);


        retranslateUi(tarkistaTunnukset);

        QMetaObject::connectSlotsByName(tarkistaTunnukset);
    } // setupUi

    void retranslateUi(QDialog *tarkistaTunnukset)
    {
        tarkistaTunnukset->setWindowTitle(QApplication::translate("tarkistaTunnukset", "Sis\303\244\303\244nkirjautuminen", Q_NULLPTR));
        label->setText(QApplication::translate("tarkistaTunnukset", "Kirjaudu", Q_NULLPTR));
        label_2->setText(QApplication::translate("tarkistaTunnukset", "Tunnus", Q_NULLPTR));
        label_3->setText(QApplication::translate("tarkistaTunnukset", "Salasana", Q_NULLPTR));
        pushButton->setText(QApplication::translate("tarkistaTunnukset", "Sis\303\244\303\244n", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class tarkistaTunnukset: public Ui_tarkistaTunnukset {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TARKISTATUNNUKSET_H