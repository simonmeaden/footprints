#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "daemon/backgroundcontroller.h"

namespace lintott {

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    init();
    initBuild();
    startDaemon();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::init() {
    pBackController = new BackgroundController(this);
    //    connect(backController, SIGNAL(error(QString)), this, SLOT(errorString(QString)));
    //    connect(thread, SIGNAL(started()), pBackController, SLOT(process()));
    connect(pBackController, SIGNAL(finished()), pBackController, SLOT(deleteLater()));
    pBackController->stop();
}

void MainWindow::initBuild() {
}

void MainWindow::startDaemon() {
}

void MainWindow::startSubController() {
    pProcess = new QProcess(this);
    pProcess->start("");
}

} // end of namespace lintott
