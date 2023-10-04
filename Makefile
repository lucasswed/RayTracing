############### PROGRAM ###############

NAME		=	RayTracing

############## TERMINAL ###############

RMV			=	rm -rf
MKD			=	mkdir
PRT			=	printf
MKE			=	make
CPY			=	CPY

################ COLORS ###############

--RED		=	\033[31m
--GRN		=	\033[32m
--WHT		=	\033[39m

################ DIRS #################

_SRC		=	src/
_OBJ		=	obj/
_LIB		=	libs/
_BIN		=	./

############## COMPILER ###############

CC			=	c++
CFLAGS	=	-Wall -Werror -Wextra #-g -fsanitize=address
SRCS		=	
OBJS		=	$(patsubst $(_SRC)%.cpp,$(_OBJ)%.o,$(SRCS))
DEPS		=
LIBS		=

################ RULES ################

all:	$(NAME)

$(_OBJ)%.o:	$(_SRC).cpp
						$(MKD) -p $(@D)
						$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(DEPS) $(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
			
############## STRUCTURE ##############

clean:
			$(RMV) $(_OBJ)
		
fclean:	clean
			$(RMV) $(NAME)

re:	fclean all

.PHONY:	all deps clean fclean re