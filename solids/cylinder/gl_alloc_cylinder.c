#include <stdlib.h>
#include "libgl.h"

t_cylinder	*gl_alloc_cylinder(t_vec3 origin, float radius, float height,
				int slices)
{
	t_cylinder	*cyl;

	cyl = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!cyl)
		return (NULL);
	*cyl = gl_create_cylinder(origin, radius, height, slices);
	return (cyl);
}
