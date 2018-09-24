#include "translator.h"

int main()
{

	Telega t(500.0, 500.0);
	t.pognali(0.0, 0.0, 400.0, -400.0);
	// std::cout << t.getCommandTurn() << "\n" << t.getCommandMove() << "\n";

	return 0;
}