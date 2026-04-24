CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -Wno-deprecated-declarations -I.
NAME	=	libgl.a

SRCS	=	solids/line/gl_new_line.c \
			solids/line/gl_alloc_line.c \
			solids/line/gl_free_line.c \
			solids/line/gl_label_line.c \
			solids/line/gl_color_line.c \
			solids/line/gl_draw_line.c \
			solids/rect/gl_new_rect.c \
			solids/rect/gl_alloc_rect.c \
			solids/rect/gl_free_rect.c \
			solids/rect/gl_label_rect.c \
			solids/rect/gl_color_rect.c \
			solids/rect/gl_outline_rect.c \
			solids/rect/gl_draw_rect.c \
			solids/cube/gl_new_cube.c \
			solids/cube/gl_alloc_cube.c \
			solids/cube/gl_free_cube.c \
			solids/cube/gl_label_cube.c \
			solids/cube/gl_color_cube.c \
			solids/cube/gl_colors_cube.c \
			solids/cube/gl_outline_cube.c \
			solids/cube/gl_draw_cube.c \
			solids/cone/gl_new_cone.c \
			solids/cone/gl_alloc_cone.c \
			solids/cone/gl_free_cone.c \
			solids/cone/gl_label_cone.c \
			solids/cone/gl_color_cone.c \
			solids/cone/gl_outline_cone.c \
			solids/cone/gl_draw_cone.c \
			solids/cylinder/gl_new_cylinder.c \
			solids/cylinder/gl_alloc_cylinder.c \
			solids/cylinder/gl_free_cylinder.c \
			solids/cylinder/gl_label_cylinder.c \
			solids/cylinder/gl_color_cylinder.c \
			solids/cylinder/gl_outline_cylinder.c \
			solids/cylinder/gl_draw_cylinder.c \
			params/vector/gl_vec3.c \
			params/vector/gl_vec2.c \
			params/color/gl_color.c \
			params/color/gl_colors.c \
			params/transform/gl_rotate.c \
			params/transform/gl_translate.c \
			params/transform/gl_scale.c \
			params/transform/gl_2d_rotate.c \
			params/transform/gl_2d_translate.c \
			params/transform/gl_2d_scale.c \
			wires/rect/gl_new_wire_rect.c \
			wires/rect/gl_alloc_wire_rect.c \
			wires/rect/gl_free_wire_rect.c \
			wires/rect/gl_label_wire_rect.c \
			wires/rect/gl_color_wire_rect.c \
			wires/rect/gl_draw_wire_rect.c \
			wires/cube/gl_new_wire_cube.c \
			wires/cube/gl_alloc_wire_cube.c \
			wires/cube/gl_free_wire_cube.c \
			wires/cube/gl_label_wire_cube.c \
			wires/cube/gl_color_wire_cube.c \
			wires/cube/gl_draw_wire_cube.c \
			wires/cone/gl_new_wire_cone.c \
			wires/cone/gl_alloc_wire_cone.c \
			wires/cone/gl_free_wire_cone.c \
			wires/cone/gl_label_wire_cone.c \
			wires/cone/gl_color_wire_cone.c \
			wires/cone/gl_slices_wire_cone.c \
			wires/cone/gl_stacks_wire_cone.c \
			wires/cone/gl_draw_wire_cone.c \
			wires/cylinder/gl_new_wire_cylinder.c \
			wires/cylinder/gl_alloc_wire_cylinder.c \
			wires/cylinder/gl_free_wire_cylinder.c \
			wires/cylinder/gl_label_wire_cylinder.c \
			wires/cylinder/gl_color_wire_cylinder.c \
			wires/cylinder/gl_slices_wire_cylinder.c \
			wires/cylinder/gl_draw_wire_cylinder.c \
			group/gl_new_group.c \
			group/gl_alloc_group.c \
			group/gl_free_group.c \
			group/gl_label_group.c \
			group/gl_group_add.c \
			group/gl_group_find.c \
			group/gl_draw_group.c \
			2d/line/gl_new_2d_line.c \
			2d/line/gl_alloc_2d_line.c \
			2d/line/gl_free_2d_line.c \
			2d/line/gl_label_2d_line.c \
			2d/line/gl_color_2d_line.c \
			2d/line/gl_draw_2d_line.c \
			2d/rect/gl_new_2d_rect.c \
			2d/rect/gl_alloc_2d_rect.c \
			2d/rect/gl_free_2d_rect.c \
			2d/rect/gl_label_2d_rect.c \
			2d/rect/gl_color_2d_rect.c \
			2d/rect/gl_outline_2d_rect.c \
			2d/rect/gl_draw_2d_rect.c \
			2d/wire_rect/gl_new_2d_wire_rect.c \
			2d/wire_rect/gl_alloc_2d_wire_rect.c \
			2d/wire_rect/gl_free_2d_wire_rect.c \
			2d/wire_rect/gl_label_2d_wire_rect.c \
			2d/wire_rect/gl_color_2d_wire_rect.c \
			2d/wire_rect/gl_draw_2d_wire_rect.c

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			@ar crs $(NAME) $(OBJS)
			@echo "libgl.a ready"

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
			@rm -f $(OBJS)

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
