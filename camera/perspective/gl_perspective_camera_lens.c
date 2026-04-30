#include "libgl.h"

void	gl_perspective_camera_lens(t_perspective_camera *cam,
	float fovy, float aspect, float near_clip, float far_clip)
{
	cam->fovy = fovy;
	cam->aspect = aspect;
	cam->near_clip = near_clip;
	cam->far_clip = far_clip;
}
