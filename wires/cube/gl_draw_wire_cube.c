#include "libgl.h"

void	gl_draw_wire_cube(t_wire_cube *cube)
{
	float	x;
	float	y;
	float	z;
	float	w;
	float	h;
	float	d;

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
	glColor3f(cube->color.r, cube->color.g, cube->color.b);
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
	glPopMatrix();
}
