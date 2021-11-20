CC 		= gcc
CCFLAGS = -Wall -Werror -Wextra
INCLUDE = -I./include
AR		= ar
ARFLAGS = rc

FILES 	= ft_printf ft_str ft_expr ft_nbr util nbr_util str_util
S_DIR	= src
B_DIR	= build
SRC		= $(addprefix $(S_DIR)/, 	$(FILES:=.c))
OBJ		= $(addprefix $(B_DIR)/, 	$(FILES:=.o))
LIB		= libftprintf.a

all: $(LIB)

$(LIB): $(OBJ)
	$(AR) $(ARFLAGS) $(LIB) $(OBJ)

$(B_DIR)/%.o: $(S_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CCFLAGS) $(INCLUDE) -o $@ -c $<

debug: CCFLAGS += -g
debug: fclean all
bonus: all

clean:
	rm -f $(OBJ)
	rm -rf $(B_DIR)
	rm -rf $(TEST_EXEC)

fclean: clean
	rm -f $(LIB)

.PHONY: all clean fclean
