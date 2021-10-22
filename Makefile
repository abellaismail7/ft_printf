CC 		= gcc
CCFLAGS = -Wall -Werror -Wextra -I./include
AR		= ar
ARFLAGS = rc

FILES 	= main util
S_DIR	= src
B_DIR	= build
SRC		= $(addprefix $(S_DIR)/, 	$(FILES:=.c))
OBJ		= $(addprefix $(B_DIR)/, 	$(FILES:=.o))
LIB		= printf.a
TEST_EXEC = test_printf

all: $(LIB)

$(LIB): $(OBJ)
	$(AR) $(ARFLAGS) $(LIB) $(OBJ)

$(B_DIR)/%.o: $(S_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CCFLAGS) -o $@ -c $<

test:
	$(CC) $(CCFLAGS) -o $(TEST_EXEC) $(LIB) tests/main.c

clean:
	rm -f $(OBJ)
	rm -rf $(B_DIR)
	rm -rf $(TEST_EXEC)

fclean: clean
	rm -f $(LIB)

.PHONY: all clean fclean
