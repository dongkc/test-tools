#include "serialportui.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QStyleFactory>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.setStyle(QStyleFactory::create("fusion"));
	SerialPortUI w;
	w.show();
	return a.exec();

}
