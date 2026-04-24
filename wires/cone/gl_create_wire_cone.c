#include <string.h>
#include "libgl.h"

t_wire_cone	gl_create_wire_cone(t_vec3 origin, float radius, float height)
{
	t_wire_cone	cone;

	cone.origin = origin;
	cone.radius = radius;
	cone.height = height;
	cone.slices = 12;
	cone.stacks = 3;
	cone.color = gl_black();
	cone.transform.rotation = gl_vec3(0, 0, 0);
	cone.transform.offset = gl_vec3(0, 0, 0);
	cone.transform.scale = gl_vec3(1, 1, 1);
	strlcpy(cone.label, "wire_cone", GL_LABEL_MAX);
	return (cone);
}

t_wire_cone	gl_create_wire_cone_with_label(t_vec3 origin, float radius,
				float height, const char *label)
{
	t_wire_cone	cone;

	cone = gl_create_wire_cone(origin, radius, height);
	strlcpy(cone.label, label, GL_LABEL_MAX);
	return (cone);
}
