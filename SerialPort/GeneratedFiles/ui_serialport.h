/********************************************************************************
** Form generated from reading UI file 'serialport.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALPORT_H
#define UI_SERIALPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SerialPortClass
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QComboBox *comboBox;
    QPushButton *pushButton_connect;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_0;
    QCheckBox *checkBox_0;
    QPushButton *pushButton_0;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_1;
    QCheckBox *checkBox_1;
    QPushButton *pushButton_1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QCheckBox *checkBox_2;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QCheckBox *checkBox_3;
    QPushButton *pushButton_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QLabel *label_AD;
    QLabel *label_7;
    QLabel *label_strength;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_calibration;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;

    void setupUi(QWidget *SerialPortClass)
    {
        if (SerialPortClass->objectName().isEmpty())
            SerialPortClass->setObjectName(QStringLiteral("SerialPortClass"));
        SerialPortClass->resize(432, 360);
        verticalLayout = new QVBoxLayout(SerialPortClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        comboBox = new QComboBox(SerialPortClass);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_6->addWidget(comboBox);

        pushButton_connect = new QPushButton(SerialPortClass);
        pushButton_connect->setObjectName(QStringLiteral("pushButton_connect"));

        horizontalLayout_6->addWidget(pushButton_connect);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(SerialPortClass);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit_0 = new QLineEdit(SerialPortClass);
        lineEdit_0->setObjectName(QStringLiteral("lineEdit_0"));

        horizontalLayout->addWidget(lineEdit_0);

        checkBox_0 = new QCheckBox(SerialPortClass);
        checkBox_0->setObjectName(QStringLiteral("checkBox_0"));

        horizontalLayout->addWidget(checkBox_0);

        pushButton_0 = new QPushButton(SerialPortClass);
        pushButton_0->setObjectName(QStringLiteral("pushButton_0"));

        horizontalLayout->addWidget(pushButton_0);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(SerialPortClass);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_1 = new QLineEdit(SerialPortClass);
        lineEdit_1->setObjectName(QStringLiteral("lineEdit_1"));

        horizontalLayout_2->addWidget(lineEdit_1);

        checkBox_1 = new QCheckBox(SerialPortClass);
        checkBox_1->setObjectName(QStringLiteral("checkBox_1"));

        horizontalLayout_2->addWidget(checkBox_1);

        pushButton_1 = new QPushButton(SerialPortClass);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));

        horizontalLayout_2->addWidget(pushButton_1);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(SerialPortClass);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_2 = new QLineEdit(SerialPortClass);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout_3->addWidget(lineEdit_2);

        checkBox_2 = new QCheckBox(SerialPortClass);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        horizontalLayout_3->addWidget(checkBox_2);

        pushButton_2 = new QPushButton(SerialPortClass);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_3->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(SerialPortClass);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEdit_3 = new QLineEdit(SerialPortClass);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        horizontalLayout_4->addWidget(lineEdit_3);

        checkBox_3 = new QCheckBox(SerialPortClass);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));

        horizontalLayout_4->addWidget(checkBox_3);

        pushButton_3 = new QPushButton(SerialPortClass);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_4->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_5 = new QLabel(SerialPortClass);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_7->addWidget(label_5);

        label_AD = new QLabel(SerialPortClass);
        label_AD->setObjectName(QStringLiteral("label_AD"));
        label_AD->setMinimumSize(QSize(155, 20));
        label_AD->setMaximumSize(QSize(16777215, 20));
        label_AD->setFrameShape(QFrame::Box);

        horizontalLayout_7->addWidget(label_AD);

        label_7 = new QLabel(SerialPortClass);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_7->addWidget(label_7);

        label_strength = new QLabel(SerialPortClass);
        label_strength->setObjectName(QStringLiteral("label_strength"));
        label_strength->setMinimumSize(QSize(155, 20));
        label_strength->setMaximumSize(QSize(16777215, 20));
        label_strength->setFrameShape(QFrame::Box);

        horizontalLayout_7->addWidget(label_strength);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButton_calibration = new QPushButton(SerialPortClass);
        pushButton_calibration->setObjectName(QStringLiteral("pushButton_calibration"));

        horizontalLayout_5->addWidget(pushButton_calibration);

        pushButton_7 = new QPushButton(SerialPortClass);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        horizontalLayout_5->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(SerialPortClass);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        horizontalLayout_5->addWidget(pushButton_8);

        pushButton_9 = new QPushButton(SerialPortClass);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));

        horizontalLayout_5->addWidget(pushButton_9);


        verticalLayout->addLayout(horizontalLayout_5);


        retranslateUi(SerialPortClass);

        QMetaObject::connectSlotsByName(SerialPortClass);
    } // setupUi

    void retranslateUi(QWidget *SerialPortClass)
    {
        SerialPortClass->setWindowTitle(QApplication::translate("SerialPortClass", "SerialPort", Q_NULLPTR));
        pushButton_connect->setText(QApplication::translate("SerialPortClass", "\350\277\236\346\216\245", Q_NULLPTR));
        label->setText(QApplication::translate("SerialPortClass", "\345\275\222\351\233\266\345\200\274\357\274\232", Q_NULLPTR));
        checkBox_0->setText(QString());
        pushButton_0->setText(QApplication::translate("SerialPortClass", "\345\275\222\351\233\266", Q_NULLPTR));
        label_2->setText(QApplication::translate("SerialPortClass", "\346\240\207\345\256\2321\357\274\232", Q_NULLPTR));
        checkBox_1->setText(QString());
        pushButton_1->setText(QApplication::translate("SerialPortClass", "\346\240\207\345\256\2321", Q_NULLPTR));
        label_3->setText(QApplication::translate("SerialPortClass", "\346\240\207\345\256\2322\357\274\232", Q_NULLPTR));
        checkBox_2->setText(QString());
        pushButton_2->setText(QApplication::translate("SerialPortClass", "\346\240\207\345\256\2322", Q_NULLPTR));
        label_4->setText(QApplication::translate("SerialPortClass", "\346\240\207\345\256\2323\357\274\232", Q_NULLPTR));
        checkBox_3->setText(QString());
        pushButton_3->setText(QApplication::translate("SerialPortClass", "\346\240\207\345\256\2323", Q_NULLPTR));
        label_5->setText(QApplication::translate("SerialPortClass", "AD\345\200\274\357\274\232", Q_NULLPTR));
        label_AD->setText(QString());
        label_7->setText(QApplication::translate("SerialPortClass", "\345\212\233\345\200\274\357\274\232", Q_NULLPTR));
        label_strength->setText(QString());
        pushButton_calibration->setText(QApplication::translate("SerialPortClass", "\350\257\273\345\217\226\346\240\207\345\256\232\345\200\274", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("SerialPortClass", "\350\277\233\345\205\245\350\277\220\350\241\214\346\250\241\345\274\217", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("SerialPortClass", "\350\277\233\345\205\245\350\256\276\345\256\232\346\250\241\345\274\217", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("SerialPortClass", "\346\265\213\350\257\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SerialPortClass: public Ui_SerialPortClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALPORT_H
