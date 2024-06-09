# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 16:52:37 by ykosaka           #+#    #+#              #
#    Updated: 2023/07/02 15:02:19 by ykosaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ********************** Section for Macros (Variables) ********************** #
# Product file
NAME			= connect4

# Component names
LIBNAME			= libft

# Check the platform
OS				= $(shell uname)

# Enumeration of files
SRC				= main.c map.c judge.c disp.c ctrl.c utils.c com.c check_chain.c

# Enumeration of directories
SRCDIR			= ./src
INCDIR			= ./include
LIBDIR			= $(LIBNAME)
OBJDIR			= ./obj

# Macros to replace and/or integrate
SRCS			= $(addprefix $(SRCDIR)/, $(SRC))
OBJS			= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))
DEPS			= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.d)))
LIBS			= $(LIBDIR)/$(LIBNAME).a

# Aliases of commands
CC				= cc
RM				= rm

# Command options (flags)
CFLAGS			= -MMD -Wall -Wextra -Werror
DEBUGCFLAGS		= -g -ggdb -fno-omit-frame-pointer
DEBUGLDFLAGS	= -fsanitize=address
INCLUDES		= -I$(INCDIR) -I$(LIBDIR)/include
RMFLAGS			= -r

# Redefination when the specific target
ifeq ($(MAKECMDGOALS), debug)
	ifneq ($(OS), Darwin)
		DEBUGCFLAGS	+= -fstack-usage
	endif
	CFLAGS	+= $(DEBUGCFLAGS)
	LDFLAGS	+= $(DEBUGLDFLAGS)
	DEF		= -D DEBUG_MODE=1
endif

# ********************* Section for targets and commands ********************* #
# Phonies
.PHONY: all clean fclean re clean_partly debug_lib debug

# Mandatory targets
all: $(LIBS) $(NAME)
clean:
	$(MAKE) clean -C $(LIBDIR)
	-$(RM) $(RMFLAGS) $(OBJDIR)
fclean: clean
	$(MAKE) fclean -C $(LIBDIR)
	-$(RM) $(RMFLAGS) $(NAME)
re: fclean all

# Additional targets
clean_partly:
	$(MAKE) clean -C $(LIBDIR)
	-$(RM) $(RMFLAGS) $(OBJDIR)
debug_lib: 
	$(MAKE) debug -C $(LIBDIR)
debug: clean_partly debug_lib all

# Recipes
$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) $(INCLUDES) $(OBJS) $(LIBS) -o $(NAME)
$(LIBS):
	$(MAKE) -C $(LIBDIR)
$(OBJDIR):
	@mkdir -p $@
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(DEF) $(INCLUDES) -o $@ -c $<

# Including and ignore .dep files when they are not found
-include $(DEPS)

# ******** ******** ******** ******** **** ******** ******** ******** ******** #
