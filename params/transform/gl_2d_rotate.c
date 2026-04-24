#include "libgl.h"

void	gl_2d_rotate(t_2d_transform *tf, float angle)
{
	tf->rotation += angle;
}
