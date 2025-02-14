TARGET = libft_fprintf.a
C_FLAG = -Werror -Wextra -Wall
HEADER_PATH = -I. -I$(DIR_LIBFT)
include source_names.mk
OBJS = $(addprefix objs/, $(patsubst %.c,%.o,$(SRCS)))
DEPS = $(addprefix deps/, $(patsubst %.c,%.d,$(SRCS)))

all: lib $(TARGET)

$(TARGET): $(OBJS)
	ar rcs $(TARGET) $(OBJS)

objs/%.o: srcs/%.c
	mkdir -p objs deps
	@if [ ! -f $< ]; then echo "Error: Source file $< not found!"; exit 1; fi
	cc $(C_FLAG) $(HEADER_PATH) -c $< -o $@ -MMD -MF deps/$(*F).d

-include $(DEPS)

clean:
	rm -rf objs deps

fclean:
	rm -rf objs deps
	rm -rf $(TARGET)

re: fclean all

lib:
ifndef DIR_LIBFT
	$(error ft_fprintf: directory path libft not defined.)
endif

.PHONY: all clean fclean re lib
