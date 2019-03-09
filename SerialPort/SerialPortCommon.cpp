#include "SerialPortCommon.h"
#include <QtSerialPort/QSerialPortInfo>

#define MAX_BUF_SIZE 1024

SerialPortCommon::SerialPortCommon(QObject *parent) : QObject(parent)
{
	m_serialPort = new QSerialPort();
	m_baudRate = 115200;
//	initDevice();
//	m_portName = "com3";
	
	connect(m_serialPort, SIGNAL(readyRead()), this, SLOT(on_readCom()));
//	connect(m_serialPort, SIGNAL(readyRead()), this, SIGNAL(beginRead()));
}

std::vector<std::string> SerialPortCommon::GetDevice()
{
	std::vector<std::string> portname_vec;
	foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
	{
		portname_vec.push_back(info.portName().toStdString());
		qDebug() << "Name : " << info.portName();
		qDebug() << "Description : " << info.description();
		qDebug() << "Manufacturer: " << info.manufacturer();
		qDebug() << "Serial Number: " << info.serialNumber();
		qDebug() << "System Location: " << info.systemLocation();
	}
	return portname_vec;
}
// void SerialPortCommon::timerUpdate_Com()
// {
// 	emit readFinished();
// }
void SerialPortCommon::on_readCom()
{
	readData();
	emit readFinished();
}
static QSerialPort::BaudRate getBaudRate(int baudRate)
{
	switch (baudRate)
	{
	case 1200:
		return QSerialPort::Baud1200;
	case 2400:
		return QSerialPort::Baud2400;
	case 4800:
		return QSerialPort::Baud4800;
	case 9600:
		return QSerialPort::Baud9600;
	case 19200:
		return QSerialPort::Baud19200;
	case 38400:
		return QSerialPort::Baud38400;
	case 57600:
		return QSerialPort::Baud57600;
	case 115200:
		return QSerialPort::Baud115200;
	default:
		return QSerialPort::UnknownBaud;
	}
}

bool SerialPortCommon::open(QString port_name)
{
	m_portName = port_name;
	m_serialPort->setPortName(port_name);
	m_serialPort->setBaudRate(getBaudRate(m_baudRate));
	m_serialPort->setParity(QSerialPort::NoParity);
	m_serialPort->setDataBits(QSerialPort::Data8);
	m_serialPort->setStopBits(QSerialPort::OneStop);
	m_serialPort->setFlowControl(QSerialPort::NoFlowControl);
	m_serialPort->setReadBufferSize(1024);
	return m_serialPort->open(QSerialPort::ReadWrite);
}

bool SerialPortCommon::open() {
	m_serialPort->setPortName(m_portName);
	m_serialPort->setBaudRate(getBaudRate(m_baudRate));
	m_serialPort->setParity(QSerialPort::NoParity);
	m_serialPort->setDataBits(QSerialPort::Data8);
	m_serialPort->setStopBits(QSerialPort::OneStop);
	m_serialPort->setFlowControl(QSerialPort::NoFlowControl);
	m_serialPort->setReadBufferSize(1024);
	return m_serialPort->open(QSerialPort::ReadWrite);
}

void SerialPortCommon::close()
{
	if (m_serialPort->isOpen())
	{
		m_serialPort->close();
	}
}

bool SerialPortCommon::clear()
{
	if (m_serialPort->isOpen())
	{
		m_serialPort->clear();
		this->close();
		return this->open();
	}
	return false;
}

int SerialPortCommon::readData()
{
	m_comReceBuf.append(m_serialPort->readAll());
	return 0;
}

int SerialPortCommon::writeData(char *data, int size)
{
	int len = 0;
	forever
	{
		int n = m_serialPort->write(&data[len], size - len);
		if (n == -1)
		{
			return -1;
		}
		else
		{
			len += n;
			if (size == len)
				break;
		}
	}
	
	return len;
}