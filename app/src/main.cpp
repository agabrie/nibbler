
#include "./Nibbler.hpp"

int main(int argc, char *argv[])
{
	Nibbler *nibbler;
	int width;
	int height;
	int level;
	if(argv[1])
		width = atoi(argv[1]);
	if(argv[2])
		height = atoi(argv[2]);
	if(argv[3])
		level = atoi(argv[3]);
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
	std::cout << "Start Game\n";
	nibbler->startGame();
}
