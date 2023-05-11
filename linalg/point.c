/*
 * point.c
 *
 */

#include "assert.h"
#include "component.h"

inline boolean point_compare(point_t *point_p, point_t *point_q)
{
/*
 * Local variables
 */
uint32 i;

/*
 * Input validation
 */
assert((point_p == NULL), "Point is NULL.");

/**
 * If the dimensions are not equal, the points are not equal. 
 */
if (point_p->dims != point_q->dims)
    {
    return FALSE;
    }

/**
 * Otherwise compare each point against each other.
 */
for(i = 0; i < point_p->dims; i++)
    {
    if (point_p->coords[ i ] != point_q->coords[ i ])
        {
        return FALSE;
        }
    }
return TRUE;

}