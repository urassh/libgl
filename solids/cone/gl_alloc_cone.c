#include <stdlib.h>
#include "libgl.h"

t_cone	*gl_alloc_cone(t_vec3 origin, float radius, float height, int slices)
{
	t_cone	*cone;

	cone = (t_cone *)malloc(sizeof(t_cone));
	if (!cone)
		return (NULL);
	*cone = gl_create_cone(origin, radius, height, slices);
	return (cone);
}
