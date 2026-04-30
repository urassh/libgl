#include <stdlib.h>
#include <string.h>
#include "libgl.h"

t_ortho_camera	*gl_alloc_ortho_camera(t_vec3 eye, t_vec3 target)
{
	t_ortho_camera	*cam;

	cam = (t_ortho_camera *)malloc(sizeof(t_ortho_camera));
	if (!cam)
		return (NULL);
	*cam = gl_new_ortho_camera(eye, target);
	return (cam);
}

t_ortho_camera	*gl_alloc_ortho_camera_with_label(t_vec3 eye, t_vec3 target,
		const char *label)
{
	t_ortho_camera	*cam;

	cam = gl_alloc_ortho_camera(eye, target);
	if (!cam)
		return (NULL);
	if (strlen(label) < GL_LABEL_MAX)
		strlcpy(cam->label, label, GL_LABEL_MAX);
	return (cam);
}
