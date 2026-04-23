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
			util/gl_util.c \
			util/gl_colors.c \
			util/gl_rotate.c \
			util/gl_translate.c \
			util/gl_scale.c

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
