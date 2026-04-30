#include "libgl.h"

void	gl_apply_ortho_camera(t_ortho_camera *cam)
{
	float	half_h;
	float	half_w;

	half_h = cam->ortho_size;
	half_w = cam->ortho_size * cam->aspect;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-half_w, half_w, -half_h, half_h,
		cam->near_clip, cam->far_clip);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(cam->eye.x, cam->eye.y, cam->eye.z,
		cam->target.x, cam->target.y, cam->target.z,
		cam->up.x, cam->up.y, cam->up.z);
}
