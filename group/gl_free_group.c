#include <stdlib.h>
#include "libgl.h"

void	gl_free_group(t_group *group)
{
	free(group);
}
