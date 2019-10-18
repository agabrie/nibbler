CC=clang++
CFLAGS= -Wall -Werror -Wextra --std=c++17 -stdlib=libc++
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
SFML = $(shell pkg-config --libs --cflags sfml-graphics sfml-system sfml-window)
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
all:$(BINS) libre

$(BINS):
	# echo -L$(LIBLINK)
	$(CC) $(SFML) $(CFLAGS) $(INCLUDES) $(LIB) $(SRC) -o $(BINS) -ldl ./RenderLib/Renderer1.dylib
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