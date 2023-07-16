/*
 gpu.h

 Description:
  plug in into OpenGL logic. This layer provides an interface between
  voodoo lib and the low level interface and should be implemented such
  that it can be swapped out for a different unuderlying graphics interface.

Notes:
    The Low Level GPU code must at minimum implement the procedures and types
    defined in this file.

 */

#ifndef GPU_H_
#define GPU_H_

#include "vdo_error.h"
#include "voodoo.h"

/* Types */
struct gpu_window_h_struc;
typedef struct gpu_window_h_struc gpu_window_h;

/* Procedures */
vdo_error_t gpu_init();
vdo_error_t gpu_create_win(vdo_window_h * win_h, int width, int height, char * const title);
vdo_error_t gpu_gui_add_button(vdo_window_h * win_h, int x, int y, int width, int height, char * const text);

#endif /* GPU_H_ */
