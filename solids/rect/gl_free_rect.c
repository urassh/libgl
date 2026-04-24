#include <stdlib.h>
#include "libgl.h"

void	gl_free_rect(t_rect *rect)
{
	free(rect);
}
