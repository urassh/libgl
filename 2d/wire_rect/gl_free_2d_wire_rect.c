#include <stdlib.h>
#include "libgl.h"

void	gl_free_2d_wire_rect(t_2d_wire_rect *rect)
{
	free(rect);
}
