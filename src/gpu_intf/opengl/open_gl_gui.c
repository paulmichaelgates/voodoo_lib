/*
 * open_gl_gui.h
 */

#include "open_gl_buf.h"
#include "voodoo.h"
#include "vdo_error.h"

#define RECT_ELEMENT_BUFFER_SIZE 12

/* Procedures */
static vdo_error_t get_component_vertices(float * buf, int x, int y, int width, int height);

/*
 * gpu_gui_add_button
 */
vdo_error_t gpu_gui_add_button(vdo_window_h * win_h, int x, int y, int width, int height, char * const text)
{
/* Local variables */
vdo_error_t ret_val;
float *     buf  = NULL;

/* input validation */
if(NULL == win_h)
    {
    return VDO_ERR_PARM;
    }

if( VDO_WIN_TYPE_GUI == win_h->type)
    {
    return VDO_ERR_WIN_TYPE;
    }

ret_val = get_component_vertices(buf, x, y, width, height);

return VDO_ERR_NONE;

}

/*
 * get_component_vertices
 */
static vdo_error_t get_component_vertices(float * buf, int x, int y, int width, int height)
{
/* Local variables */
open_gl_rect_buf_id_t32 buf_id;
vdo_error_t             ret_val;


/* Attempt to allocate buffer */
ret_val = open_gl_create_buf(OPEN_GL_BUF_TYPE_RECT, &buf_id);
if(VDO_ERR_NONE != ret_val)
    {
    return ret_val;
    }

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
