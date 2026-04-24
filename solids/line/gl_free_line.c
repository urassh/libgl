#include <stdlib.h>
#include "libgl.h"

void	gl_free_line(t_line *line)
{
	free(line);
}
