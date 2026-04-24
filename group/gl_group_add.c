#include "libgl.h"

void	gl_group_add(t_group *group, void *object, void (*draw)(void *))
{
	if (group->count >= GROUP_MAX_CHILDREN)
		return ;
	group->children[group->count].object = object;
	group->children[group->count].draw = draw;
	group->count++;
}
