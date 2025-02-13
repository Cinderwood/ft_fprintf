TARGET = libft_fprintf.a
C_FLAG = -Werror -Wextra -Wall
HEADER_PATH = -I.
include source_names.mk
OBJS = $(addprefix objs/, $(patsubst %.c,%.o,$(SRCS)))
DEPS = $(addprefix deps/, $(patsubst %.c,%.d,$(SRCS)))

all: $(OBJS)
	ar rcs $(TARGET) $(OBJS)

objs/%.o: srcs/%.c
	mkdir -p objs deps
	cc $(C_FLAG) $(HEADER_PATH) -c $< -o $@ -MMD -MF deps/$(*F).d

-include $(DEPS)

clean:
	rm -rf objs deps

fclean: clean
	rm -rf $(TARGET)

re: fclean all

.PHONY: all clean fclean re
