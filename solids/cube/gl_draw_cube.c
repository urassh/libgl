#include "libgl.h"

/*
** Face order: front, back, top, bottom, right, left
*/

static void	draw_face(t_vec3 v[4], t_color c)
{
	int	i;

	glColor3f(c.r, c.g, c.b);
	glBegin(GL_QUADS);
	i = 0;
	while (i < 4)
	{
		glVertex3f(v[i].x, v[i].y, v[i].z);
		i++;
	}
	glEnd();
}

void	gl_draw_cube(t_cube *cube)
{
	float	x;
	float	y;
	float	z;
	float	w;
	float	h;
	float	d;
	t_vec3	f[4];

	x = cube->origin.x;
	y = cube->origin.y;
	z = cube->origin.z;
	w = cube->size.x;
	h = cube->size.y;
	d = cube->size.z;
	glPushMatrix();
	glTranslatef(cube->transform.offset.x,
		cube->transform.offset.y, cube->transform.offset.z);
	glRotatef(cube->transform.rotation.x, 1.0f, 0.0f, 0.0f);
	glRotatef(cube->transform.rotation.y, 0.0f, 1.0f, 0.0f);
	glRotatef(cube->transform.rotation.z, 0.0f, 0.0f, 1.0f);
	glScalef(cube->transform.scale.x,
		cube->transform.scale.y, cube->transform.scale.z);
	f[0] = gl_vec3(x, y, z + d);
	f[1] = gl_vec3(x + w, y, z + d);
	f[2] = gl_vec3(x + w, y + h, z + d);
	f[3] = gl_vec3(x, y + h, z + d);
	draw_face(f, cube->colors[0]);
	f[0] = gl_vec3(x, y, z);
	f[1] = gl_vec3(x + w, y, z);
	f[2] = gl_vec3(x + w, y + h, z);
	f[3] = gl_vec3(x, y + h, z);
	draw_face(f, cube->colors[1]);
	f[0] = gl_vec3(x, y + h, z);
	f[1] = gl_vec3(x + w, y + h, z);
	f[2] = gl_vec3(x + w, y + h, z + d);
	f[3] = gl_vec3(x, y + h, z + d);
	draw_face(f, cube->colors[2]);
	f[0] = gl_vec3(x, y, z);
	f[1] = gl_vec3(x + w, y, z);
	f[2] = gl_vec3(x + w, y, z + d);
	f[3] = gl_vec3(x, y, z + d);
	draw_face(f, cube->colors[3]);
	f[0] = gl_vec3(x + w, y, z);
	f[1] = gl_vec3(x + w, y, z + d);
	f[2] = gl_vec3(x + w, y + h, z + d);
	f[3] = gl_vec3(x + w, y + h, z);
	draw_face(f, cube->colors[4]);
	f[0] = gl_vec3(x, y, z);
	f[1] = gl_vec3(x, y, z + d);
	f[2] = gl_vec3(x, y + h, z + d);
	f[3] = gl_vec3(x, y + h, z);
	draw_face(f, cube->colors[5]);
	if (cube->has_outline)
	{
		glColor3f(cube->outline_color.r, cube->outline_color.g,
			cube->outline_color.b);
		glBegin(GL_LINES);
		glVertex3f(x, y, z + d);
		glVertex3f(x + w, y, z + d);
		glVertex3f(x + w, y, z + d);
		glVertex3f(x + w, y + h, z + d);
		glVertex3f(x + w, y + h, z + d);
		glVertex3f(x, y + h, z + d);
		glVertex3f(x, y + h, z + d);
		glVertex3f(x, y, z + d);
		glVertex3f(x, y, z);
		glVertex3f(x + w, y, z);
		glVertex3f(x + w, y, z);
		glVertex3f(x + w, y + h, z);
		glVertex3f(x + w, y + h, z);
		glVertex3f(x, y + h, z);
		glVertex3f(x, y + h, z);
		glVertex3f(x, y, z);
		glVertex3f(x, y, z + d);
		glVertex3f(x, y, z);
		glVertex3f(x + w, y, z + d);
		glVertex3f(x + w, y, z);
		glVertex3f(x + w, y + h, z + d);
		glVertex3f(x + w, y + h, z);
		glVertex3f(x, y + h, z + d);
		glVertex3f(x, y + h, z);
		glEnd();
	}
	glPopMatrix();
}
