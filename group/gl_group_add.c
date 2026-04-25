#include "libgl.h"

static void	(*g_draw_table[GL_TYPE_COUNT])(void *) = {
	[GL_TYPE_LINE] = (void (*)(void *))gl_draw_line,
	[GL_TYPE_RECT] = (void (*)(void *))gl_draw_rect,
	[GL_TYPE_CUBE] = (void (*)(void *))gl_draw_cube,
	[GL_TYPE_CONE] = (void (*)(void *))gl_draw_cone,
	[GL_TYPE_CYLINDER] = (void (*)(void *))gl_draw_cylinder,
	[GL_TYPE_WIRE_RECT] = (void (*)(void *))gl_draw_wire_rect,
	[GL_TYPE_WIRE_CUBE] = (void (*)(void *))gl_draw_wire_cube,
	[GL_TYPE_WIRE_CONE] = (void (*)(void *))gl_draw_wire_cone,
	[GL_TYPE_WIRE_CYLINDER] = (void (*)(void *))gl_draw_wire_cylinder,
	[GL_TYPE_GROUP] = (void (*)(void *))gl_draw_group,
	[GL_TYPE_2D_LINE] = (void (*)(void *))gl_draw_2d_line,
	[GL_TYPE_2D_RECT] = (void (*)(void *))gl_draw_2d_rect,
	[GL_TYPE_2D_WIRE_RECT] = (void (*)(void *))gl_draw_2d_wire_rect,
};

void	gl_group_add(t_group *group, void *object)
{
	t_object_type	type;

	if (group->count >= GROUP_MAX_CHILDREN)
		return ;
	type = *(t_object_type *)object;
	if (type < 0 || type >= GL_TYPE_COUNT || !g_draw_table[type])
		return ;
	group->children[group->count].object = object;
	group->children[group->count].draw = g_draw_table[type];
	group->count++;
}
