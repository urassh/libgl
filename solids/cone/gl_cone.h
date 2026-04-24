#ifndef GL_CONE_H
# define GL_CONE_H

# include <stdbool.h>
# include "params/vector/gl_vector.h"
# include "params/color/gl_color.h"
# include "params/transform/gl_transform.h"

typedef struct s_cone
{
	t_vec3		origin;
	float		radius;
	float		height;
	int			slices;
	t_color		color;
	bool		has_outline;
	t_color		outline_color;
	t_transform	transform;
}	t_cone;

t_cone	gl_create_cone(t_vec3 origin, float radius, float height, int slices);
t_cone	*gl_alloc_cone(t_vec3 origin, float radius, float height, int slices);
void	gl_free_cone(t_cone *cone);
void	gl_color_cone(t_cone *cone, t_color color);
void	gl_outline_cone(t_cone *cone, t_color color);
void	gl_draw_cone(t_cone *cone);

#endif
