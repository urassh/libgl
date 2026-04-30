#include <string.h>
#include "libgl.h"

t_perspective_camera	gl_new_perspective_camera(t_vec3 eye, t_vec3 target)
{
	t_perspective_camera	cam;

	cam.type = GL_TYPE_PERSPECTIVE_CAMERA;
	strlcpy(cam.label, "perspective_camera", GL_LABEL_MAX);
	cam.eye = eye;
	cam.target = target;
	cam.up = gl_vec3(0, 1, 0);
	cam.fovy = 45.0f;
	cam.aspect = 1.0f;
	cam.near_clip = 0.1f;
	cam.far_clip = 100.0f;
	return (cam);
}

t_perspective_camera	gl_new_perspective_camera_with_label(t_vec3 eye,
		t_vec3 target, const char *label)
{
	t_perspective_camera	cam;

	cam = gl_new_perspective_camera(eye, target);
	if (strlen(label) < GL_LABEL_MAX)
		strlcpy(cam.label, label, GL_LABEL_MAX);
	return (cam);
}
