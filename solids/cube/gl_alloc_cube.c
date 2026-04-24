#include <stdlib.h>
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
