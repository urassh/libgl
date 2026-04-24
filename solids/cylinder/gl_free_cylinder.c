#include <stdlib.h>
#include "libgl.h"

void	gl_free_cylinder(t_cylinder *cyl)
{
	free(cyl);
}
