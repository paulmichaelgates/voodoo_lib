/*
 * open_gl_buf.h
 */

#ifndef OPENGL_BUF_H_
#define OPENGL_BUF_H_

#include "generic_types.h"
#include "vdo_error.h"

/* Literal constants */
#define OPENGL_RECT_BUF_SIZE 12
#define OPENGL_MAX_RECT_BUF  10 /* Arbitrary -- can only have 10 rectangles at any given time */

/* Types */
typedef uint8 open_gl_buf_type;
enum
    {
    OPEN_GL_BUF_TYPE_RECT,      /* Rectangular buffer object type */
    };

typedef uint32 open_gl_rect_buf_id_t32;

/* Procedures */
void open_gl_buf_init();
vdo_error_t open_gl_create_buf(open_gl_buf_type type, open_gl_rect_buf_id_t32 * id);
vdo_error_t open_gl_get_buf(open_gl_buf_type type, open_gl_rect_buf_id_t32 id, void * buf);

#endif /* OPENGL_BUF_H_ */