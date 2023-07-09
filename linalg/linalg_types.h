/**
 * component.h
 * 
 * Defines components used in linear algebra.
 */

#include "generic_types.h"

#define NUM_POINTS  ( 2 )

/*
 * Types
 */

typedef struct
    {
    int dims;           /* Dimensions */
    int * coords;       /* Coordinates */
    }point_t;

typedef struct
    {
    int dims;           /* Dimensions */
    point_t points[ NUM_POINTS ];
    }line_t;

typedef struct
    {
    float x;
    float y;
    float z;
    }linalg_vector_3d_t;

typedef struct
    {
    void * buff;        /* Data buffer */
    uint32 el_size;     /* Element size */
    uint64 rows;        /* Rows m */
    uint64 cols;        /* Columns n */
    }linalg_matrix_t;

typedef uint8 component_err_t;
enum
    {
    COMPONENT_ERR_NONE,
    COMPONENT_ERR_INVALID_DIMS,
    COMPONENT_ERR_INVALID_COORDS,
    COMPONENT_ERR_INVALID_POINT,
    COMPONENT_ERR_INVALID_LINE,
    COMPONENT_ERR_INVALID_PLANE,
    COMPONENT_ERR_INVALID_MATRIX,
    COMPONENT_ERR_INVALID_VECTOR,
    COMPONENT_ERR_INVALID_TENSOR,
    COMPONENT_ERR_INVALID_QUATERNION,
    COMPONENT_ERR_INVALID_POLYNOMIAL,
    COMPONENT_ERR_INVALID_FUNCTION,
    };

typedef uint8 linalg_matrix_err_t
enum
    {
    LIN_ALG_MATRIX_ERR_NO_ERR,
    };

/**
 * Procedures
 */
component_err_t line_init(line_t *out_line, int dims, int* coord_p, int* coord_q);
boolean point_compare(point_t *point_p, point_t *point_q);
boolean line_point_in_line(line_t *line_p, point_t *point_p);
