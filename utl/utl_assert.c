/**
 * utl_assert.c
 * 
 */

#include <stdio.h>
#include <stdlib.h>

void utl_assert(int expression, char *message)
{
if (!expression)
    {
    printf("Assertion failed: %s\n", message);
    exit(1);
    }
}
