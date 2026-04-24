#include <string.h>
#include "libgl.h"

t_wire_cylinder	gl_new_wire_cylinder(t_vec3 origin, float radius,
					float height)
{
	t_wire_cylinder	cyl;

	strlcpy(cyl.label, "wire_cylinder", GL_LABEL_MAX);
	cyl.origin = origin;
	cyl.radius = radius;
	cyl.height = height;
	cyl.slices = 12;
	cyl.color = gl_black();
	cyl.transform.rotation = gl_vec3(0, 0, 0);
	cyl.transform.offset = gl_vec3(0, 0, 0);
	cyl.transform.scale = gl_vec3(1, 1, 1);
	return (cyl);
}

t_wire_cylinder	gl_new_wire_cylinder_with_label(t_vec3 origin, float radius,
					float height, const char *label)
{
	t_wire_cylinder	cyl;

	cyl = gl_new_wire_cylinder(origin, radius, height);
	if (strlen(label) < GL_LABEL_MAX)
		strlcpy(cyl.label, label, GL_LABEL_MAX);
	return (cyl);
}
