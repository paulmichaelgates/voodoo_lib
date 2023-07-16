/*
 * vdo_error.h
 */
#ifndef VDO_ERROR_H_
#define VDO_ERROR_H_

#include "generic_types.h"

typedef uint8 vdo_error_t;
enum
{
VDO_ERR_NONE = 0,
VDO_ERR_INIT,
VDO_ERR_WIN_INIT,
VDO_ERR_WIN,
VDO_ERR_PARM,
VDO_ERR_WIN_TYPE,
VDO_ERR_BUF_OVRFL,
VDO_ERR_BUF,
VDO_ERR_BUF_MEM_MAX,
VDO_ERR_BUF_NOT_IN_USE,
};

#endif /* VDO_ERROR_H_ */