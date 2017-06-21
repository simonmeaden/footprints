#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QProcess>
#include <QSettings>

namespace Ui {
class MainWindow;
}

namespace lintott {

class BackgroundController;

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

  protected:
    BackgroundController *pBackController;
    QProcess *pProcess;
    QSettings *pSettings;

    void init();
    void initBuild();
    void startDaemon();
    void startSubController();

  private:
    Ui::MainWindow *ui;
};

} // end of namespace lintott

#endif // MAINWINDOW_H
