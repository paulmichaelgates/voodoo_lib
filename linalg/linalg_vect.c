/*
 * linalg_vect.c
 */

#include "linalg_types.h"

/*
 * linalg_vect_scale
 */
int linalg_vect_scale(float scalar, linalg_vector_3d_t * vect_in, linalg_vector_3d_t * vect_out)
{
/* input validation */
if(!vect_in)
    {
    return -1;
    }

/* scale each component of the vetor */
vect_out->x = vect_in->x * scalar;
vect_out->y = vect_in->y * scalar;
vect_out->y = vect_in->y * scalar;

return 0;
}
