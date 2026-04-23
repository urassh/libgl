#include "libgl.h"

void	gl_draw_wire_rect(t_rect *rect)
{
	float	x;
	float	y;
	float	w;
	float	h;

	x = rect->origin.x;
	y = rect->origin.y;
	w = rect->size.x;
	h = rect->size.y;
	glPushMatrix();
	glTranslatef(rect->transform.offset.x,
		rect->transform.offset.y, rect->transform.offset.z);
	glRotatef(rect->transform.rotation.x, 1.0f, 0.0f, 0.0f);
	glRotatef(rect->transform.rotation.y, 0.0f, 1.0f, 0.0f);
	glRotatef(rect->transform.rotation.z, 0.0f, 0.0f, 1.0f);
	glScalef(rect->transform.scale.x,
		rect->transform.scale.y, rect->transform.scale.z);
	glColor3f(rect->color.r, rect->color.g, rect->color.b);
	glBegin(GL_LINE_LOOP);
	glVertex3f(x, y, rect->origin.z);
	glVertex3f(x + w, y, rect->origin.z);
	glVertex3f(x + w, y + h, rect->origin.z);
	glVertex3f(x, y + h, rect->origin.z);
	glEnd();
	glPopMatrix();
}
