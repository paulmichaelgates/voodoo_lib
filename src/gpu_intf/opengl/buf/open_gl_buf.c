/*
 * open_gl_buf.c 
 */

#include <glad/glad.h> 
#include <GLFW/glfw3.h>

#include "vdo_error.h"
#include "open_gl_buf.h"
#include "open_gl_win.h"
#include "generic_types.h"
#include "string.h"

/* Local types */

typedef struct
    {
    float        buf[ OPENGL_RECT_BUF_SIZE ];    /* Buffer of vertices */
    uint32       id;                             /* OpenGl Buffer id */
    boolean      in_use;                         /* Is this buffer currently being used */
    } open_gl_float_rect_buf_t;

/* Constants */
const uint32 rect_indices[] = {
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
};

/* Variables */
static open_gl_float_rect_buf_t s_rect_bufs[ OPENGL_MAX_RECT_BUF ];

/* Procedures */
static vdo_error_t open_gl_buf_create_buf_rect(open_gl_rect_buf_id_t32 * id);
static vdo_error_t open_gl_get_buf_rect(open_gl_rect_buf_id_t32 id, float * buf);

/*
 * open_gl_buf_init
 */
void open_gl_buf_init()
{
/* Init all of the buffers */
memset(s_rect_bufs, 0, sizeof(s_rect_bufs));

}

/*
 * open_gl_alloc_buf
 */
vdo_error_t open_gl_alloc_buf(open_gl_buf_type type, open_gl_rect_buf_id_t32 * id)
{
/* init return */
*id = OPENGL_MAX_RECT_BUF;

/* Attempt to create the specified buffer */
switch (type)
    {
    case OPEN_GL_BUF_TYPE_RECT:
        open_gl_buf_create_buf_rect(id);
        break;

    /* Buffer type not supported  */
    default:
        return VDO_ERR_PARM;
        break;
    }

return VDO_ERR_NONE;
}

/*
 * open_gl_get_buf
 */
vdo_error_t open_gl_get_buf(open_gl_buf_type type, open_gl_rect_buf_id_t32 id, void * buf)
{
switch (type)
    {
    case OPEN_GL_BUF_TYPE_RECT:
        return( open_gl_get_buf_rect(id, (float *)buf) );
        break;

    /* Buffer type not supported  */
    default:
        return VDO_ERR_PARM;
        break;
    }
}

/*
 * open_gl_get_buf_rect
 */
vdo_error_t open_gl_get_buf_rect(open_gl_rect_buf_id_t32 id, float * buf)
{
/* Input validation */
if(id >= OPENGL_MAX_RECT_BUF )
    {
    return VDO_ERR_PARM;
    }

/* Return the requested buffer if is still valid */
if( !s_rect_bufs[ id ].in_use )
    {
    return VDO_ERR_BUF_NOT_IN_USE;
    }
buf = s_rect_bufs[ id ].buf; 

return VDO_ERR_NONE;

}

/*
 * open_gl_buf_create_buf_rect 
 */
static vdo_error_t open_gl_buf_create_buf_rect(open_gl_rect_buf_id_t32 * id)
{
/* Local variables */
uint32  buf_idx;

/* Search for a free buffer */
for(buf_idx = 0; buf_idx < arr_count(s_rect_bufs); buf_idx++)
    {
    if(!s_rect_bufs[buf_idx].in_use)
        {
        break;
        }
    }

if(buf_idx >= OPENGL_MAX_RECT_BUF)
    {
    return VDO_ERR_BUF_MEM_MAX;
    }

/* Generate the new buffer. 1 for single buffer */
glGenBuffers( 1, &(s_rect_bufs[ buf_idx ].id) );

*id = buf_idx;

return VDO_ERR_NONE;

}

/*
 * open_gl_assoc_buf
 * Description: Associates a buffer with a window
 */
vdo_error_t open_gl_assoc_buf(open_gl_buf_type type, vdo_window_h * win_h, uint32 buf_idx )
{
/* Input validation */
if( ( NULL == win_h )
||  ( OPENGL_MAX_RECT_BUF <= buf_idx )
||  ( OPEN_GL_BUF_TYPE_COUNT <= type ) )
    {
    return VDO_ERR_PARM;
    }

/* 
 * Ensure that the buffer is applied to the correct window.
 */
open_gl_win_updt_current_context( win_h );

switch (type)
    {
    /* Bind the rectangular buffer */
    case OPEN_GL_BUF_TYPE_RECT:
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, s_rect_bufs[ buf_idx ].id);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(rect_indices), rect_indices, GL_STATIC_DRAW);
        break;

    /* Buffer type not supported */
    default:
        return VDO_ERR_PARM;
        break;
    }

return VDO_ERR_NONE;

}
