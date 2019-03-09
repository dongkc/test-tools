#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QtWidgets/QWidget>
#include "ui_serialport.h"
#include "SerialPortCommon.h"

class SerialPortUI : public QWidget
{
	Q_OBJECT

public:
	SerialPortUI(QWidget *parent = 0);
	~SerialPortUI();

	bool OpenPort(QString port_name);

public slots:
	//void OpenPortSlot();

	void on_pushButton_connect_clicked();
	void on_pushButton_0_clicked();
	void on_pushButton_1_clicked();
	void on_pushButton_2_clicked();
	void on_pushButton_3_clicked();

	void on_pushButton_calibration_clicked();

	void PortReadFinished();

private:
	Ui::SerialPortClass ui;
	SerialPortCommon serialport_common_;
};

#endif // SERIALPORT_H
