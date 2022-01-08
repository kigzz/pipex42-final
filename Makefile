
#SETUP
NAME		=	pipex
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

#FILES AND PATH
HEADER_SRCS	=	pipex.h

SRCS    	=	pipex.c
OBJ_SRCS    =	$(SRCS:.c=.o)

FUNC_SRCS	=	ft_strncmp.c ft_strdup.c ft_split.c ft_strjoin.c ft_free.c ft_memcpy.c ft_strlen.c \
                pipex_utils.c ft_child.c ft_error.c
FUNC_DIR	=	functions/
FUNC 		=	$(addprefix $(FUNC_DIR), $(FUNC_SRCS))
OBJ_F		=	$(FUNC:.c=.o)

#COMMANDS
%.o: %.c $(HEADER) Makefile
				@${CC} ${FLAGS} -c $< -o $@

$(NAME):		$(OBJ_F) $(OBJ_SRCS)
				@$(CC) $(FLAGS) $(OBJ_F) $(OBJ_SRCS) -o $(NAME)
				@echo "$(NAME) created!"

all:			$(NAME)

clean:
				@$(RM) $(OBJ_SRCS)
				@$(RM) $(OBJ_F)
				@echo "object files deleted!"

fclean:			clean
				@$(RM) $(NAME)
				@echo "all deleted!"

re:				fclean all

.PHONY:		all clean fclean bonus re
