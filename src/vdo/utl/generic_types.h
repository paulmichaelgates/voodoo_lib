/*
 * generic_types.h
 */

#ifndef GENERIC_TYPES_H
#define GENERIC_TYPES_H

typedef char                  uint8;
typedef unsigned short        uint16;
typedef unsigned int          uint32;
typedef unsigned long long    uint64;
typedef char                  boolean;

#ifndef TRUE
#define TRUE  (1)
#endif /* TRUE */

#ifndef FALSE
#define FALSE (0)
#endif /* FALSE */

#ifndef NULL
#define NULL ( (void *) 0)
#endif /* NULL */

#ifndef arr_count
#define arr_count(arr) (uint32)(sizeof(arr) / sizeof(arr[0]))
#endif  /* arr_count */

#endif /* GENERIC_TYPES_H */