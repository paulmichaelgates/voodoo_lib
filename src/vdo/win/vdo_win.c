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
vdo_error_t vdo_win_create(vdo_window_h * win_h, int width, int height, char * const title)
{
return( gpu_create_win(win_h, width, height, title) ); // todo update these args

}
