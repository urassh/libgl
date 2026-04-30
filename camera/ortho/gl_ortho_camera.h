#ifndef GL_ORTHO_CAMERA_H
# define GL_ORTHO_CAMERA_H

# include <stdbool.h>
# include "params/object_type/gl_object_type.h"
# include "params/vector/gl_vector.h"

typedef struct s_ortho_camera
{
	t_object_type	type;
	char			label[32];
	t_vec3			eye;
	t_vec3			target;
	t_vec3			up;
	float			ortho_size;
	float			aspect;
	float			near_clip;
	float			far_clip;
}	t_ortho_camera;

t_ortho_camera	gl_new_ortho_camera(t_vec3 eye, t_vec3 target);
t_ortho_camera	gl_new_ortho_camera_with_label(t_vec3 eye, t_vec3 target,
					const char *label);
t_ortho_camera	*gl_alloc_ortho_camera(t_vec3 eye, t_vec3 target);
t_ortho_camera	*gl_alloc_ortho_camera_with_label(t_vec3 eye, t_vec3 target,
					const char *label);
void			gl_free_ortho_camera(t_ortho_camera *cam);
bool			gl_label_ortho_camera(t_ortho_camera *cam, const char *label);
void			gl_ortho_camera_look_at(t_ortho_camera *cam,
					t_vec3 eye, t_vec3 target, t_vec3 up);
void			gl_ortho_camera_lens(t_ortho_camera *cam,
					float ortho_size, float aspect,
					float near_clip, float far_clip);
void			gl_apply_ortho_camera(t_ortho_camera *cam);

#endif
