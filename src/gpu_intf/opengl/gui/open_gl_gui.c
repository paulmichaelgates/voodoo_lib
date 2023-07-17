/*
 * open_gl_gui.h
 * Description: GUI Graphic component processing logic
 */

#include "generic_types.h"
#include "open_gl_buf.h"
#include "voodoo.h"
#include "vdo_error.h"

#define RECT_ELEMENT_BUFFER_SIZE 12

/* Variables */
static boolean s_render = FALSE;

/* Procedures */
static vdo_error_t load_rectangular_buffer(float * buf, int x, int y, int width, int height);

/*
 * gpu_gui_prdc
 * Description: Periodic GUI graphics component
 */
void gpu_gui_prdc()
{
if( s_render )
    {
    // todo do graphics rendering
    }
}

/*
 * gpu_gui_add_button
 */
vdo_error_t gpu_gui_add_button(vdo_window_h * win_h, int x, int y, int width, int height, char * const text)
{
/* Local variables */
vdo_error_t ret_val;
uint32      buf_idx;

/* input validation */
if(NULL == win_h)
    {
    return VDO_ERR_PARM;
    }

if( VDO_WIN_TYPE_GUI == win_h->type)
    {
    return VDO_ERR_WIN_TYPE;
    }

/* 
 * Get the vertices of this graphics object using the information the 
 * user gave us to create this button
 */
ret_val = load_rectangular_buffer(&buf_idx, x, y, width, height);
if( VDO_ERR_NONE != ret_val )
    {
    return ret_val;
    }

open_gl_assoc_buf(OPEN_GL_BUF_TYPE_RECT, win_h, buf_idx);

// todo pass button handler back to the user

return VDO_ERR_NONE;

}

/*
 * load_rectangular_buffer
 */
static vdo_error_t load_rectangular_buffer(uint32 * buf_idx, int x, int y, int width, int height)
{
/* Local variables */
open_gl_rect_buf_id_t32 buf_id;
vdo_error_t             ret_val;
float *                 buf;

/* Attempt to allocate buffer */
ret_val = open_gl_alloc_buf(OPEN_GL_BUF_TYPE_RECT, &buf_id);
if(VDO_ERR_NONE != ret_val)
    {
    return ret_val;
    }

/* Retreive the stored buffer out of memory */
ret_val = open_gl_get_buf(OPEN_GL_BUF_TYPE_RECT, buf_id, buf);
if(VDO_ERR_NONE != ret_val)
    {
    return ret_val;
    }

if(NULL == buf)
    {
    return VDO_ERR_BUF;
    }

/* Successully created a buffer, now time to set the verts */
// todo - decide buffer values based on x, y, width, height, etc.
// todo - instead of hard coding values.
buf[ 0 ] = 0.5f;
buf[ 1 ] = 0.5f;
buf[ 2 ] = 0.0f;

buf[ 3 ] = 0.5f;
buf[ 4 ] = -0.5f;
buf[ 5 ] = 0.0f;

buf[ 6 ] = -0.5f;
buf[ 7 ] = -0.5f;
buf[ 8 ] = 0.0f;

buf[ 9 ]  = -0.5f;
buf[ 10 ] = 0.5f;
buf[ 11 ] = 0.0f;

return VDO_ERR_NONE;

}
