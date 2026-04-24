#include "libgl.h"

void	gl_2d_scale(t_2d_transform *tf, t_vec2 scale)
{
	tf->scale.x *= scale.x;
	tf->scale.y *= scale.y;
}
