#include <stdlib.h>
#include <string.h>
#include "libgl.h"

t_wire_cube	*gl_alloc_wire_cube(t_vec3 origin, t_vec3 size)
{
	t_wire_cube	*cube;

	cube = (t_wire_cube *)malloc(sizeof(t_wire_cube));
	if (!cube)
		return (NULL);
	*cube = gl_new_wire_cube(origin, size);
	return (cube);
}

t_wire_cube	*gl_alloc_wire_cube_with_label(t_vec3 origin, t_vec3 size,
				const char *label)
{
	t_wire_cube	*cube;

	cube = gl_alloc_wire_cube(origin, size);
	if (!cube)
		return (NULL);
	if (strlen(label) < GL_LABEL_MAX)
		strlcpy(cube->label, label, GL_LABEL_MAX);
	return (cube);
}
