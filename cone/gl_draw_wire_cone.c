#include "libgl.h"

void	gl_draw_wire_cone(t_cone *cone)
{
	glPushMatrix();
	glTranslatef(cone->transform.offset.x,
		cone->transform.offset.y, cone->transform.offset.z);
	glTranslatef(cone->origin.x, cone->origin.y, cone->origin.z);
	glRotatef(cone->transform.rotation.x, 1.0f, 0.0f, 0.0f);
	glRotatef(cone->transform.rotation.y, 0.0f, 1.0f, 0.0f);
	glRotatef(cone->transform.rotation.z, 0.0f, 0.0f, 1.0f);
	glScalef(cone->transform.scale.x,
		cone->transform.scale.y, cone->transform.scale.z);
	glColor3f(cone->color.r, cone->color.g, cone->color.b);
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glutWireCone(cone->radius, cone->height, cone->slices, cone->slices);
	glPopMatrix();
}
