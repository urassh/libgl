#ifndef LIBGL_H
# define LIBGL_H

# include <stdbool.h>

# ifdef __APPLE__
#  define GL_SILENCE_DEPRECATION
#  include <GLUT/glut.h>
#  include <OpenGL/gl.h>
#  include <OpenGL/glu.h>
# else
#  include "GL/glut.h"
#  include "GL/gl.h"
#  include "GL/glu.h"
# endif

/* ========== types ========== */

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef struct s_color
{
	float	r;
	float	g;
	float	b;
}	t_color;

typedef struct s_transform
{
	t_vec3	rotation;
	t_vec3	offset;
	t_vec3	scale;
}	t_transform;

typedef struct s_line
{
	t_vec3		start;
	t_vec3		end;
	t_color		color;
	t_transform	transform;
}	t_line;

typedef struct s_rect
{
	t_vec3		origin;
	t_vec3		size;
	t_color		color;
	bool		has_outline;
	t_color		outline_color;
	t_transform	transform;
}	t_rect;

typedef struct s_cube
{
	t_vec3		origin;
	t_vec3		size;
	t_color		colors[6];
	bool		has_outline;
	t_color		outline_color;
	t_transform	transform;
}	t_cube;

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

typedef struct s_cylinder
{
	t_vec3		origin;
	float		radius;
	float		height;
	int			slices;
	t_color		color;
	bool		has_outline;
	t_color		outline_color;
	t_transform	transform;
}	t_cylinder;

/* ========== color macros (3 floats) ========== */

# define RED     1.0f, 0.0f, 0.0f
# define GREEN   0.0f, 1.0f, 0.0f
# define BLUE    0.0f, 0.0f, 1.0f
# define YELLOW  1.0f, 1.0f, 0.0f
# define CYAN    0.0f, 1.0f, 1.0f
# define MAGENTA 1.0f, 0.0f, 1.0f
# define WHITE   1.0f, 1.0f, 1.0f
# define BLACK   0.0f, 0.0f, 0.0f

/* ========== create ========== */

t_line	gl_create_line(t_vec3 start, t_vec3 end);
t_rect	gl_create_rect(t_vec3 origin, t_vec3 size);
t_cube	gl_create_cube(t_vec3 origin, t_vec3 size);

t_cone		gl_create_cone(t_vec3 origin, float radius, float height, int slices);
t_cylinder	gl_create_cylinder(t_vec3 origin, float radius, float height,
				int slices);

/* ========== color ========== */

void	gl_color_line(t_line *line, t_color color);
void	gl_color_rect(t_rect *rect, t_color color);
void	gl_color_cube(t_cube *cube, t_color color);
void	gl_colors_cube(t_cube *cube, t_color colors[6]);
void	gl_outline_rect(t_rect *rect, t_color color);
void	gl_outline_cube(t_cube *cube, t_color color);
void	gl_color_cone(t_cone *cone, t_color color);
void	gl_outline_cone(t_cone *cone, t_color color);
void	gl_color_cylinder(t_cylinder *cyl, t_color color);
void	gl_outline_cylinder(t_cylinder *cyl, t_color color);

/* ========== transform ========== */

void	gl_rotate(t_transform *tf, t_vec3 angle);
void	gl_translate(t_transform *tf, t_vec3 offset);
void	gl_scale(t_transform *tf, t_vec3 scale);

/* ========== draw ========== */

void	gl_draw_line(t_line *line);
void	gl_draw_rect(t_rect *rect);
void	gl_draw_wire_rect(t_rect *rect);
void	gl_draw_cube(t_cube *cube);
void	gl_draw_cone(t_cone *cone);
void	gl_draw_wire_cone(t_cone *cone, int slices, int stacks);
void	gl_draw_cylinder(t_cylinder *cyl);
void	gl_draw_wire_cylinder(t_cylinder *cyl);

/* ========== utility ========== */

t_vec3	gl_vec3(float x, float y, float z);
t_color	gl_color(float r, float g, float b);

/* ========== color functions ========== */

t_color	gl_red(void);
t_color	gl_green(void);
t_color	gl_blue(void);
t_color	gl_yellow(void);
t_color	gl_cyan(void);
t_color	gl_magenta(void);
t_color	gl_white(void);
t_color	gl_black(void);

#endif
