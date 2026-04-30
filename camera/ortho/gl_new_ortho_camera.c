#include <string.h>
#include "libgl.h"

t_ortho_camera	gl_new_ortho_camera(t_vec3 eye, t_vec3 target)
{
	t_ortho_camera	cam;

	cam.type = GL_TYPE_ORTHO_CAMERA;
	strlcpy(cam.label, "ortho_camera", GL_LABEL_MAX);
	cam.eye = eye;
	cam.target = target;
	cam.up = gl_vec3(0, 1, 0);
	cam.ortho_size = 1.0f;
	cam.aspect = 1.0f;
	cam.near_clip = 0.1f;
	cam.far_clip = 100.0f;
	return (cam);
}

t_ortho_camera	gl_new_ortho_camera_with_label(t_vec3 eye, t_vec3 target,
		const char *label)
{
	t_ortho_camera	cam;

	cam = gl_new_ortho_camera(eye, target);
	if (strlen(label) < GL_LABEL_MAX)
		strlcpy(cam.label, label, GL_LABEL_MAX);
	return (cam);
}
