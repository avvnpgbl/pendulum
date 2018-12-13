#include <thread>
using namespace std;

#include "GUI.h"
#include "Integrator.h"

extern volatile double x[];
int main(int argc, char *argv[])
{
	QApplication app(argc,argv);
	MainWindow wind(nullptr,x);

	thread intg(IntegratorThread,&wind.exit_flag, &wind.start_flag, &wind.stop_flag);

	wind.show();

	return app.exec();
}
