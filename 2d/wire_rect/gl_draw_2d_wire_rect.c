#include "libgl.h"

void	gl_draw_2d_wire_rect(t_2d_wire_rect *rect)
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
		rect->transform.offset.y, 0.0f);
	glRotatef(rect->transform.rotation, 0.0f, 0.0f, 1.0f);
	glScalef(rect->transform.scale.x,
		rect->transform.scale.y, 1.0f);
	glColor3f(rect->color.r, rect->color.g, rect->color.b);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x, y);
	glVertex2f(x + w, y);
	glVertex2f(x + w, y + h);
	glVertex2f(x, y + h);
	glEnd();
	glPopMatrix();
}
