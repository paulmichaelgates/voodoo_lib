/**
 * line.c
 * 
 * Line data structure and functions.
 */
#include <math.h>
#include "assert.h"
#include "component.h"
#include "generic_types.h"

/**
 * line_init
 * 
 * initializes a line_t struct.
 */
component_err_t line_init(line_t *out_line, int dims, int* coord_p, int* coord_q)
{
/*
 * Local variables
 */
uint32 i;

/*
 * Input validation
 */
if (dims < 1)
    {
    return COMPONENT_ERR_INVALID_DIMS;
    }

/*
 * Initialize the line.
 */
out_line->dims = dims;
out_line->points[ 0 ].dims = dims;
out_line->points[ 1 ].dims = dims;

/**
 * Copy in the coordinates.
 */
for (i = 0; i < dims; i++)
    {
    out_line->points[ 0 ].coords = coord_p;
    out_line->points[ 1 ].coords = coord_q;
    }

return COMPONENT_ERR_NONE;
}

boolean line_point_in_line(line_t *line_p, point_t *point_p)
{
/*
 * Local variables
 */
uint32 i;
float t_axis;       /* Scalar with respect to the current axis */
float frac_part;    /* Fractional part of t_axis */
float prv_t_axis;   /* Previous scalar value */

/*
 * Input validation
 */
assert((line_p == NULL), "Line is NULL.");
assert((point_p == NULL), "Point is NULL.");
assert ((line_p->dims != point_p->dims), "Dimensions of line and point do not match.");

/*
 * Determine if this is a single point line
 * not really a line, but a point I guess
 */
if(line_is_point(&line_p))
    {
    return point_compare(&line_p->points[ 0 ], point_p);
    }

/*
 * Determine if the point is in the line.
 */
for(i = 0; i < line_p->dims; i++)
    {
    /*
     * Construct the equation for this axis
     * t = (p-x)/(p-q)
     */
    t_axis = (line_p->points[0].coords[i] - point_p->coords[i]) 
            / (line_p->points[0].coords[i] - line_p->points[1].coords[i]);

    /*
     * If the fractional part of the scalar is not zero, the point is not in the line.
     * Also if the t component does not match the previous t component after the first
     * iteration, the point is not in the line.
     */
    if((modf(t_axis, NULL) != 0)
    || (i < 0 && t_axis != prv_t_axis))
        {
        return FALSE;
        }
    
    prv_t_axis = t_axis;
    }

return TRUE;

}

inline boolean line_is_point(line_t *line_p)
{
/*
 * Local variables
 */
uint32 i;

/*
 * input validation
 */
assert((line_p == NULL), "Line is NULL.");

/*
 * compare the two points in the line
 */
for(i = 0; i < line_p->dims; i++)
    {
    if (line_p->points[ 0 ].coords[ i ] != line_p->points[ 1 ].coords[ i ])
        {
        return FALSE;
        }

    }

return TRUE;

}