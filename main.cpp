#include "translator.h"

int main()
{

	Telega t(0.0, 0.0);
	t.pognali(200.0, 0.0);
	t.pognali(200.0, -100.0);
	// std::cout << t.getCommandTurn() << "\n" << t.getCommandMove() << "\n";

	return 0;
}