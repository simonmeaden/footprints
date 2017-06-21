#ifndef MANUALMOTORVOLTAGE_H
#define MANUALMOTORVOLTAGE_H

#include <QObject>


class MotorSpeeds {
  public:
    MotorSpeeds();

    void setManualSpeed(qreal speed);
    qreal manualSpeed();
    qreal speed20();
    qreal speed4();

  protected:
    qreal mManualSpeed, m20Speed, m4Speed;

};

#endif // MANUALMOTORVOLTAGE_H
