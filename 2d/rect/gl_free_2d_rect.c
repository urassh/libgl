#include <stdlib.h>
#include "libgl.h"

void	gl_free_2d_rect(t_2d_rect *rect)
{
	free(rect);
}
