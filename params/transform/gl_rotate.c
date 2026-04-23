#include "libgl.h"

void	gl_rotate(t_transform *tf, t_vec3 angle)
{
	tf->rotation.x += angle.x;
	tf->rotation.y += angle.y;
	tf->rotation.z += angle.z;
}
