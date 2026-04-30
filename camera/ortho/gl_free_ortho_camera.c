#include <stdlib.h>
#include "libgl.h"

void	gl_free_ortho_camera(t_ortho_camera *cam)
{
	free(cam);
}
