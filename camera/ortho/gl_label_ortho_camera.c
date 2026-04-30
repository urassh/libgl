#include <string.h>
#include "libgl.h"

bool	gl_label_ortho_camera(t_ortho_camera *cam, const char *label)
{
	if (strlen(label) >= GL_LABEL_MAX)
		return (false);
	strlcpy(cam->label, label, GL_LABEL_MAX);
	return (true);
}
