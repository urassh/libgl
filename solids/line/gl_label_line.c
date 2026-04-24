#include <string.h>
#include "libgl.h"

bool	gl_label_line(t_line *line, const char *label)
{
	if (strlen(label) >= GL_LABEL_MAX)
		return (false);
	strlcpy(line->label, label, GL_LABEL_MAX);
	return (true);
}
