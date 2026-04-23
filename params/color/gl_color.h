#ifndef GL_COLOR_H
# define GL_COLOR_H

typedef struct s_color
{
	float	r;
	float	g;
	float	b;
}	t_color;

# define RED     1.0f, 0.0f, 0.0f
# define GREEN   0.0f, 1.0f, 0.0f
# define BLUE    0.0f, 0.0f, 1.0f
# define YELLOW  1.0f, 1.0f, 0.0f
# define CYAN    0.0f, 1.0f, 1.0f
# define MAGENTA 1.0f, 0.0f, 1.0f
# define WHITE   1.0f, 1.0f, 1.0f
# define BLACK   0.0f, 0.0f, 0.0f

t_color	gl_color(float r, float g, float b);
t_color	gl_red(void);
t_color	gl_green(void);
t_color	gl_blue(void);
t_color	gl_yellow(void);
t_color	gl_cyan(void);
t_color	gl_magenta(void);
t_color	gl_white(void);
t_color	gl_black(void);

#endif
