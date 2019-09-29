CC		=	clang++
CFLAGS	=	-Wall -Werror -Wextra
BINS	=	Renderer1
DIR		=	../../RenderLib/
SHARED	=	$(addprefix lib,$(OBJ:.o=.so))
OBJ		=	$(SRC:.cpp=.o)
LIB		=	-lsfml-graphics \
			-lsfml-window \
			-lsfml-system
LIBLINK	=	-l$(LIB)
MODELS	=	../../models/include/
ENGINE	=	../../engine/include/
HEADER	=	../include/
INCLUDES=	-I $(HEADER) -I $(MODELS) -I $(ENGINE)

all: $(BINS)

$(BINS): $(DIR)
	$(CC) $(CFLAGS) -fPIC -shared -o $(addprefix $(DIR),$(BINS).dylib) $(INCLUDES) $(addprefix src/,$@.cpp) $(LIB)
	$(CC) $(CFLAGS) -fPIC -shared -o $(addprefix $(DIR),$(BINS).so) $(INCLUDES) $(addprefix src/,$@.cpp) $(LIB)

$(DIR):
	mkdir $(DIR)
clean:
	rm $(addprefix $(DIR),$(BINS).dylib)
	rm $(addprefix $(DIR),$(BINS).so)

re: clean all