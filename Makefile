CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -Wno-deprecated-declarations -I.
NAME	=	libgl.a

SRCS	=	line/gl_create_line.c \
			line/gl_color_line.c \
			line/gl_draw_line.c \
			rect/gl_create_rect.c \
			rect/gl_color_rect.c \
			rect/gl_outline_rect.c \
			rect/gl_draw_rect.c \
			cube/gl_create_cube.c \
			cube/gl_color_cube.c \
			cube/gl_colors_cube.c \
			cube/gl_outline_cube.c \
			cube/gl_draw_cube.c \
			params/vector/gl_vec3.c \
			params/color/gl_color.c \
			params/color/gl_colors.c \
			params/transform/gl_rotate.c \
			params/transform/gl_translate.c \
			params/transform/gl_scale.c \
			cone/gl_create_cone.c \
			cone/gl_color_cone.c \
			cone/gl_outline_cone.c \
			cone/gl_draw_cone.c \
			cylinder/gl_create_cylinder.c \
			cylinder/gl_color_cylinder.c \
			cylinder/gl_outline_cylinder.c \
			cylinder/gl_draw_cylinder.c \
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
