#include <string.h>
#include "libgl.h"

bool	gl_label_perspective_camera(t_perspective_camera *cam,
	const char *label)
{
	if (strlen(label) >= GL_LABEL_MAX)
		return (false);
	strlcpy(cam->label, label, GL_LABEL_MAX);
	return (true);
}
