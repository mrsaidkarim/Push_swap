CC = cc
CFLAGS = -Wall -Werror -Wextra 
SRCD = mandatory/
SRCF = ft_checker.c ft_join.c ft_split.c ft_utils.c init_stack.c push.c rev_rotate.c rotate.c sort.c stack_utils1.c stack_utils2.c stack_utils3.c swap.c lis_utils.c push_swap.c
SRC = ${addprefix $(SRCD), $(SRCF)}
OBJ = ${SRC:.c=.o}
bnsd = bonus/
bnsf = checker_bonus.c checker_operations_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c  ft_checker.c ft_join.c ft_split.c ft_utils.c init_stack.c push.c rev_rotate.c rotate.c swap.c stack_utils1.c
bns = ${addprefix $(bnsd), $(bnsf)}
bns_objs = ${bns:.c=.o}
NAME = push_swap
bonus_name = checker
header = push_swap.h

all: $(NAME)

%.o : %.c $(header)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $@

bonus: $(bonus_name)

$(bonus_name): $(bns_objs)
	$(CC) $(bns_objs) -o $@

clean:
	rm -rf $(OBJ)
	rm -rf $(bns_objs)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(bonus_name)

re: fclean all