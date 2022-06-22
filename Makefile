# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: riramli <riramli@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/09 11:23:18 by riramli           #+#    #+#              #
#    Updated: 2022/06/09 16:42:21 by riramli          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	 	= philo
FLAG		= -Wall -Wextra -Werror -pthread
# to check for data race / mutex lock inversion / etc issues. 
# but this will have a bit of performance hit and inaccuracy
# also try not to test this on a remote/shell environment like Guacamole
# due to the latency issues.
CHECK		= -g -fsanitize=thread

all:	$(NAME)

$(NAME):
	gcc -c -Iinc src/*.c
	gcc $(FLAG) main.c -Iinc *.o -o $(NAME)

clean:
		rm -f *.o

fclean: clean
		rm $(NAME)

re:		fclean all
# a simple, self-sustaining program of two philos
# ample t_die ensures no philo will ever die.
t1: re
	./$(NAME) 2 6000 1500 3000 2
# same but only using 1 philo. Philo should not eat and should die
t2: re
	./$(NAME) 1 6000 1500 3000 4
# non sustaining, 2 philos. A philo should die.
t3: re
	./$(NAME) 2 6000 4500 1500 4
# the others onward are from evaluation page. Philo should not eat and should die
t4: re
	./$(NAME) 1 800 200 200
# no die
t5: re
	./$(NAME) 5 800 200 200
# no die. 'x is eating' should appear 7 times.
t6: re
	./$(NAME) 5 800 200 200 7
# no die. This will trip and fail randomly in the absence of rounding down of timestamps.
t7: re
	./$(NAME) 4 410 200 200
# die while waiting to eat. For instance 1 will die at 300 because 4 is still eating and will only release fork at 400.
t8: re
	./$(NAME) 4 310 200 100
# last but not least, test with small numbers
t9: re
	./$(NAME) 4 130 60 60

.PHONY: all run clean
