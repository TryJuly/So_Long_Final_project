NAME = libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

INCLUDES = libft.h

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
	ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c \
	ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \
	ft_printf_char.c ft_printf_hexa.c ft_printf_number.c \
	ft_printf_void.c ft_printf.c get_next_line.c

OBJS = ${addprefix ${OBJ_DIR}/,${SRCS:.c=.o}}
OBJ_DIR = objets

all: ${NAME}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

${OBJ_DIR}/%.o: %.c ${INCLUDES}
	@mkdir -p ${OBJ_DIR}
	${CC} ${FLAGS} -c $< -o $@

clean:
	rm -rf ${OBJS} ${OBJ_DIR}/

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus