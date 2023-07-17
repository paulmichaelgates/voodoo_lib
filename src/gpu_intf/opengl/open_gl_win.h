/*
 * open_gl_win.h
 */

#ifndef GPU_INTF_OPENGL_BUF_OPEN_GL_WIN_H_
#define GPU_INTF_OPENGL_BUF_OPEN_GL_WIN_H_

#include <GLFW/glfw3.h>
#include "vdo_error.h"
#include "voodoo.h"

vdo_error_t open_gl_win_updt_current_context( vdo_window_h * win_h );

#endif /* GPU_INTF_OPENGL_BUF_OPEN_GL_WIN_H_ */