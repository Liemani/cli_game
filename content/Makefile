NAME				:= cli_game.out

LMT_C_LIBRARY		:= lmt_c_library/liblmt_c_library.a



SRCS				:= \
					   character/character.c \
					   display/display.c \
					   display/display_method.c \
					   game/game_constructor.c \
					   game/game.c \
					   time/time_method.c \
					   time/time_type.c \
					   vector2/vector2.c \
					   main.c
OBJS				:= $(SRCS:.c=.o)

CC					:= clang
CFLAG				:= -Wall -Wextra -Werror

ABSTRACT_INCLUDE	:= \
					   character \
					   display \
					   game \
					   time \
					   vector2 \
					   lmt_c_library \
					   lmt_c_library/lmt_c_library \
					   lmt_c_library/lmt_io \
					   lmt_c_library/lmt_iterator \
					   lmt_c_library/lmt_list \
					   lmt_c_library/lmt_primitive_type \
					   lmt_c_library/lmt_string \
					   . 
INCLUDE				:= $(addprefix -I ,$(ABSTRACT_INCLUDE))

LIBRARY				:= -l pthread -L lmt_c_library -l lmt_c_library

COMPILE				= $(CC) $(CFLAG) $(INCLUDE) $(DEBUG_OPTION)
LINK				= $(CC) $(CFLAG) $(INCLUDE) $(DEBUG_OPTION) $(LIBRARY)

RM					:= rm -f



.PHONY:				all debug setdebug clean fclean re
all:				$(LMT_C_LIBRARY) $(NAME)

debug:				clean setdebug $(NAME)
setdebug:
					$(eval DEBUG_OPTION = -g)

clean:
					$(RM) $(OBJS)
fclean:				clean
					$(RM) $(NAME)
re:					fclean all



$(LMT_C_LIBRARY):
					make -C lmt_c_library

$(NAME):			$(OBJS)
					$(LINK) -o $@ $^

%.o:				%.c
					$(COMPILE) -o $@ -c $<
