#include <stdlib.h>
#include "libgl.h"

void	gl_free_wire_rect(t_wire_rect *rect)
{
	free(rect);
}
