#include "libgl.h"

void	gl_draw_line(t_line *line)
{
	glPushMatrix();
	glTranslatef(line->transform.offset.x,
		line->transform.offset.y, line->transform.offset.z);
	glRotatef(line->transform.rotation.x, 1.0f, 0.0f, 0.0f);
	glRotatef(line->transform.rotation.y, 0.0f, 1.0f, 0.0f);
	glRotatef(line->transform.rotation.z, 0.0f, 0.0f, 1.0f);
	glScalef(line->transform.scale.x,
		line->transform.scale.y, line->transform.scale.z);
	glColor3f(line->color.r, line->color.g, line->color.b);
	glBegin(GL_LINES);
	glVertex3f(line->start.x, line->start.y, line->start.z);
	glVertex3f(line->end.x, line->end.y, line->end.z);
	glEnd();
	glPopMatrix();
}
