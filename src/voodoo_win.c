/*
 */

#include "voodoo.h"
#include "vdo_error.h"
#include "gpu.h"

/*
vdo_win_create
description:
    Creates a new window object.
 */
win_id_sint32 vdo_win_create(void)
{
return 0;
}

/*
 *
 */
vdo_error_t vdo_init(void)
{
return( gpu_init() );
}
