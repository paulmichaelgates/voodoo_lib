/*
 * vdo_win.c
 */
#include "gpu.h"
#include "vdo_error.h"
#include "voodoo.h"
#include "generic_types.h"

/*
vdo_win_create
Description:
    Creates a new window object.
 */
vdo_error_t vdo_win_create(vdo_window_h * win_h, int width, int height, char * const title, vdo_win_type_t8 type)
{
/* Local variables */
vdo_error_t ret_val;

/* Call the low level procedure to create the window */
ret_val = gpu_create_win(win_h, width, height, title);

/* Set the window attributes */
if(type >= VDO_WIN_TYPE_COUNT)
    {
    return VDO_ERR_WIN_INIT;
    }
win_h->type = type;

return ret_val;
}
