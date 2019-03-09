#pragma once
#include <string>
#include <vector>

#include <QtCore/QObject>
#include <QtSerialPort/QtSerialPort>
#include <QtSerialPort/QSerialPortInfo>

 class SerialPortCommon : public QObject
 {
 	Q_OBJECT
 public:
 	explicit SerialPortCommon(QObject* parent = nullptr);
 	virtual ~SerialPortCommon()
 	{
		if (m_serialPort != nullptr)
		{
			if (m_serialPort->isOpen())
			{
				m_serialPort->close();
			}
			m_serialPort = nullptr;
		}
		
 	}
 
	std::vector<std::string> GetDevice();
	QByteArray GetRecvByte() {
		return m_comReceBuf;
	}
	void ClearRecvByte() {
		m_comReceBuf.clear();
	}


 	bool isOpen() const
 	{
 		return m_serialPort->isOpen();
 	}
 	void setPortName(const QString &name)
 	{
 		m_portName = name;
 	}
 	QString portName()const
 	{
 		return m_portName;
 	}
 	
 	void setBaudRate(int baudRate)
 	{
 		m_baudRate = baudRate;
 	}
 	int baudRate() const
 	{
 		return m_baudRate;
 	}
 
 	virtual bool open(QString port_name);
 	virtual void close();
 	virtual bool clear();
 
	bool open();

 	int readData();
 	int writeData(char* data, int size);
 

 signals:
 	void readFinished();
	void beginRead();

 public slots:
 	void on_readCom();
 protected:
 	QString m_portName;
 	int m_baudRate;
 	QSerialPort *m_serialPort;
	QSerialPortInfo m_comInfo;
	QByteArray m_comReceBuf;
 };
