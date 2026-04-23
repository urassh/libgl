#include "libgl.h"

void	gl_translate(t_transform *tf, t_vec3 offset)
{
	tf->offset.x += offset.x;
	tf->offset.y += offset.y;
	tf->offset.z += offset.z;
}
