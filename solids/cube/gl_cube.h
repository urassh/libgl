#ifndef GL_CUBE_H
# define GL_CUBE_H

# include <stdbool.h>
# include "params/vector/gl_vector.h"
# include "params/color/gl_color.h"
# include "params/transform/gl_transform.h"

typedef struct s_cube
{
	char		label[32];
	t_vec3		origin;
	t_vec3		size;
	t_color		colors[6];
	bool		has_outline;
	t_color		outline_color;
	t_transform	transform;
}	t_cube;

t_cube	gl_new_cube(t_vec3 origin, t_vec3 size);
t_cube	gl_new_cube_with_label(t_vec3 origin, t_vec3 size,
			const char *label);
t_cube	*gl_alloc_cube(t_vec3 origin, t_vec3 size);
t_cube	*gl_alloc_cube_with_label(t_vec3 origin, t_vec3 size,
			const char *label);
void	gl_free_cube(t_cube *cube);
bool	gl_label_cube(t_cube *cube, const char *label);
void	gl_color_cube(t_cube *cube, t_color color);
void	gl_colors_cube(t_cube *cube, t_color colors[6]);
void	gl_outline_cube(t_cube *cube, t_color color);
void	gl_draw_cube(t_cube *cube);

#endif
