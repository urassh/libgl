#include <stdlib.h>
#include "libgl.h"

void	gl_free_perspective_camera(t_perspective_camera *cam)
{
	free(cam);
}
