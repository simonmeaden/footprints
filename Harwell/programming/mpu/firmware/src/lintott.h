/* 
 * File:   lintott.h
 * Author: Simon Meaden
 *
 * Created on 02 May 2017, 08:45
 */

#ifndef LINTOK_H
#    define	LINTOK_H

#    include <stdint.h>
#    include <stdbool.h>
#    include <stddef.h>
#    include <stdlib.h>

#    include "i2c.h"


#    ifdef	__cplusplus
extern "C" {
#    endif

    typedef union {
        uint64_t state;

        struct {
            uint64_t direction : 1;
            uint64_t implant : 1;
            uint64_t stop : 1;

        } memory;
    } LINTOTT_STATE;


    void initImplant();
    void stopimplant();
    void startImplant();
    void completedImplant();


#    ifdef	__cplusplus
}
#    endif

#endif	/* LINTOK_H */

