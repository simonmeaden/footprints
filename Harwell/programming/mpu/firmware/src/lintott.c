
#include <stdbool.h>

#include "lintott.h"
#include "driver/i2c/drv_i2c.h"

/*
 Memory locations.
 */

LINTOCK_STATUS m_lintott;

void startImplant() {
    m_lintott.implant_memory = true;
}

void stopImplant() {
    m_lintott.stop_memory = true;
}

void implantComplete() {
    m_lintott.implant_memory = false;
    m_lintott.completed = true;
}

void initImplant() {
    m_lintott.completed = false;
    m_lintott.direction_memory = LintottDirection::UP;
    m_lintott.implant_memory = false;
    m_lintott.stop_memory = false;
}


void requestI2CInputs(LintottInputAddress address) {
    
    
    
    switch (address) {
        case Input1: {
            break;
        }
        case Input2: {
            break;
        }
        case Input3: {
            break;
        }
        case Input4: {
            break;
        }
    }
}
