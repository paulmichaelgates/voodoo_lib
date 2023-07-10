/*
 gpu.h
 Description:
  plug in into OpenGL logic. This layer provides an interface between
  voodoo lib and the low level interface and should be implemented such
  that it can be swapped out for a different unuderlying graphics interface.
 */

#ifndef GPU_H_

#define GPU_H_

#include "vdo_error.h"

vdo_error_t gpu_init();

#endif /* GPU_H_ */
