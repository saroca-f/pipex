NAME = pipex
NAME2 = pipex_bonus
CC = gcc
CFLAGS = -g -Wall -Werror -Wextra
PRINTF_PATH = ./printf
PRINT = $(PRINTF_PATH)/libftprintf.a


SRCS = 	./SRC/pipex.c \
		./SRC/argument_control.c \
		./utils/free_matrix.c \
		./utils/ft_split.c \
		./utils/ft_strcmp.c \
		./utils/ft_strdup.c \
		./utils/ft_strjoin.c \
		./utils/ft_strlen.c \
		./utils/ft_substr.c \

SRCS_BONUS =	./SRC_BONUS/pipex_bonus.c \
				./SRC_BONUS/argument_control_bonus.c \
				./SRC_BONUS/pipex_bonus_extra.c \
				./get_next_line/get_next_line.c \
				./get_next_line/get_next_line_utils.c \
				./utils/free_super_matrix.c \
				./utils/free_matrix.c \
				./utils/ft_split.c \
				./utils/ft_strcmp.c \
				./utils/ft_strncmp.c \
				./utils/ft_strdup.c \
				./utils/ft_putstr_fd.c \
				./utils/ft_strjoin.c \
				./utils/ft_strlen.c \
				./utils/ft_substr.c \

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all : $(NAME)

bonus : $(NAME2)

$(NAME): $(OBJS) $(PRINT)
	$(CC) $(CFLAGS) $(OBJS) $(PRINT) -o $(NAME)

$(NAME2): $(OBJS_BONUS) $(PRINT)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(PRINT) -o $(NAME2)

$(PRINT):
	make -C $(PRINTF_PATH) all

%.o : %.c
	$(CC) $(CFLAGS) -c -g $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	make -C $(PRINTF_PATH) clean

fclean: clean
	rm -f $(NAME) $(NAME2)
	make -C $(PRINTF_PATH) fclean

re : fclean all

.PHONY : all clean fclean re