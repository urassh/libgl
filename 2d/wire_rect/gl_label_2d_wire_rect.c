#include <string.h>
#include "libgl.h"

bool	gl_label_2d_wire_rect(t_2d_wire_rect *rect, const char *label)
{
	if (strlen(label) >= GL_LABEL_MAX)
		return (false);
	strlcpy(rect->label, label, GL_LABEL_MAX);
	return (true);
}
