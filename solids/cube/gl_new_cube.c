#include <string.h>
#include "libgl.h"

t_cube	gl_new_cube(t_vec3 origin, t_vec3 size)
{
	t_cube	cube;
	int		i;

	cube.type = GL_TYPE_CUBE;
	strlcpy(cube.label, "cube", GL_LABEL_MAX);
	cube.origin = origin;
	cube.size = size;
	i = 0;
	while (i < 6)
	{
		cube.colors[i] = gl_black();
		i++;
	}
	cube.has_outline = false;
	cube.transform.rotation = gl_vec3(0, 0, 0);
	cube.transform.offset = gl_vec3(0, 0, 0);
	cube.transform.scale = gl_vec3(1, 1, 1);
	return (cube);
}

t_cube	gl_new_cube_with_label(t_vec3 origin, t_vec3 size,
			const char *label)
{
	t_cube	cube;

	cube = gl_new_cube(origin, size);
	if (strlen(label) < GL_LABEL_MAX)
		strlcpy(cube.label, label, GL_LABEL_MAX);
	return (cube);
}
