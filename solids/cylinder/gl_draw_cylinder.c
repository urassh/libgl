#include "libgl.h"
#include <math.h>

#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif

static void	draw_side_and_caps(t_cylinder *cyl)
{
	float	a0;
	float	a1;
	float	r;
	int		i;

	r = cyl->radius;
	i = 0;
	while (i < cyl->slices)
	{
		a0 = 2.0f * M_PI * i / cyl->slices;
		a1 = 2.0f * M_PI * (i + 1) / cyl->slices;
		glBegin(GL_QUADS);
		glVertex3f(cyl->origin.x + r * cosf(a0), cyl->origin.y,
			cyl->origin.z + r * sinf(a0));
		glVertex3f(cyl->origin.x + r * cosf(a1), cyl->origin.y,
			cyl->origin.z + r * sinf(a1));
		glVertex3f(cyl->origin.x + r * cosf(a1), cyl->origin.y + cyl->height,
			cyl->origin.z + r * sinf(a1));
		glVertex3f(cyl->origin.x + r * cosf(a0), cyl->origin.y + cyl->height,
			cyl->origin.z + r * sinf(a0));
		glEnd();
		glBegin(GL_TRIANGLES);
		glVertex3f(cyl->origin.x, cyl->origin.y, cyl->origin.z);
		glVertex3f(cyl->origin.x + r * cosf(a1), cyl->origin.y,
			cyl->origin.z + r * sinf(a1));
		glVertex3f(cyl->origin.x + r * cosf(a0), cyl->origin.y,
			cyl->origin.z + r * sinf(a0));
		glEnd();
		glBegin(GL_TRIANGLES);
		glVertex3f(cyl->origin.x, cyl->origin.y + cyl->height, cyl->origin.z);
		glVertex3f(cyl->origin.x + r * cosf(a0), cyl->origin.y + cyl->height,
			cyl->origin.z + r * sinf(a0));
		glVertex3f(cyl->origin.x + r * cosf(a1), cyl->origin.y + cyl->height,
			cyl->origin.z + r * sinf(a1));
		glEnd();
		i++;
	}
}

static void	draw_outline(t_cylinder *cyl)
{
	float	a0;
	float	a1;
	float	r;
	int		i;

	r = cyl->radius;
	glColor3f(cyl->outline_color.r, cyl->outline_color.g,
		cyl->outline_color.b);
	i = 0;
	while (i < cyl->slices)
	{
		a0 = 2.0f * M_PI * i / cyl->slices;
		a1 = 2.0f * M_PI * (i + 1) / cyl->slices;
		glBegin(GL_LINES);
		glVertex3f(cyl->origin.x + r * cosf(a0), cyl->origin.y,
			cyl->origin.z + r * sinf(a0));
		glVertex3f(cyl->origin.x + r * cosf(a0), cyl->origin.y + cyl->height,
			cyl->origin.z + r * sinf(a0));
		glVertex3f(cyl->origin.x + r * cosf(a0), cyl->origin.y,
			cyl->origin.z + r * sinf(a0));
		glVertex3f(cyl->origin.x + r * cosf(a1), cyl->origin.y,
			cyl->origin.z + r * sinf(a1));
		glVertex3f(cyl->origin.x + r * cosf(a0), cyl->origin.y + cyl->height,
			cyl->origin.z + r * sinf(a0));
		glVertex3f(cyl->origin.x + r * cosf(a1), cyl->origin.y + cyl->height,
			cyl->origin.z + r * sinf(a1));
		glEnd();
		i++;
	}
}

void	gl_draw_cylinder(t_cylinder *cyl)
{
	glPushMatrix();
	glTranslatef(cyl->transform.offset.x,
		cyl->transform.offset.y, cyl->transform.offset.z);
	glRotatef(cyl->transform.rotation.x, 1.0f, 0.0f, 0.0f);
	glRotatef(cyl->transform.rotation.y, 0.0f, 1.0f, 0.0f);
	glRotatef(cyl->transform.rotation.z, 0.0f, 0.0f, 1.0f);
	glScalef(cyl->transform.scale.x,
		cyl->transform.scale.y, cyl->transform.scale.z);
	glColor3f(cyl->color.r, cyl->color.g, cyl->color.b);
	draw_side_and_caps(cyl);
	if (cyl->has_outline)
		draw_outline(cyl);
	glPopMatrix();
}
