#include <stdlib.h>
#include <string.h>
#include "libgl.h"

t_perspective_camera	*gl_alloc_perspective_camera(t_vec3 eye, t_vec3 target)
{
	t_perspective_camera	*cam;

	cam = (t_perspective_camera *)malloc(sizeof(t_perspective_camera));
	if (!cam)
		return (NULL);
	*cam = gl_new_perspective_camera(eye, target);
	return (cam);
}

t_perspective_camera	*gl_alloc_perspective_camera_with_label(t_vec3 eye,
		t_vec3 target, const char *label)
{
	t_perspective_camera	*cam;

	cam = gl_alloc_perspective_camera(eye, target);
	if (!cam)
		return (NULL);
	if (strlen(label) < GL_LABEL_MAX)
		strlcpy(cam->label, label, GL_LABEL_MAX);
	return (cam);
}
