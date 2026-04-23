#include "libgl.h"

void	gl_scale(t_transform *tf, t_vec3 scale)
{
	tf->scale.x *= scale.x;
	tf->scale.y *= scale.y;
	tf->scale.z *= scale.z;
}
