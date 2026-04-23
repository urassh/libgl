#include "libgl.h"

t_cube	gl_create_cube(t_vec3 origin, t_vec3 size)
{
	t_cube	cube;
	int		i;

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
