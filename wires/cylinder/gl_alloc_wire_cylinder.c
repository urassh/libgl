#include <stdlib.h>
#include "libgl.h"

t_wire_cylinder	*gl_alloc_wire_cylinder(t_vec3 origin, float radius,
					float height)
{
	t_wire_cylinder	*cyl;

	cyl = (t_wire_cylinder *)malloc(sizeof(t_wire_cylinder));
	if (!cyl)
		return (NULL);
	*cyl = gl_create_wire_cylinder(origin, radius, height);
	return (cyl);
}
