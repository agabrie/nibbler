
#include "./Nibbler.hpp"

int main(int argc, char *argv[])
{
	Nibbler *nibbler;
	int width;
	int height;
	int level;
	// std::cout << "Test";
	if(argc > 1){
	if(argv[1] ){
		// std::cout << "width : " << width;
		if(is_number(argv[1])){
			width = atoi(argv[1]);
			if(width < 10 || width > 500)
				throw IncorrectWidthException();
		}
		else
		{
			// std::cout << "here";
			throw IncorrectArgumentTypeException();
		}	
	}
	if(argv[2]){
		// height = atoi(argv[2]);
		if(is_number(argv[2])){
			height = atoi(argv[2]);
			// std::cout << height;
			if(height < 10 || height > 500)
				throw IncorrectHeightException();
		}
		else
		{
			// std::cout << "heree";
			throw IncorrectArgumentTypeException();
		}
	}
	if(argv[3]){
		// level = atoi(argv[3]);
		if(is_number(argv[3])){
			level = atoi(argv[3]);
			if(level >= (int)(width/2) || level >= (int)(height/2) || level < 1)
				throw IncorrectLevelException();
		}
		else
		{
			throw IncorrectArgumentTypeException();
		}
	}}
	if(argc == 4){
		nibbler=new Nibbler(width,height,level);
	}
	else if(argc == 3){
		nibbler =new Nibbler(width,height);
	}
	else if(argc == 2)
		nibbler = new Nibbler(width,width);
	else{
		nibbler =new Nibbler(21,21);
	}
	// std::cout << "Start Game\n";
	nibbler->startGame();
}
