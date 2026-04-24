#include <string.h>
#include "libgl.h"

bool	gl_label_cube(t_cube *cube, const char *label)
{
	if (strlen(label) >= GL_LABEL_MAX)
		return (false);
	strlcpy(cube->label, label, GL_LABEL_MAX);
	return (true);
}
