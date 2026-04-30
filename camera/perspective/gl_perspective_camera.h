#ifndef GL_PERSPECTIVE_CAMERA_H
# define GL_PERSPECTIVE_CAMERA_H

# include <stdbool.h>
# include "params/object_type/gl_object_type.h"
# include "params/vector/gl_vector.h"

typedef struct s_perspective_camera
{
	t_object_type	type;
	char			label[32];
	t_vec3			eye;
	t_vec3			target;
	t_vec3			up;
	float			fovy;
	float			aspect;
	float			near_clip;
	float			far_clip;
}	t_perspective_camera;

t_perspective_camera	gl_new_perspective_camera(t_vec3 eye, t_vec3 target);
t_perspective_camera	gl_new_perspective_camera_with_label(t_vec3 eye,
							t_vec3 target, const char *label);
t_perspective_camera	*gl_alloc_perspective_camera(t_vec3 eye, t_vec3 target);
t_perspective_camera	*gl_alloc_perspective_camera_with_label(t_vec3 eye,
							t_vec3 target, const char *label);
void					gl_free_perspective_camera(t_perspective_camera *cam);
bool					gl_label_perspective_camera(t_perspective_camera *cam,
							const char *label);
void					gl_perspective_camera_look_at(
							t_perspective_camera *cam,
							t_vec3 eye, t_vec3 target, t_vec3 up);
void					gl_perspective_camera_lens(t_perspective_camera *cam,
							float fovy, float aspect,
							float near_clip, float far_clip);
void					gl_apply_perspective_camera(t_perspective_camera *cam);

#endif
