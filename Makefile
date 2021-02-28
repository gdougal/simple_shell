# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vanell <vanell@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/21 23:25:54 by vanell            #+#    #+#              #
#    Updated: 2020/12/25 22:45:09 by gdougal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME            =   minishell

CC              =   gcc

LIBFT_DIR       =   ./libs/libft/

SRCS_DIR        =   ./srcs/

HEADERS_DIR     =   $(SRCS_DIR)includes/

SRCS_HEAD       =   $(addprefix $(HEADERS_DIR), parser.h \
                                                minishell.h)

INCLUDES        =   -I$(HEADERS_DIR) -I./$(LIBFT_DIR)

FLAGS           =   $(INCLUDES) -Wall -Wextra -Werror -O2 -MD

LFLAGS          =   -L$(LIBFT_DIR) -lft

PARS_DIR        =   parser/

SRCS_PARS       =  $(addprefix $(PARS_DIR), $(notdir $(wildcard $(SRCS_DIR)$(PARS_DIR)*.c)))

GNL_DIR         =   gnl/

SRCS_GNL        =   $(addprefix $(GNL_DIR), get_next_line.c \
                                             get_next_line_utils.c)

ERROR_DIR        =   error/

SRCS_ERROR       =   $(addprefix $(ERROR_DIR), $(notdir $(wildcard $(SRCS_DIR)$(ERROR_DIR)*.c)))

EXEC_DIR          =   execute/

SRC_EXEC          =   $(addprefix $(EXEC_DIR), $(notdir $(wildcard $(SRCS_DIR)$(EXEC_DIR)*.c)))

UTILS_DIR        =   utils/

SRC_UTILS        =   $(addprefix $(UTILS_DIR), $(notdir $(wildcard $(SRCS_DIR)$(UTILS_DIR)*.c)))

MINI_DIR		=  ./

SRC_MINI		=	$(addprefix $(MINI_DIR), $(notdir $(wildcard $(SRCS_DIR)$(MINI_DIR)*.c)))

SRCS_ALL        =   $(addprefix $(SRCS_DIR), \
                                    $(SRCS_PARS) \
                                    $(SRCS_GNL) \
                                    $(SRCS_ERROR) \
                                    $(SRC_EXEC) \
                                    $(SRC_UTILS) \
									$(SRC_MINI))

OBJ_DIR         =   ./obj/

O_FILE          =   $(patsubst $(SRCS_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS_ALL))
D_FILE          =   $(patsubst %.c,%.d,$(SRCS_ALL))

ALL_O_DIRS      =   $(addprefix $(OBJ_DIR), $(GNL_DIR) $(PARS_DIR) $(ERROR_DIR) $(EXEC_DIR) $(UTILS_DIR))

.PHONY: all

all: $(NAME)

$(NAME): $(ALL_O_DIRS) $(O_FILE)
	$(MAKE) -C libs/libft bonus
	$(CC) $(FLAGS) $(O_FILE) $(LFLAGS) -o $(NAME)

$(O_FILE): $(OBJ_DIR)%.o: $(SRCS_DIR)%.c $(SRCS_HEAD)
	$(CC) -c $(FLAGS) $(INCLUDES) -c $< -o $@

$(ALL_O_DIRS):
	@mkdir -p $(ALL_O_DIRS)

.PHONY: clean

clean:
	$(MAKE) -C libs/libft clean
	@rm -rf $(OBJ_DIR)
	@rm -f $(O_FILE)
	@rm -f $(D_FILE)

PHONY: fclean

fclean: clean
	$(MAKE) -C libs/libft fclean
	@rm -f $(NAME) screenshoot.bmp

.PHONY: re

re:     fclean all
