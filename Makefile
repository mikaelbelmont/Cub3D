NAME	:=	cub3D

CC		:=	cc
CFLAGS	:= 	-O3 -g -Wall -Wextra -Werror -fsanitize=address -g
OPTFLAGS := -ffast-math -ffinite-math-only -flto
PATH_SRC		:=	./src
PATH_INCLUDES	:=	./incs
PATH_BUILD		:= ./build
PATH_OBJS		:= $(PATH_BUILD)/objs

MLX_L           := ./mlx_linux/libmlx_Linux.a

SRCS			:=	$(PATH_SRC)/main.c \
					$(PATH_SRC)/mlx_stuff.c \
					$(PATH_SRC)/init.c \
					$(PATH_SRC)/map.c \
					$(PATH_SRC)/movement.c \
					$(PATH_SRC)/rays.c \
					$(PATH_SRC)/rayutils.c \
					$(PATH_SRC)/horizontal_inter.c \
					$(PATH_SRC)/vertical_inter.c \
					$(PATH_SRC)/gun.c \
					$(PATH_SRC)/gnl.c \
					$(PATH_SRC)/utils.c \
					$(PATH_SRC)/utils2.c \
					$(PATH_SRC)/utils3.c \
					$(PATH_SRC)/parser.c \
					$(PATH_SRC)/parser2.c \
					$(PATH_SRC)/parse_map.c \
					$(PATH_SRC)/init_map.c \
					$(PATH_SRC)/map_close.c \
					$(PATH_SRC)/mlx_boosters.c \
					$(PATH_SRC)/keyhook.c \
					$(PATH_SRC)/utils_ter.c \
					$(PATH_SRC)/utils4.c \

OBJ				:= $(subst .c,.o,$(subst $(PATH_SRC), $(PATH_OBJS), $(SRCS)))

all:$(NAME)

$(NAME): $(MLX_L) $(OBJ)
		@$(CC) $(CFLAGS) $(OPTFLAGS) -o $(@) $^ -I$(PATH_INCLUDES) $(MLX_L) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

$(PATH_OBJS)/%.o: $(PATH_SRC)/%.c | $(PATH_BUILD)
		@$(CC) $(CFLAGS)  -c $(^) -o $@

$(PATH_BUILD):
		@mkdir -p $(PATH_BUILD)
		@mkdir -p $(PATH_OBJS) 

clean:
		@rm -rf $(PATH_OBJS)

$(MLX_L):
	@$(MAKE) -C ./mlx_linux --silent

fclean: clean
		@rm -rf $(PATH_BUILD) $(NAME)

re: fclean all
