#include "libgl.h"

void	gl_ortho_camera_look_at(t_ortho_camera *cam,
	t_vec3 eye, t_vec3 target, t_vec3 up)
{
	cam->eye = eye;
	cam->target = target;
	cam->up = up;
}
