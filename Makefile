CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror
NAME		:=	graint
SRCS		:=	main.c vector.c force.c expander_euler.c expander_leap_frog.c printer.c
OBJS		:=	$(SRCS:.c=.o)

.PHONY		:	all clean fclean re

all			:	$(NAME)
$(NAME)		:	$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean		:
	$(RM) -rf $(OBJS)

fclean		:	clean
	$(RM) $(NAME)

re			:	fclean all
