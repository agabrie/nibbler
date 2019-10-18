
#include "./Nibbler.hpp"
bool is_number(const std::string& s){
	return !s.empty() && std::find_if(s.begin(),s.end(),[](char c){return !std::isdigit(c);}) == s.end();
}
class IncorrectWidthException:public std::exception {
	const char * what () const throw(){
		return "Width of board must be greater than 10 but less than 500";
	}
};
class IncorrectHeightException:public std::exception {
	const char * what () const throw(){
		return "Height of board must be greater than 10 but less than 500";
	}
};
class IncorrectLevelException:public std::exception {
	const char * what () const throw(){
		return "Length of player can't exceed half the width or height of board or be negative";
	}
};
class IncorrectArgumentTypeException:public std::exception {
	const char * what () const throw(){
		return "Incorrect argument format must be (int int int)";
	}
};
class IncorrectNumberArgumentsException:public std::exception {
	const char * what () const throw(){
		return "Number of additional arguments : 2-3";
	}
};

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
			std::cout << "heree";
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
	else if(argc == 1)
	{
		nibbler =new Nibbler(21,21);
	}
	else{
		throw IncorrectNumberArgumentsException();
	}
	std::cout << "Start Game\n";
	nibbler->startGame();
}

