# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 13:56:51 by wismith           #+#    #+#              #
#    Updated: 2022/08/11 15:51:04 by wismith          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#.SILENT:

NAME = philo

SRCS = 	main\
		tools/basic\
		tools/print\
		tools/time\
		parse/pars\
		init/init\
		init/local_\
		actions/eat_\
		actions/life_\
		actions/lonely_life\

OBJ = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(SRCS)))

OBJDIR = OBJECTS

CC = gcc

CFLAGS = -Wall -Werror -Wextra

$(OBJDIR)/%.o : srcs/%.c
	@tput setaf 6; echo "-> Generating Object <-"; tput setaf 7;
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJDIR)/tools
	@mkdir -p $(OBJDIR)/parse
	@mkdir -p $(OBJDIR)/init
	@mkdir -p $(OBJDIR)/actions
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME) printasciiart

$(NAME) : $(OBJ)
	@tput setaf 6; echo "-> Compiling <-"; tput setaf 7;
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -lpthread

clean :
	@tput setaf 1; echo "-> Cleaning <-"; tput setaf 7;
	rm -rf $(OBJDIR)

fclean : clean
	@tput setaf 1; echo "-> Removing Executable <-"; tput setaf 7;
	rm -f $(NAME)

printre :
	@tput setaf 4; echo "-> Recreating <-"; tput setaf 7;

printasciiart :
	@tput setaf 1;
	@printf "\e[1;1H\e[2J"
	@printf "             ___          \n"
	@printf "            /   \\        \n"
	@printf "        /\\ |     \\       \n"
	@printf "      ////\\|     ||       \n"
	@printf "    ////   \\ ___//\       \n"
	@printf "   ///      \\      \            _          _ _   _    \n"
	@printf "  ///       |\\      |   __ __ _(_)____ __ (_) |_| |_  \n"
	@printf " //         | \\  \   \  \ V  V / (_-< '  \| |  _| ' \ \n"
	@printf " /          |  \\  \   \  \_/\_/|_/__/_|_|_|_|\__|_||_|\n"
	@printf "            |   \\ /  "; tput setaf 2; printf  "____  _     _ _                       _                    \n"; tput setaf 1;
	@printf "            |    \/ ";   tput setaf 2; printf  "|  _ \| |__ (_) | ___  ___  ___  _ __ | |__   ___ _ __ ___ \n"; tput setaf 1;
	@printf "            |     \\/";  tput setaf 2; printf  "| |_) | '_ \| | |/ _ \/ __|/ _ \| '_ \| '_ \ / _ \ '__/ __|\n"; tput setaf 1;
	@printf "            |      \\";  tput setaf 2; printf  "|  __/| | | | | | (_) \__ \ (_) | |_) | | | |  __/ |  \__ \ \n"; tput setaf 1;
	@printf "            |       ";   tput setaf 2; printf  "|_|   |_| |_|_|_|\___/|___/\___/| .__/|_| |_|\___|_|  |___/\n"; tput setaf 1;
	@printf "            |        | "; printf  "  -> Executable Provided <- "; tput setaf 2; printf " |_|                        \n"; tput setaf 1;
	@printf "            |_________\    \n\n"
	@tput setaf 7;


re : fclean printre all

.PHONY : all clean fclean re printre