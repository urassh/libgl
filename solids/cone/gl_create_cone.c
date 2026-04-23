#include "libgl.h"

t_cone	gl_create_cone(t_vec3 origin, float radius, float height, int slices)
{
	t_cone	cone;

	cone.origin = origin;
	cone.radius = radius;
	cone.height = height;
	cone.slices = slices;
	cone.color = gl_black();
	cone.has_outline = false;
	cone.transform.rotation = gl_vec3(0, 0, 0);
	cone.transform.offset = gl_vec3(0, 0, 0);
	cone.transform.scale = gl_vec3(1, 1, 1);
	return (cone);
}
