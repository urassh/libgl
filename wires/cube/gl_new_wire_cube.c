#include <string.h>
#include "libgl.h"

t_wire_cube	gl_new_wire_cube(t_vec3 origin, t_vec3 size)
{
	t_wire_cube	cube;

	cube.type = GL_TYPE_WIRE_CUBE;
	strlcpy(cube.label, "wire_cube", GL_LABEL_MAX);
	cube.origin = origin;
	cube.size = size;
	cube.color = gl_black();
	cube.transform.rotation = gl_vec3(0, 0, 0);
	cube.transform.offset = gl_vec3(0, 0, 0);
	cube.transform.scale = gl_vec3(1, 1, 1);
	return (cube);
}

t_wire_cube	gl_new_wire_cube_with_label(t_vec3 origin, t_vec3 size,
				const char *label)
{
	t_wire_cube	cube;

	cube = gl_new_wire_cube(origin, size);
	if (strlen(label) < GL_LABEL_MAX)
		strlcpy(cube.label, label, GL_LABEL_MAX);
	return (cube);
}
