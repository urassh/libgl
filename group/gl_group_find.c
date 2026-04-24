#include <string.h>
#include "libgl.h"

void	*gl_group_find(t_group *group, const char *label)
{
	int	i;

	i = 0;
	while (i < group->count)
	{
		if (strcmp((char *)group->children[i].object, label) == 0)
			return (group->children[i].object);
		i++;
	}
	return (NULL);
}
