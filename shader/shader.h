/*
 * shader.h
 */

#ifndef SHADER_H_

int shader_read(char *filename, const char **shader);

int shader_compile(unsigned int *shader, const char *shader_source);

#endif /* SHADER_H_ */
