CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -Wno-deprecated-declarations -I.
NAME	=	libgl.a

SRCS	=	solids/line/gl_create_line.c \
			solids/line/gl_color_line.c \
			solids/line/gl_draw_line.c \
			solids/rect/gl_create_rect.c \
			solids/rect/gl_color_rect.c \
			solids/rect/gl_outline_rect.c \
			solids/rect/gl_draw_rect.c \
			solids/cube/gl_create_cube.c \
			solids/cube/gl_color_cube.c \
			solids/cube/gl_colors_cube.c \
			solids/cube/gl_outline_cube.c \
			solids/cube/gl_draw_cube.c \
			solids/cone/gl_create_cone.c \
			solids/cone/gl_color_cone.c \
			solids/cone/gl_outline_cone.c \
			solids/cone/gl_draw_cone.c \
			solids/cylinder/gl_create_cylinder.c \
			solids/cylinder/gl_color_cylinder.c \
			solids/cylinder/gl_outline_cylinder.c \
			solids/cylinder/gl_draw_cylinder.c \
			params/vector/gl_vec3.c \
			params/color/gl_color.c \
			params/color/gl_colors.c \
			params/transform/gl_rotate.c \
			params/transform/gl_translate.c \
			params/transform/gl_scale.c \
			wires/rect/gl_create_wire_rect.c \
			wires/rect/gl_color_wire_rect.c \
			wires/rect/gl_draw_wire_rect.c \
			wires/cube/gl_create_wire_cube.c \
			wires/cube/gl_color_wire_cube.c \
			wires/cube/gl_draw_wire_cube.c \
			wires/cone/gl_create_wire_cone.c \
			wires/cone/gl_color_wire_cone.c \
			wires/cone/gl_slices_wire_cone.c \
			wires/cone/gl_stacks_wire_cone.c \
			wires/cone/gl_draw_wire_cone.c \
			wires/cylinder/gl_create_wire_cylinder.c \
			wires/cylinder/gl_color_wire_cylinder.c \
			wires/cylinder/gl_slices_wire_cylinder.c \
			wires/cylinder/gl_draw_wire_cylinder.c

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
