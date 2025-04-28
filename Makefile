COMPILE=clang++
COMPILER_FLAGS= -Wall -Werror -Wextra --std=c++17 -stdlib=libc++
BUILD_DIRECTORY=build
SOURCE_FILES= $(ENGINE) \
	$(RENDERERS)\
	$(MODELS)\
	$(APP)
ENGINE := $(shell find engine/src -name "*.cpp")
MODELS := $(shell find models/src -name "*.cpp")
RENDERERS := $(shell find renderer/Renderer1 -name "*.cpp")
APP := $(shell find app -name "*.cpp")

BINARY=nibbler
OBJECTS := $(addprefix $(BUILD_DIRECTORY)/,$(SOURCE_FILES:%.cpp=%.o))
# LIBRARY = -lsfml-graphics -lsfml-window -lsfml-system
LIBRARY_LINK= -l$(LIBRARY)
SFML = $(shell pkg-config --libs --cflags sfml-graphics sfml-system sfml-window)
HEADERS	= engine/include\
	renderer/include\
	models/include\
	app/include
$(BUILD_DIRECTORY)/%.o: %.cpp 
	@echo "building files..."
	
	$(COMPILE) $(COMPILER_FLAGS) -I$(subst src,include,$($<:.cpp=.hpp)) -c $< -o $(basename $<).o
	mv *.o $(BUILD_DIRECTORY)
$(INCLUDE)
# DYLIBS = -l renderer/Renderer1/rend1.dylib\
	# -l renderer/Renderer2/\
	# -l renderer/Renderer3/
INCLUDE_HEADERS = $(addprefix -I, $(HEADERS))
LIBRARIES		= 
LIBRARY_LINK		= $(addprefix -l, $(LIBRARIES))
# LIBLINK = /renderer/Renderer1
all:$(BINARY) library_rebuild

$(BINARY): $(SOURCE_FILES) $(HEADERS) $(OBJECTS)
	echo -L$(LIBRARY_LINK)
	$(COMPILE) $(SFML) $(COMPILER_FLAGS) $(INCLUDE_HEADERS) $(SOURCE_FILES) -o $(BINARY) -ldl ./RenderLib/Renderer1.dylib
	# ar rc $(OBJECTS)
	# ranlib $(BINARY)
	# rm $(OBJECTS)

library_rebuild:
	make -C ./renderer/Renderer1
	make -C ./renderer/Renderer2
	make -C ./renderer/Renderer3
	
clean:
	@echo "####### removing binary $(BINARY) ######"
	rm -f $(BINARY)
	@echo "############### Removing Objects ###############"
	@echo "\t$(OBJECTS:=\n\t)"
	@echo "################################################"
	rm -f $(OBJECTS)

rebuild: clean all

display_files: $(SOURCE_FILES) $(OBJECTS)
	@echo "#################### Files ####################"
	@echo "\t$(SOURCE_FILES:=\n\t)"
	@echo "###############################################"
	@echo "################### OBJECTS ###################"
	@echo "\t$(OBJECTS:=\n\t)"
	@echo "###############################################"