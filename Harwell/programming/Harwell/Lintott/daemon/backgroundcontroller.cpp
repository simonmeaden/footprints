#include "backgroundcontroller.h"

namespace lintott {

BackgroundController::BackgroundController(QObject *parent) :
    QThread(parent),
    bRunning(false) {
}

BackgroundController::~BackgroundController() {
}

void BackgroundController::run() {
    bRunning = true;

    while (!bRunning) {
    }

    emit finished();
}

void BackgroundController::stop() {
    QMutexLocker locker(&mMutex);
    bRunning = false;
}

void BackgroundController::processError(ControllerError error) {
    switch (error) {
        case NoError:
        default:
            return;
    }
}

} // end of namespace lintott
