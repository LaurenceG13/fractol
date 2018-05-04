# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lagirard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/24 15:53:24 by lagirard          #+#    #+#              #
#    Updated: 2017/10/31 15:02:45 by lagirard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_PATH = srcs/

SRCS = main.c common_fcts.c colors.c events.c zoom.c mouse.c keycode.c\
errors.c init.c\
julia.c mandelbrot.c burningship.c juju.c tricorn.c rorschach.c\
julia_init.c mandelbrot_init.c burningship_init.c juju_init.c tricorn_init.c\
rorschach_init.c

OBJ = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra

INC = -I ./includes/ -I./libft/includes

LIB = -L minilibx_macos -lmlx -framework OpenGL -framework AppKit -Llibft/ -lft

all : $(NAME)

$(NAME) : $(OBJ)
	    	@make -C libft/
			@make -C minilibx_macos
		  	@gcc $(OBJ) $(INC) $(LIB) -o $(NAME)

%.o: $(SRC_PATH)%.c
	       	@gcc -c $(FLAGS) $< -o $@ $(INC)


.PHONY = clean
clean :
	        @rm -rf $(OBJ)

fclean : clean
	        @rm -rf $(NAME)
			    @make -C libft fclean
				@make -C minilibx_macos clean

re : fclean all

.PHONY: all clean fclean re
