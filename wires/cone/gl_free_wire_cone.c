#include <stdlib.h>
#include "libgl.h"

void	gl_free_wire_cone(t_wire_cone *cone)
{
	free(cone);
}
