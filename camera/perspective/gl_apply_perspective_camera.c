#include "libgl.h"

void	gl_apply_perspective_camera(t_perspective_camera *cam)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(cam->fovy, cam->aspect, cam->near_clip, cam->far_clip);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(cam->eye.x, cam->eye.y, cam->eye.z,
		cam->target.x, cam->target.y, cam->target.z,
		cam->up.x, cam->up.y, cam->up.z);
}
