#################################################################################################################
#                                           VARIABLES SET                                                       #
#################################################################################################################
NAME = so_long

CC = gcc
FLAGS = -Wall -Wextra -Werror -g

SRCS = main.c map_check.c map_check_v2.c valid_extension.c tool_player.c \
	free.c tool_mlx.c print.c init_structure.c print_image.c \
	texture.c tool_hooks.c

SRCS_BONUS = bonus/main_bonus.c bonus/map_check_bonus.c bonus/map_check_v2_bonus.c \
	bonus/valid_extension_bonus.c bonus/tool_player_bonus.c bonus/free_bonus.c \
	bonus/tool_mlx_bonus.c bonus/init_structure_bonus.c bonus/print_image_bonus.c \
	bonus/texture_bonus.c bonus/print_bonus.c bonus/tool_hooks_bonus.c
 
UNAME_S = ${shell uname -s}

INCLUDES = so_long.h

INCLUDES_BONUS = ./bonus/so_long_bonus.h


ifeq (${UNAME_S}, Linux)
	EXTRA = -L${MINILIBX} -lXext -lX11 -lm -lz
else ifeq (${UNAME_S}, Darwin)
	EXTRA = -L${MINILIBX} -lmlx -framework OpenGl -framework AppKit
endif

LIBFT = ./libft/
LIBFT_A= ./libft.a

MINILIBX = ./minilibx
MINILIBX_A = ./libmlx.a

LIB = ${MINILIBX_A} ${LIBFT_A}

OBJS = ${addprefix ${OBJ_DIR}/,${SRCS:.c=.o}}
OBJ_DIR = objets
#################################################################################################################
#                                           RULES COMPILATION                                                   #
#################################################################################################################
all: ${LIBFT_A} ${MINILIBX_A} ${NAME}

${NAME}: ${OBJS}
	${CC} ${FLAGS} ${OBJS} ${LIB} ${EXTRA} -I ${INCLUDES} -o ${NAME}

${OBJ_DIR}/%.o: %.c ${INCLUDES}
	@mkdir -p ${OBJ_DIR}
	${CC} ${FLAGS} -c $< -o $@

${LIBFT_A}:
	@make -C ${LIBFT}
	@cd ${LIBFT} && cp ${LIBFT_A} ..

${MINILIBX_A}:
	@make -C ${MINILIBX}
	@cd ${MINILIBX} && cp ${MINILIBX_A} ..
#################################################################################################################
#                                           RULES CLEAN                                                         #
#################################################################################################################
clean:
	rm -rf ${OBJ_DIR}/ ${OBJS}
	rm -rf ${OBJ_DIR_BONUS}/ ${OBJS_BONUS}

clean_lib:
	@make clean -C ${LIBFT}
	@make clean -C ${MINILIBX}

fclean: clean
	rm -rf ${NAME} ${MINILIBX_A} ${LIBFT_A} ${BONUS_NAME}

fclean_lib: clean_lib
	@make fclean -C ${LIBFT}
	@rm -rf ${LIBFT_A}
	@make clean -C ${MINILIBX}
	@rm -rf ${MINILIBX_A}

re: fclean fclean_lib all
#################################################################################################################
#                                           NO RELINK                                                           #
#################################################################################################################

.PHONY: all clean fclean re clean_lib fclean_lib bonus

#################################################################################################################
#                                           BONUS	                                                            #
#################################################################################################################
BONUS_NAME = so_long_bonus

OBJ_DIR_BONUS = bonus/objets_bonus
OBJS_BONUS = ${SRCS_BONUS:bonus/%.c=${OBJ_DIR_BONUS}/%.o}

${OBJ_DIR_BONUS}/%.o: bonus/%.c ${INCLUDES_BONUS}
	@mkdir -p ${OBJ_DIR_BONUS}
	${CC} ${FLAGS} -c $< -o $@

${BONUS_NAME}: ${OBJS_BONUS}
	${CC} ${FLAGS} ${OBJS_BONUS} ${LIB} ${EXTRA} -I ${INCLUDES_BONUS} -o ${BONUS_NAME}

bonus: ${MINILIBX_A} ${LIBFT_A} ${BONUS_NAME}