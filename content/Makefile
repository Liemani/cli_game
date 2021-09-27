NAME				:= cli_game.out

SRCS				:= \
					   main.c \
					   lmt_c_library/lmt_alloc/lmt_alloc.c \
					   lmt_c_library/lmt_sequence/t_lmt_sequence_type.c \
					   lmt_c_library/lmt_sequence/t_lmt_sequence_method.c \
					   lmt_c_library/lmt_sequence/t_lmt_sequence_element_type.c \
					   lmt_c_library/lmt_sequence/t_lmt_sequence_element_method.c \
					   lmt_c_library/lmt_string/t_lmt_string_type.c \
					   lmt_c_library/lmt_string/t_lmt_string_method.c \
					   lmt_c_library/lmt_unsafe/lmt_unsafe_memcpy.c \
					   lmt_c_library/lmt_unsafe/lmt_unsafe_strlen.c \
					   lmt_c_library/lmt_unsafe/lmt_unsafe_strcpy.c \
					   lmt_c_library/lmt_unsafe/lmt_unsafe_strdup.c \
					   lmt_c_library/lmt_unsafe/lmt_unsafe_strchr.c \
					   lmt_c_library/lmt_unsafe/lmt_unsafe_strrchr.c \
					   lmt_c_library/lmt_unsafe/lmt_unsafe_string_starts.c \
					   lmt_c_library/lmt_util/lmt_atoi.c \
					   lmt_c_library/lmt_util/lmt_is_space.c \
					   lmt_c_library/lmt_util/lmt_is_digit.c
OBJS				:= $(SRCS:.c=.o)

CC					:= clang
CFLAG				:= -Wall -Wextra -Werror

ABSTRACT_INCLUDE	:= \
					   . \
					   lmt_c_library \
					   lmt_c_library/lmt_alloc \
					   lmt_c_library/lmt_reader \
					   lmt_c_library/lmt_sequence \
					   lmt_c_library/lmt_string \
					   lmt_c_library/lmt_unsafe \
					   lmt_c_library/lmt_util
INCLUDE				:= $(addprefix -I ,$(ABSTRACT_INCLUDE))

LIBRARY				:= -l pthread

COMPILE				= $(CC) $(CFLAG) $(INCLUDE) $(DEBUG_OPTION)
LINK				= $(CC) $(CFLAG) $(INCLUDE) $(DEBUG_OPTION) $(LIBRARY)

RM					:= rm -f



.PHONY:				all debug setdebug clean fclean re
all:				$(NAME)

debug:				clean setdebug $(NAME)
setdebug:
					$(eval DEBUG_OPTION = -g)

clean:
					$(RM) $(OBJS)
fclean:				clean
					$(RM) $(NAME)
re:					fclean all



$(NAME):			$(OBJS)
					$(LINK) -o $@ $^

%.o:				%.c
					$(COMPILE) -o $@ -c $<
