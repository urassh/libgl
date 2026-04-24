#ifndef GL_GROUP_H
# define GL_GROUP_H

# include <stddef.h>
# include "params/vector/gl_vector.h"
# include "params/transform/gl_transform.h"

# define GROUP_MAX_CHILDREN 32

typedef struct s_group_child
{
	void	*object;
	void	(*draw)(void *object);
}	t_group_child;

typedef struct s_group
{
	t_vec3			origin;
	t_transform		transform;
	t_group_child	children[GROUP_MAX_CHILDREN];
	int				count;
}	t_group;

t_group	gl_create_group(t_vec3 origin);
void	gl_group_add(t_group *group, void *object, void (*draw)(void *));
void	gl_draw_group(t_group *group);

#endif
