#ifndef GL_CUBE_H
# define GL_CUBE_H

# include <stdbool.h>
# include "params/vector/gl_vector.h"
# include "params/color/gl_color.h"
# include "params/transform/gl_transform.h"

typedef struct s_cube
{
	t_vec3		origin;
	t_vec3		size;
	t_color		colors[6];
	bool		has_outline;
	t_color		outline_color;
	t_transform	transform;
}	t_cube;

t_cube	gl_create_cube(t_vec3 origin, t_vec3 size);
t_cube	*gl_alloc_cube(t_vec3 origin, t_vec3 size);
void	gl_free_cube(t_cube *cube);
void	gl_color_cube(t_cube *cube, t_color color);
void	gl_colors_cube(t_cube *cube, t_color colors[6]);
void	gl_outline_cube(t_cube *cube, t_color color);
void	gl_draw_cube(t_cube *cube);

#endif
