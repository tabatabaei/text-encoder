/**
 * The main function for load application
 *
 * @package Text Encoder
 * @since Text Encoder 1.0
 * @license GNU General Public License v3 or later
 * @copyright (C) 2014  Linuxihaa, linuxihaa.ir
 * @author Misam Saki,  http://misam.ir/
 */


#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
