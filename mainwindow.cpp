/**
 * The main window class
 *
 * @package Text Encoder
 * @since Text Encoder 1.0
 * @license GNU General Public License v3 or later
 * @copyright (C) 2014  Linuxihaa, linuxihaa.ir
 * @author Misam Saki,  http://misam.ir/
 */


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());

    ui->comboBoxEncode->addItem(tr("Default"));
    ui->comboBoxEncode->addItem(tr("UTF-8"));
    ui->comboBoxEncode->addItem(tr("Windows-1256"));
    ui->comboBoxEncode->addItem(tr("ISO-8859-1"));
    ui->comboBoxEncode->addItem(tr("Windows-1252"));

    setAcceptDrops(true);

    connect(ui->pushButtonSaveFile, SIGNAL(clicked()), this, SLOT(saveFile()));
    connect(ui->comboBoxEncode,SIGNAL(currentIndexChanged(int)), this, SLOT(switchEncode(int)));

    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(openFile()));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(ui->actionClose, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(showAbout()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dropEvent(QDropEvent *ev) {
    QList<QUrl> urls = ev->mimeData()->urls();
    foreach(QUrl url, urls) {
        fileName = url.toLocalFile();
        if (!fileName.isEmpty()) {
            ui->comboBoxEncode->setCurrentIndex(0);
            ui->pushButtonSaveFile->setEnabled(true);
            ui->actionSave->setEnabled(true);
            QFile file(fileName);
            if(file.open(QIODevice::ReadOnly|QIODevice::Text)) {
                QTextStream in(&file);
                ui->textEdit->setText(in.readAll());
            }
            file.close();
        }
    }
}

void MainWindow::dragEnterEvent(QDragEnterEvent *ev) {
    ev->accept();
}

void MainWindow::openFile() {
    QFileDialog::Options options;
        QString selectedFilter;
        fileName = QFileDialog::getOpenFileName(this,
                                    tr("QFileDialog::getOpenFileName()"),
                                    ui->pushButtonSaveFile->text(),
                                    tr("All Files (*);;Text Files (*.txt)"),
                                    &selectedFilter,
                                    options);
        if (!fileName.isEmpty()) {
            ui->comboBoxEncode->setCurrentIndex(0);
            ui->pushButtonSaveFile->setEnabled(true);
            ui->actionSave->setEnabled(true);
            QFile file(fileName);
            if(file.open(QIODevice::ReadOnly|QIODevice::Text)) {
                QTextStream in(&file);
                ui->textEdit->setText(in.readAll());
            }
            file.close();
        }
}
void MainWindow::saveFile() {
    QString code = ui->comboBoxEncode->currentText();
    if (code != "Default") {
        QFile file(fileName);
        if(file.open(QIODevice::WriteOnly|QIODevice::Text)) {
            QTextStream out(&file);
            out << ui->textEdit->toPlainText();
            out.setCodec(code.toUtf8());
        }
        file.close();
    }
}
void MainWindow::switchEncode(int index) {
    QString code = ui->comboBoxEncode->currentText();
    QFile file(fileName);
    if(file.open(QIODevice::ReadOnly|QIODevice::Text)) {
        QTextStream in(&file);
        if (code != "Default") in.setCodec(code.toUtf8());
        ui->textEdit->setText(in.readAll());
    }
}

void MainWindow::close() {
    QApplication::quit();
}
void MainWindow::showAbout() {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::information(this, tr("About"), "Text Encoder\nVersion 1.0\nLicense GNU General Public License v3 or later\nCopyright (C) 2014  Linuxihaa, linuxihaa.ir\n\nAuthor: Misam Saki (misam.ir)\nGithub: http://github.com/misamplus/text-encoder/");
    //if (reply == QMessageBox::Ok)
}

