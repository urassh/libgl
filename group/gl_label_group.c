#include <string.h>
#include "libgl.h"

bool	gl_label_group(t_group *group, const char *label)
{
	if (strlen(label) >= GL_LABEL_MAX)
		return (false);
	strlcpy(group->label, label, GL_LABEL_MAX);
	return (true);
}
