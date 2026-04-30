#include "libgl.h"

void	gl_ortho_camera_lens(t_ortho_camera *cam,
	float ortho_size, float aspect, float near_clip, float far_clip)
{
	cam->ortho_size = ortho_size;
	cam->aspect = aspect;
	cam->near_clip = near_clip;
	cam->far_clip = far_clip;
}
