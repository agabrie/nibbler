#include <AMainLoop.hpp>

#include <ctime>
#include <cmath>
#include <iostream>
void AMainLoop::start()
{
	this->_running = true;
	while (this->_running)
	{
		this->updateFunc();
	}
}

void AMainLoop::stop()
{
	this->_running = false;
}
