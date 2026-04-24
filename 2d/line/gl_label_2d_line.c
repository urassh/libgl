#include <string.h>
#include "libgl.h"

bool	gl_label_2d_line(t_2d_line *line, const char *label)
{
	if (strlen(label) >= GL_LABEL_MAX)
		return (false);
	strlcpy(line->label, label, GL_LABEL_MAX);
	return (true);
}
