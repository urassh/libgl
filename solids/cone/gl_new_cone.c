#include <string.h>
#include "libgl.h"

t_cone	gl_new_cone(t_vec3 origin, float radius, float height, int slices)
{
	t_cone	cone;

	strlcpy(cone.label, "cone", GL_LABEL_MAX);
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

t_cone	gl_new_cone_with_label(t_vec3 origin, float radius, float height,
			int slices, const char *label)
{
	t_cone	cone;

	cone = gl_new_cone(origin, radius, height, slices);
	if (strlen(label) < GL_LABEL_MAX)
		strlcpy(cone.label, label, GL_LABEL_MAX);
	return (cone);
}
