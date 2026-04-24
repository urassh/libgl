#include "libgl.h"

void	gl_2d_translate(t_2d_transform *tf, t_vec2 offset)
{
	tf->offset.x += offset.x;
	tf->offset.y += offset.y;
}
