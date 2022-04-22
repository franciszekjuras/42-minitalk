NAME = minitalk
SERVER = server

FILES = \
	minitalk

SERVER_FILES = \
	server char_bld

OFILES = $(FILES:%=%.o)
SERVER_OFILES = $(SERVER_FILES:%=%.o)
CFLAGS = -Wall -Wextra
OPTIM = -O0
export OPTIM
INC = -I.
LIBS= -lft
LIBS_FILES = libft/libft.a
LIBS_DIRS = $(addprefix -L, $(dir $(LIBS_FILES)))

all: $(NAME) $(SERVER)

$(NAME): $(OFILES) $(LIBS_FILES)
	gcc $(LIBS_DIRS) $(OFILES) $(LIBS) -o $@

$(SERVER): $(SERVER_OFILES) $(LIBS_FILES)
	gcc $(LIBS_DIRS) $(SERVER_OFILES) $(LIBS) -o $@

$(OFILES): %.o: %.c
	gcc $(CFLAGS) $(OPTIM) $(INC) -c $< -o $@

$(SERVER_OFILES): %.o: %.c
	gcc $(CFLAGS) $(OPTIM) $(INC) -c $< -o $@

$(LIBS_FILES): FORCE
	make -C $(dir $@)

FORCE: ;

clean_:
	rm -f $(OFILES) $(SERVER_OFILES)

clean: clean_libs clean_

fclean_: clean_
	rm -f $(NAME) $(SERVER)

fclean: fclean_ clean
	rm -f $(LIBS_FILES)

re_: fclean_ all

re: re_libs re_

clean_libs:
	make clean -C libft

re_libs:
	make re -C libft

.PHONY: clean clean_ fclean fclean_ re re_ re_libs clean_libs FORCE
