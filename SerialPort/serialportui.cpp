#include "serialportui.h"
#include <QtWidgets/QMessageBox>

#include "message.h"

using std::vector;
using std::string;

#define MAX_BUF_SIZE 1024

SerialPortUI::SerialPortUI(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//Get port names from device manager
	vector<string>&& serial_names = serialport_common_.GetDevice();
	for (int i = 0; i < serial_names.size(); ++i) {
		ui.comboBox->addItem(QString::fromStdString(serial_names[i]));
	}

	//connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(OpenPortSlot()));
	connect(&serialport_common_, SIGNAL(readFinished()), this, SLOT(PortReadFinished()));
}

void SerialPortUI::PortReadFinished() {
	QByteArray bytes = serialport_common_.GetRecvByte();
	serialport_common_.ClearRecvByte();

	char* recv_buf = bytes.data();
	qint64 len = bytes.length();

	std::string recv_str = Message::format(recv_buf, len);
	if (recv_str == "0A 01 30 00 DD EE") {
		QMessageBox::information(this, QString(QStringLiteral("提示")), QString(QStringLiteral("成功")));
	}
	else if (len == 17) {
		uint16_t value_0 = Message::GetCalibrationResult(recv_buf[3], recv_buf[4]);
		uint16_t value_1 = Message::GetCalibrationResult(recv_buf[5], recv_buf[6]);
		uint16_t value_2 = Message::GetCalibrationResult(recv_buf[7], recv_buf[8]);		
		uint16_t value_3 = Message::GetCalibrationResult(recv_buf[9], recv_buf[10]);
		uint16_t value_strength = Message::GetCalibrationResult(recv_buf[11], recv_buf[12]);	
		uint16_t value_AD = Message::GetCalibrationResult(recv_buf[13], recv_buf[14]);

		ui.lineEdit_0->setText(QString("%1").arg(value_0));
		ui.lineEdit_1->setText(QString("%1").arg(value_1));
		ui.lineEdit_2->setText(QString("%1").arg(value_2));
		ui.lineEdit_3->setText(QString("%1").arg(value_3));

		ui.label_AD->setText(QString("%1").arg(value_AD));
		ui.label_strength->setText(QString("%1").arg(value_strength));
	}
	else {
		QMessageBox::information(this, QString(QStringLiteral("提示")), QString(QStringLiteral("返回结果错误")));
	}
}


void SerialPortUI::on_pushButton_connect_clicked() {
	if (!serialport_common_.isOpen()) {
		if (OpenPort(ui.comboBox->currentText())) {
			ui.pushButton_connect->setText(QString(QStringLiteral("断开连接")));
		}
	}
	else {
		serialport_common_.close();
		ui.pushButton_connect->setText(QString(QStringLiteral("连接")));
	}
}

bool SerialPortUI::OpenPort(QString port_name) {
	if (!serialport_common_.open(port_name)) {
		QMessageBox::information(this, QString(QStringLiteral("提示")), QString(QStringLiteral("打开失败")));
		return false;
	}
	return true;
}

void SerialPortUI::on_pushButton_0_clicked() {
	if (!serialport_common_.isOpen()) {
		QMessageBox::information(this, QString(QStringLiteral("提示")), QString(QStringLiteral("串口未打开")));
		return;
	}

	unsigned char buf[MAX_BUF_SIZE];
	unsigned int len = sizeof(buf);
	memset(buf, MAX_BUF_SIZE, 0);
	char *begin = (char*)buf;

	if (ui.checkBox_0->checkState() == Qt::Unchecked) {
		Message::GetUnCheckedMessage(0, &buf[0], len);
	}
	else {
		uint16_t value = ui.lineEdit_0->text().toUInt();
		Message::GetCheckedMessage(0, value,&buf[0], len);
	}

	serialport_common_.writeData(begin, len);
}
void SerialPortUI::on_pushButton_1_clicked() {
	if (!serialport_common_.isOpen()) {
		QMessageBox::information(this, QString(QStringLiteral("提示")), QString(QStringLiteral("串口未打开")));
		return;
	}

	unsigned char buf[MAX_BUF_SIZE];
	unsigned int len = sizeof(buf);
	memset(buf, MAX_BUF_SIZE, 0);
	char *begin = (char*)buf;

	if (ui.checkBox_1->checkState() == Qt::Unchecked) {
		Message::GetUnCheckedMessage(1, &buf[0], len);
	}
	else {
		uint16_t value = ui.lineEdit_1->text().toUInt();
		Message::GetCheckedMessage(1, value,&buf[0], len);
	}

	serialport_common_.writeData(begin, len);
}
void SerialPortUI::on_pushButton_2_clicked() {
	if (!serialport_common_.isOpen()) {
		QMessageBox::information(this, QString(QStringLiteral("提示")), QString(QStringLiteral("串口未打开")));
		return;
	}

	unsigned char buf[MAX_BUF_SIZE];
	unsigned int len = sizeof(buf);
	memset(buf, MAX_BUF_SIZE, 0);
	char *begin = (char*)buf;

	if (ui.checkBox_2->checkState() == Qt::Unchecked) {
		Message::GetUnCheckedMessage(2, &buf[0], len);
	}
	else {
		uint16_t value = ui.lineEdit_2->text().toUInt();
		Message::GetCheckedMessage(2,value, &buf[0], len);
	}

	serialport_common_.writeData(begin, len);
}
void SerialPortUI::on_pushButton_3_clicked() {
	if (!serialport_common_.isOpen()) {
		QMessageBox::information(this, QString(QStringLiteral("提示")), QString(QStringLiteral("串口未打开")));
		return;
	}

	unsigned char buf[MAX_BUF_SIZE];
	unsigned int len = sizeof(buf);
	memset(buf, MAX_BUF_SIZE, 0);
	char *begin = (char*)buf;

	if (ui.checkBox_3->checkState() == Qt::Unchecked) {
		Message::GetUnCheckedMessage(2, &buf[0], len);
	}
	else {
		uint16_t value = ui.lineEdit_3->text().toUInt();
		Message::GetCheckedMessage(2,value, &buf[0], len);
	}

	serialport_common_.writeData(begin, len);
}

void SerialPortUI::on_pushButton_calibration_clicked() {
	if (!serialport_common_.isOpen()) {
		QMessageBox::information(this, QString(QStringLiteral("提示")), QString(QStringLiteral("串口未打开")));
		return;
	}

	unsigned char buf[MAX_BUF_SIZE];
	unsigned int len = sizeof(buf);
	memset(buf, MAX_BUF_SIZE, 0);
	char *begin = (char*)buf;
	Message::GetUnCheckedMessage(4, &buf[0], len);

	serialport_common_.writeData(begin, len);
}

SerialPortUI::~SerialPortUI()
{

}
