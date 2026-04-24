#include <string.h>
#include "libgl.h"

bool	gl_label_cone(t_cone *cone, const char *label)
{
	if (strlen(label) >= GL_LABEL_MAX)
		return (false);
	strlcpy(cone->label, label, GL_LABEL_MAX);
	return (true);
}
