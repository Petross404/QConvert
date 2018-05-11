#include "qconvert.h"
#include <QApplication>

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	QConvert w;
	w.show();

	return app.exec();
}

