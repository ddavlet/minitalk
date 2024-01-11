CC = cc
NAME = server
FLAGS = -Wall -Werror -Wextra
LIBFT_DIR = ../libft/
# RULES_DIR =
# UTILS_DIR =
# SORT_DIR =
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I $(LIBFT_DIR) -I .
# HEADERS = server.h
RM = rm -f
RANNAME = ranlib $(NAME)
SRC = server.c
OBJ := $(SRC:.c=.o)
# BONUS = checker
# BONUS_DIR = ./bonus/
# B_RULES_DIR = ./rules_bonus/
# BONUS_SRC =
# BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $^ -o $@

%.o: %.c
	$(CC) -g $(FLAGS) $(INCLUDES) -c $< -o $@

bonus: $(LIBFT) $(BONUS)
# $(BONUS) : $(BONUS_OBJ) $(LIBFT)
# 	$(CC) -g $(FLAGS) $^ -o $@

clean:
		$(RM) $(OBJ) $(BONUS_OBJ)
		$(MAKE) -C $(LIBFT_DIR) fclean

fclean: clean
		$(RM) $(NAME) $(BONUS)
		$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
