#include <string.h>
#include "libgl.h"

#define QUEUE_MAX 256

static char	*get_label(void *obj)
{
	return (((t_group *)obj)->label);
}

void	*gl_group_find(t_group *group, const char *label)
{
	t_group	*queue[QUEUE_MAX];
	int		front;
	int		back;
	int		i;

	front = 0;
	back = 0;
	queue[back++] = group;
	while (front < back)
	{
		i = 0;
		while (i < queue[front]->count)
		{
			if (strcmp(get_label(queue[front]->children[i].object),
					label) == 0)
				return (queue[front]->children[i].object);
			if (*(t_object_type *)queue[front]->children[i].object
				== GL_TYPE_GROUP && back < QUEUE_MAX)
				queue[back++] = (t_group *)queue[front]->children[i].object;
			i++;
		}
		front++;
	}
	return (NULL);
}
