#include "pch.h"
#include "Engine.h"

int main()
{
	srand(static_cast<unsigned>(time(NULL)));

	Engine engine;

	engine.run();
}