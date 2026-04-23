#include "libgl.h"

t_cylinder	gl_create_cylinder(t_vec3 origin, float radius, float height,
				int slices)
{
	t_cylinder	cyl;

	cyl.origin = origin;
	cyl.radius = radius;
	cyl.height = height;
	cyl.slices = slices;
	cyl.color = gl_black();
	cyl.has_outline = false;
	cyl.transform.rotation = gl_vec3(0, 0, 0);
	cyl.transform.offset = gl_vec3(0, 0, 0);
	cyl.transform.scale = gl_vec3(1, 1, 1);
	return (cyl);
}
