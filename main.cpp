/****************************************************************
 *  file manager                                                *
 *  2011 - 2013 by Thomas Führinger <thomasfuhringer@gmail.com> *
 *  provided under the terms of the GPL                         *
 ****************************************************************/

#include <QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("Synopson");
    app.setWindowIcon(QIcon(":/Images/App.ico"));
    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
