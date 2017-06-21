#include "manualmotorvoltage.h"

MotorSpeeds::MotorSpeeds() {
}

void MotorSpeeds::setManualSpeed(qreal speed) {
    mManualSpeed = speed;
}

qreal MotorSpeeds::manualSpeed() {
    return mManualSpeed;
}

qreal MotorSpeeds::speed20() {
    return m20Speed;
}

qreal MotorSpeeds::speed4() {
    return m4Speed;
}
