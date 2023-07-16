/*
 * vdo_init.c
 */

#include "voodoo.h"
#include "gpu.h"

/*
 *  vdo_init
 *  Description: Initialize the voodoo library
 */
vdo_error_t vdo_init(void)
{
return( gpu_init() );

}
