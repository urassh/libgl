#ifndef GL_GROUP_H
# define GL_GROUP_H

# include <stdbool.h>
# include <stddef.h>
# include "params/object_type/gl_object_type.h"
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
	t_object_type	type;
	char			label[32];
	t_vec3			origin;
	t_transform		transform;
	t_group_child	children[GROUP_MAX_CHILDREN];
	int				count;
}	t_group;

t_group	gl_new_group(t_vec3 origin);
t_group	gl_new_group_with_label(t_vec3 origin, const char *label);
t_group	*gl_alloc_group(t_vec3 origin);
t_group	*gl_alloc_group_with_label(t_vec3 origin, const char *label);
void	gl_free_group(t_group *group);
bool	gl_label_group(t_group *group, const char *label);
void	gl_group_add(t_group *group, void *object, void (*draw)(void *));
void	*gl_group_find(t_group *group, const char *label);
void	gl_draw_group(t_group *group);

#endif
