# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 08:46:19 by sniemela          #+#    #+#              #
#    Updated: 2025/03/18 08:59:20 by sniemela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
CPPFLAGS = -Wall -Werror -Wextra
CPP = c++

SOURCES = main.cpp \

OBJDIR = obj
OBJS = $(SOURCES:%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(CPPFLAGS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	@mkdir -p $(dir $@)
	@$(CPP) $(CPPFLAGS) -cpp $< -o $@

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re