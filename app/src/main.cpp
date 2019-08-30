
#include "./Nibbler.hpp"

int main(int argc, char *argv[])
{
	Nibbler *nibbler;
	if(argc == 4){
		nibbler=new Nibbler(atoi(argv[1]),atoi(argv[2]),atoi(argv[3]));
	}
	else if(argc == 3){
		nibbler =new Nibbler(atoi(argv[1]),atoi(argv[2]));
	}
	else{
		nibbler =new Nibbler(21,21);
	}
	nibbler->startGame();
}
