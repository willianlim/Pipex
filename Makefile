# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 00:45:29 by wrosendo          #+#    #+#              #
#    Updated: 2021/11/29 09:42:22 by wrosendo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = "\033[0;32m"
RED = "\n\033[0;31m"
EOC = "\033[0;0m"

NAME = pipex
CC = clang
CFLAGS = -Wall -Wextra -Werror -g
OBJDIR = ./obj
SRC_DIR = ./src
INCLUDES = ./includes
SRC_DIR_PIP = ./functions_shared
REMOVE = rm -rf

SRC_FILE = ft_pipex.c
OBJFILE = $(SRC_FILE:.c=.o)
OBJECTS = $(addprefix $(OBJDIR)/, $(OBJFILE))

SRC_FILE_BONUS = ft_pipex_bonus.c
OBJFILE_BONUS = $(SRC_FILE_BONUS:.c=.o)
OBJECTS_BONUS = $(addprefix $(OBJDIR)/, $(OBJFILE_BONUS))

SRC_SHARED += ft_bzero.c ft_calloc.c ft_parse_cmd.c ft_memset.c ft_split.c
SRC_SHARED += ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_message_clean.c
SRC_SHARED += ft_strnstr.c ft_memmove.c ft_strdup.c ft_memcpy.c ft_putstr_fd.c
OBJFILE_SHARED = $(SRC_SHARED:.c=.o)
OBJECTS_SHARED = $(addprefix $(OBJDIR)/, $(OBJFILE_SHARED))

all: $(NAME)

$(NAME): $(OBJECTS_SHARED) $(OBJECTS)
	@echo $(GREEN) "Source files are compiled!\n" $(EOC)
	$(CC) $(CFLAGS) -I $(INCLUDES) -o $(NAME) $(OBJDIR)/*.o
	@echo $(GREEN) "pipex is created!\n" $(EOC)

$(OBJDIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -I $(INCLUDES) -o $@

$(OBJDIR)/%.o: $(SRC_DIR_PIP)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -I $(INCLUDES) -o $@

bonus: $(OBJECTS_SHARED) $(OBJECTS_BONUS)
	@echo $(GREEN) "Source files are compiled!\n" $(EOC)
	$(CC) $(CFLAGS) -I $(INCLUDES) -o $(NAME) $(OBJDIR)/*.o
	@echo $(GREEN) "pipex is created!\n" $(EOC)

$(OBJDIR)/%.o: $(SRC_DIR_PIP)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -I $(INCLUDES) -o $@

$(OBJDIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -I $(INCLUDES) -o $@

clean:
	$(REMOVE) $(OBJDIR)

fclean: clean
	$(REMOVE) $(NAME)
	@echo $(RED) "Deleting EVERYTHING! ⌐(ಠ۾ಠ)¬\n" $(EOC)

re: fclean all

rebonus: fclean bonus

norm:
	@norminette ./includes/ ./functions_shared ./src/

.PHONY: clean fclean re
