#include <stdlib.h>
#include <string.h>
#include "libgl.h"

t_cone	*gl_alloc_cone(t_vec3 origin, float radius, float height, int slices)
{
	t_cone	*cone;

	cone = (t_cone *)malloc(sizeof(t_cone));
	if (!cone)
		return (NULL);
	*cone = gl_new_cone(origin, radius, height, slices);
	return (cone);
}

t_cone	*gl_alloc_cone_with_label(t_vec3 origin, float radius, float height,
			int slices, const char *label)
{
	t_cone	*cone;

	cone = gl_alloc_cone(origin, radius, height, slices);
	if (!cone)
		return (NULL);
	if (strlen(label) < GL_LABEL_MAX)
		strlcpy(cone->label, label, GL_LABEL_MAX);
	return (cone);
}
