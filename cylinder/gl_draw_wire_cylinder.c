#include "libgl.h"

void	gl_draw_wire_cylinder(t_cylinder *cyl)
{
	GLUquadric	*q;

	glPushMatrix();
	glTranslatef(cyl->transform.offset.x,
		cyl->transform.offset.y, cyl->transform.offset.z);
	glTranslatef(cyl->origin.x, cyl->origin.y, cyl->origin.z);
	glRotatef(cyl->transform.rotation.x, 1.0f, 0.0f, 0.0f);
	glRotatef(cyl->transform.rotation.y, 0.0f, 1.0f, 0.0f);
	glRotatef(cyl->transform.rotation.z, 0.0f, 0.0f, 1.0f);
	glScalef(cyl->transform.scale.x,
		cyl->transform.scale.y, cyl->transform.scale.z);
	glColor3f(cyl->color.r, cyl->color.g, cyl->color.b);
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	q = gluNewQuadric();
	gluQuadricDrawStyle(q, GLU_LINE);
	gluCylinder(q, cyl->radius, cyl->radius, cyl->height,
		cyl->slices, 1);
	gluDeleteQuadric(q);
	glPopMatrix();
}
