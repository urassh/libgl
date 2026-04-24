#include <string.h>
#include "libgl.h"

bool	gl_label_wire_cylinder(t_wire_cylinder *cyl, const char *label)
{
	if (strlen(label) >= GL_LABEL_MAX)
		return (false);
	strlcpy(cyl->label, label, GL_LABEL_MAX);
	return (true);
}
