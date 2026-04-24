#include "libgl.h"

void	gl_draw_group(t_group *group)
{
	int	i;

	glPushMatrix();
	glTranslatef(group->transform.offset.x,
		group->transform.offset.y, group->transform.offset.z);
	glTranslatef(group->origin.x, group->origin.y, group->origin.z);
	glRotatef(group->transform.rotation.x, 1.0f, 0.0f, 0.0f);
	glRotatef(group->transform.rotation.y, 0.0f, 1.0f, 0.0f);
	glRotatef(group->transform.rotation.z, 0.0f, 0.0f, 1.0f);
	glScalef(group->transform.scale.x,
		group->transform.scale.y, group->transform.scale.z);
	i = 0;
	while (i < group->count)
	{
		group->children[i].draw(group->children[i].object);
		i++;
	}
	glPopMatrix();
}
