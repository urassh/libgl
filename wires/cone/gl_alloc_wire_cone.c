#include <stdlib.h>
#include "libgl.h"

t_wire_cone	*gl_alloc_wire_cone(t_vec3 origin, float radius, float height)
{
	t_wire_cone	*cone;

	cone = (t_wire_cone *)malloc(sizeof(t_wire_cone));
	if (!cone)
		return (NULL);
	*cone = gl_create_wire_cone(origin, radius, height);
	return (cone);
}
