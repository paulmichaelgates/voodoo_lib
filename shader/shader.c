/*
 * shader.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <glad/glad.h>

/*
shader_read()

reads in a shader file and returns a pointer to the buffer
*/
int shader_read(char *filename, char **buffer)
{
FILE *fp;

/*
 * Attempt to open the file in read mode
 */
fp = fopen(filename, "r");
if (fp == NULL)
    {
    printf("Error opening file %s\n", filename);
    return -1;
    }

/*
 * Get the size of the file
 */
fseek(fp, 0, SEEK_END);
long size = ftell(fp);
rewind(fp);

*buffer = (char *)malloc(size + 1);
if (*buffer == NULL)
    {
    printf("Error allocating memory for file %s\n", filename);
    return -1;
    }

fread(*buffer, size, 1, fp);
fclose(fp);

return 0;

}

/*
 * shader_compiler()
 *
 * shader - pointer to the shader object id
 * shader_source - file name of the shader source codes
 */
int shader_compile(unsigned int *shader, char *shader_source)
{
/*
 * Local variables
 */
const char * source_code;

/*
 * Compiler the shader
 */
if(shader_read(shader_source, (char ** )&source_code) != 0)
    {
    printf("Error reading shader source code\n");
    return -1;
    }

glShaderSource(*shader, 1, &source_code, NULL);
glCompileShader(*shader);

return 0;

}
