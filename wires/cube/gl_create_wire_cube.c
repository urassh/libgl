#include "libgl.h"

t_wire_cube	gl_create_wire_cube(t_vec3 origin, t_vec3 size)
{
	t_wire_cube	cube;

	cube.origin = origin;
	cube.size = size;
	cube.color = gl_black();
	cube.transform.rotation = gl_vec3(0, 0, 0);
	cube.transform.offset = gl_vec3(0, 0, 0);
	cube.transform.scale = gl_vec3(1, 1, 1);
	return (cube);
}
