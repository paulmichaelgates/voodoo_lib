/*
 * Contains all of the Windows specific interfaces for the Voodoo library.
 */

#ifndef VOODOO_H

#include "vdo_error.h"

/*
 * Literal costants
 */
#define VDO_MAX_KEY_MAPS 16

/*
 * Typedefs
 */
typedef int win_id_sint32;

typedef struct
    {
    int key_maps[VDO_MAX_KEY_MAPS];         /* Window key maps */
    win_id_sint32 id;                     /* Key to window obj */
    } vdo_window_h;                         /* Window handle */

/*
 * Procedures
 */

win_id_sint32 vdo_win_create(void);
void vdo_reg_key_bind(vdo_window_h window, int key, int action); // TODO callback function
vdo_error_t vdo_init(void);

#endif /* VOODOO_H */
