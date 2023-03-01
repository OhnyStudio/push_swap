NAME 		=	push_swap
CC 			=	gcc
CFLAGS 		=	-Wall -Wextra -Werror -g
LIBFT_PATH	=	libft/
LIBFT_LIB	=	$(LIBFT_PATH)libft.a
CFILES		=	src/algo_complexe.c \
				src/algo_utils.c \
				src/algo.c \
				src/base_action.c \
				src/list_creator.c \
				src/list_validation_other.c \
				src/list_validation.c \
				src/list_value_finder.c \
				src/list_check_bit.c \
				src/new_new_algo.c \
				src/main.c
Y			=	"\033[33m"
R			=	"\033[31m"
G			=	"\033[32m"
B			=	"\033[34m"
X			=	"\033[0m"
UP			=	"\033[A"
CUT			=	"\033[K"
OBJECTS		=	$(CFILES:.c=.o)

all: subsystems $(NAME)

%.o : %.c
	@echo $(Y)Compiling [$<]...$(X)
	@$(CC) $(CFLAGS) -Imlx -c -o $@ $<
	@printf $(UP)$(CUT)

subsystems:
	@echo $(B)
	make -C $(LIBFT_PATH) all

$(NAME): $(OBJECTS)
	@echo $(Y)Compiling [$(CFILES)]...$(X)
	@echo $(G)Finished [$(CFILES)]$(X)
	@echo
	@echo $(Y)Compiling [$(NAME)]...$(X)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_LIB) -o $(NAME)
	@echo $(G)Finished [$(NAME)]$(X)

clean:
	@make -C $(LIBFT_PATH) clean
	@rm -f $(OBJECTS)
	@echo $(R)Removed [$(OBJECTS)]$(X)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@rm -f $(NAME)
	@echo $(R)Removed [$(NAME)]$(X)

re: fclean all