/**
 * The main window library
 *
 * @package Text Encoder
 * @since Text Encoder 1.0
 * @license GNU General Public License v3 or later
 * @copyright (C) 2014  Linuxihaa, linuxihaa.ir
 * @author Misam Saki,  http://misam.ir/
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    QString fileName;

private slots:
    void openFile();
    void saveFile();
    void switchEncode(int);

    void close();
    void showAbout();

    void dropEvent(QDropEvent *ev);
    void dragEnterEvent(QDragEnterEvent *ev);
};

#endif // MAINWINDOW_H
