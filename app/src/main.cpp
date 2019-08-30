
#include "./Nibbler.hpp"

int main(int argc, char *argv[])
{
	Nibbler nibbler(atoi(argv[1]),atoi(argv[2]));

	nibbler.startGame();
}
