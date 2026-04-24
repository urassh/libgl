#include <string.h>
#include "libgl.h"

bool	gl_label_rect(t_rect *rect, const char *label)
{
	if (strlen(label) >= GL_LABEL_MAX)
		return (false);
	strlcpy(rect->label, label, GL_LABEL_MAX);
	return (true);
}
