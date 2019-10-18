CC		=	clang++
CFLAGS	=	-Wall -Werror -Wextra --std=c++17 -stdlib=libc++
BINS	=	Renderer1
DIR		=	../../RenderLib/
SHARED	=	$(addprefix lib,$(OBJ:.o=.so))
OBJ		=	$(SRC:.cpp=.o)
LIB		=	-lsfml-graphics \
			-lsfml-window \
			-lsfml-system
LIBLINK	=	-l$(LIB)
# MODELS	=	../../models/include/
# ENGINE	=	../../engine/include/
# HEADER	=	../include/
INC_PATHS=	../../models/include/\
			../../engine/include/\
			../include/\
			# ~/.brew/include
        	# /usr/local/Cellar/sfml/2.5.1/include
INCLUDES=	$(addprefix -I,$(INC_PATHS)) 
SFML = $(shell pkg-config --libs --cflags sfml-graphics sfml-system sfml-window)

all: $(BINS)

$(BINS): $(DIR)
	$(CC) $(SFML) $(CFLAGS) -fPIC -shared -o $(addprefix $(DIR),$(BINS).dylib) $(INCLUDES) $(addprefix src/,$@.cpp)
	# $(CC) $(CFLAGS) -fPIC -shared -o $(addprefix $(DIR),$(BINS).so) $(INCLUDES) -L~/.brew/include $(addprefix src/,$@.cpp) $(LIB)

$(DIR):
	mkdir $(DIR)

clean:
	rm $(addprefix $(DIR),$(BINS).dylib)
	rm $(addprefix $(DIR),$(BINS).so)

re: clean all