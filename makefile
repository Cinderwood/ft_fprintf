TARGET = libft_fprintf.a
C_FLAG = -Werror -Wextra -Wall
HEADER_PATH = -I. -Ilibft
include source_names.mk
OBJS = $(addprefix objs/, $(patsubst %.c,%.o,$(SRCS)))
DEPS = $(addprefix deps/, $(patsubst %.c,%.d,$(SRCS)))

all: $(OBJS)
	git submodule update --init --recursive
	make -C libft all -s
	ar rcsT $(TARGET) $(OBJS) libft/libft.a

objs/%.o: srcs/%.c
	mkdir -p objs deps
	cc $(C_FLAG) $(HEADER_PATH) -c $< -o $@ -MMD -MF deps/$(*F).d

-include $(DEPS)

clean:
	rm -rf objs deps
	make -C libft clean -s

fclean: clean
	rm -rf $(TARGET)
	make -C libft fclean -s

re: fclean all

.PHONY: all clean fclean re
