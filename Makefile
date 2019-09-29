CC=clang++
CFLAGS= -Wall -Werror -Wextra
SRC =engine/src/*.cpp \
	renderer/Renderer1/src/*.cpp\
	models/src/*.cpp\
	app/src/*.cpp
	# renderer/Renderer2/src/*.cpp\
	renderer/Renderer3/src/*.cpp
BINS=nibbler
OBJ = $(SRC:.cpp=.o)
LIB = -lsfml-graphics -lsfml-window -lsfml-system
LIBLINK= -l$(LIB)
INCLUDE_DIR	= engine/include\
	renderer/include\
	models/include\
	app/include
# DYLIBS = -l renderer/Renderer1/rend1.dylib\
	# -l renderer/Renderer2/\
	# -l renderer/Renderer3/
INCLUDES = $(addprefix -I, $(INCLUDE_DIR))
LIBS		= 
LIBLINK		= $(addprefix -l, $(LIBS))
# LIBLINK = /renderer/Renderer1
all:libre $(BINS)

$(BINS):
	# echo -L$(LIBLINK)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIB) $(SRC) $(LIBLINK) -o $(BINS) -ldl ./RenderLib/*.so
	# ar rc $(BINS) $(OBJ)
	# ranlib $(BINS)
	# rm $(OBJ)

libre:
	make -C ./renderer/Renderer1
	make -C ./renderer/Renderer2
	make -C ./renderer/Renderer3
	
clean:
	rm $(BINS)
	echo $(OBJ)
	# rm $(OBJ)

re: clean all