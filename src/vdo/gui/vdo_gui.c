/*
 * vdo_gui.c
 */

#include "generic_types.h"
#include "voodoo.h"
#include "gpu.h"

vdo_error_t vdo_gui_add_button(vdo_window_h * win, uint32 x, uint32 y, uint32 width, uint32 height, char * const text)
{
gpu_gui_add_button(win, x, y, width, height, text);

return VDO_ERR_NONE;
}