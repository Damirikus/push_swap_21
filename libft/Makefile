SRC_NAME =	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
		ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_strdup.c ft_atoi.c \
		ft_calloc.c ft_strlen.c ft_strlcpy.c ft_strlcat.c\
		ft_substr.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			

BONUS	=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c \
		ft_lstiter_bonus.c ft_lstmap_bonus.c
BONUS_OBJS		=	$(BONUS:.c=.o)
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(SRC_NAME)
OBJ = $(addprefix ,$(OBJ_NAME))
CC = gcc
CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -I.
NAME = libft.a

all : $(NAME)


$(NAME) : $(OBJ) libft.h
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$%.o: $(SRC_PATH)%.c 
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
bonus:	$(OBJS) $(BONUS_OBJS)
		ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
clean:
	rm -f $(OBJ) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)  $(bonus)

re : fclean all

.PHONY: clean fclean all re	