NAME 		= libft.a
NAME_SO		= libft.so
HEAD		= libft.h

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

SRC			= ft_memset.c	ft_bzero.c		ft_memcpy.c		ft_memccpy.c	ft_memmove.c	\
			ft_memchr.c		ft_memcmp.c 	ft_strlen.c 	ft_strlcpy.c 	ft_strlcat.c 	\
			ft_strchr.c		ft_strrchr.c	ft_strnstr.c	ft_strncmp.c	ft_atoi.c 		\
			ft_isalpha.c	ft_isdigit.c	ft_isalnum.c	ft_isascii.c	ft_isprint.c	\
			ft_toupper.c	ft_tolower.c	ft_calloc.c		ft_strdup.c		ft_substr.c		\
			ft_strjoin.c	ft_strtrim.c	ft_split.c		ft_itoa.c 		ft_strmapi.c	\
			ft_strchr_len.c from_addr_to_addr_cpy.c         ft_strdup_ch.c	ft_strdup_set.c	\
			ft_is_set.c		ft_join_with_free.c				clear_any_arr.c	ft_strcmp.c  \
			ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c

OBJ			= $(patsubst %.c, %.o, $(SRC))

SRC_BONUS	= 	ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.c	ft_lstadd_back.c	\
				ft_lstdelone.c	ft_lstclear.c		ft_lstiter.c	ft_lstmap.c

OBJ_BONUS	= $(patsubst %.c, %.o, $(SRC_BONUS))

.PHONY: all bonus clean fclean re so

all: $(NAME)

$(NAME): $(OBJ)
		@ar rcs $(NAME) $(OBJ)

$(OBJ): %.o: %.c $(HEAD)
		@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME) $(OBJ_BONUS)
		@ar r $(NAME) $(OBJ) $(OBJ_BONUS)

$(OBJ_BONUS): %.o: %.c $(HEAD)
		@$(CC) $(CFLAGS) -c $< -o $@

clean:
		@rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
		@rm -f $(NAME) $(NAME_SO)

re: fclean all

so: $(NAME_SO)

$(NAME_SO): $(OBJ) $(OBJ_BONUS)
		@$(CC) -shared -o $(NAME_SO) $(OBJ) $(OBJ_BONUS)
