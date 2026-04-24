#include <stdlib.h>
#include "libgl.h"

void	gl_free_wire_cylinder(t_wire_cylinder *cyl)
{
	free(cyl);
}
