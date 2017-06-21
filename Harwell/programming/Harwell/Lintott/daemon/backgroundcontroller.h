#ifndef BACKGROUNDCONTROLLER_H
#define BACKGROUNDCONTROLLER_H

#include <QObject>
#include <QThread>
#include <QMutex>
#include <QMutexLocker>

namespace lintott {

class BackgroundController : public QThread {
    Q_OBJECT
  public:
    enum ControllerError {
        NoError,
    };

    explicit BackgroundController(QObject *parent = 0);
    ~BackgroundController();

    void stop();
    void processError(ControllerError);

  signals:
    void finished();
    void error(ControllerError);

  protected:

    QMutex mMutex;
    bool bRunning;

    void run();

  private:


};

} // end of namespace lintott

#endif // BACKGROUNDCONTROLLER_H
