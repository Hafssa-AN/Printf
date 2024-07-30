NAME = libftprintf.a

MN = ./Mandatory

BN = ./Bonus

SRCS =  ft_adr.c       ft_base.c      ft_printf.c      ft_putchar.c   \
		ft_putnbr.c    ft_putstr.c    ft_strlen.c   ft_strchr.c	\

SRCS_BONS = ft_adr.c		ft_base.c	ft_strchr.c	\
			ft_comb_flags_bonus.c		ft_comb_nbr_bonus.c		ft_printf.c	\
			ft_putchar.c		ft_putnbr.c	ft_putstr.c	\
			ft_strlen.c	ft_comb_putchar_bonus.c	ft_comb_putstr_bonus.c	\
			ft_comb_base_bonus.c	ft_strncmp_bonus.c		ft_comb_adr_bonus.c	\
			ft_pourcentage_bonus.c 	ft_tools_base_bonus.c		ft_tools_nbr_bonus.c	\

OBJS = $(SRCS:%.c=$(MN)/%.o)

BONUS_OBJS = $(SRCS_BONS:%.c=$(BN)/%.o)

CC = cc

HEADER = ft_printf.h
CFLAGS = -Wall -Wextra -Werror

rm = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $?

bonus: $(BONUS_OBJS)
	ar rcs $(NAME) $?

clean:
	$(rm) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(rm) $(NAME)

re: fclean all

.PHONY: clean re fclean bonus all