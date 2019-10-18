CC		=	clang++
CFLAGS	=	-Wall -Werror -Wextra
BINS	=	Renderer1
DIR		=	../../RenderLib/
SHARED	=	$(addprefix lib,$(OBJ:.o=.so))
OBJ		=	$(SRC:.cpp=.o)
LIB		=	-lsfml-graphics \
			-lsfml-window \
			-lsfml-system
SFML = $(shell pkg-config --libs --cflags sfml-graphics sfml-system sfml-window)
LIBLINK	=	-l$(LIB)
MODELS	=	../../models/include/
ENGINE	=	../../engine/include/
HEADER	=	../include/
INCLUDES=	-I $(HEADER) -I $(MODELS) -I $(ENGINE)

all: $(BINS)

$(BINS): $(DIR)
	$(CC) $(SFML) $(CFLAGS) $(INCLUDES) -fPIC -shared -o $(addprefix $(DIR),$(BINS).dylib) 
$(DIR):
	mkdir $(DIR)
clean:
	rm $(addprefix $(DIR),$(BINS).so)

re: clean all