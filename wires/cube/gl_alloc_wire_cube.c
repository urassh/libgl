#include <stdlib.h>
#include "libgl.h"

t_wire_cube	*gl_alloc_wire_cube(t_vec3 origin, t_vec3 size)
{
	t_wire_cube	*cube;

	cube = (t_wire_cube *)malloc(sizeof(t_wire_cube));
	if (!cube)
		return (NULL);
	*cube = gl_create_wire_cube(origin, size);
	return (cube);
}
