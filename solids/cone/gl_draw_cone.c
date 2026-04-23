#include "libgl.h"
#include <math.h>

#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif

void	gl_draw_cone(t_cone *cone)
{
	float	x;
	float	y;
	float	z;
	float	r;
	float	h;
	int		i;
	float	a0;
	float	a1;

	x = cone->origin.x;
	y = cone->origin.y;
	z = cone->origin.z;
	r = cone->radius;
	h = cone->height;
	glPushMatrix();
	glTranslatef(cone->transform.offset.x,
		cone->transform.offset.y, cone->transform.offset.z);
	glRotatef(cone->transform.rotation.x, 1.0f, 0.0f, 0.0f);
	glRotatef(cone->transform.rotation.y, 0.0f, 1.0f, 0.0f);
	glRotatef(cone->transform.rotation.z, 0.0f, 0.0f, 1.0f);
	glScalef(cone->transform.scale.x,
		cone->transform.scale.y, cone->transform.scale.z);
	glColor3f(cone->color.r, cone->color.g, cone->color.b);
	i = 0;
	while (i < cone->slices)
	{
		a0 = 2.0f * M_PI * i / cone->slices;
		a1 = 2.0f * M_PI * (i + 1) / cone->slices;
		glBegin(GL_TRIANGLES);
		glVertex3f(x, y + h, z);
		glVertex3f(x + r * cosf(a0), y, z + r * sinf(a0));
		glVertex3f(x + r * cosf(a1), y, z + r * sinf(a1));
		glEnd();
		glBegin(GL_TRIANGLES);
		glVertex3f(x, y, z);
		glVertex3f(x + r * cosf(a1), y, z + r * sinf(a1));
		glVertex3f(x + r * cosf(a0), y, z + r * sinf(a0));
		glEnd();
		i++;
	}
	if (cone->has_outline)
	{
		glColor3f(cone->outline_color.r, cone->outline_color.g,
			cone->outline_color.b);
		i = 0;
		while (i < cone->slices)
		{
			a0 = 2.0f * M_PI * i / cone->slices;
			a1 = 2.0f * M_PI * (i + 1) / cone->slices;
			glBegin(GL_LINES);
			glVertex3f(x, y + h, z);
			glVertex3f(x + r * cosf(a0), y, z + r * sinf(a0));
			glVertex3f(x + r * cosf(a0), y, z + r * sinf(a0));
			glVertex3f(x + r * cosf(a1), y, z + r * sinf(a1));
			glEnd();
			i++;
		}
	}
	glPopMatrix();
}
