#include <stdlib.h>
#include <string.h>
#include "libgl.h"

t_cube	*gl_alloc_cube(t_vec3 origin, t_vec3 size)
{
	t_cube	*cube;

	cube = (t_cube *)malloc(sizeof(t_cube));
	if (!cube)
		return (NULL);
	*cube = gl_create_cube(origin, size);
	return (cube);
}

t_cube	*gl_alloc_cube_with_label(t_vec3 origin, t_vec3 size,
			const char *label)
{
	t_cube	*cube;

	cube = gl_alloc_cube(origin, size);
	if (!cube)
		return (NULL);
	strlcpy(cube->label, label, GL_LABEL_MAX);
	return (cube);
}
