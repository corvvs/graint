CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror -O3
NAME		:=	graint
SRCS		:=	main.c\
				initializer.c\
				vector.c force.c\
				expander_euler.c expander_leap_frog.c\
				conservative.c printer.c
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
