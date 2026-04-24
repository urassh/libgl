#include "libgl.h"

void	gl_draw_2d_line(t_2d_line *line)
{
	glPushMatrix();
	glTranslatef(line->transform.offset.x,
		line->transform.offset.y, 0.0f);
	glRotatef(line->transform.rotation, 0.0f, 0.0f, 1.0f);
	glScalef(line->transform.scale.x,
		line->transform.scale.y, 1.0f);
	glColor3f(line->color.r, line->color.g, line->color.b);
	glBegin(GL_LINES);
	glVertex2f(line->start.x, line->start.y);
	glVertex2f(line->end.x, line->end.y);
	glEnd();
	glPopMatrix();
}
