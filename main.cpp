#include "translator.h"

int main()
{
	Telega t(0.0, 0.0);
   	t.secondTypeOfMoving(0.0, 0.0, 100.0, 0.0);//A
  	t.secondTypeOfMoving(100.0, 0.0, 100.0, -200.0);//B
   	t.secondTypeOfMoving(100.0, -200.0, 200.0, -200.0);//C
   	t.secondTypeOfMoving(200.0, -200.0, 200.0, 0.0);//D
   	t.secondTypeOfMoving(200.0, 0.0, 0.0, 0.0);//E

 	// t.pognali(0.0, 0.0, 100.0, 0.0);//A
  	// t.pognali(100.0, 0.0, 100.0, -200.0);//B
   	// t.pognali(100.0, -200.0, 200.0, -200.0);//C
   	// t.pognali(200.0, -200.0, 200.0, 0.0);//D
   	// t.pognali(200.0, 0.0, 0.0, 0.0);//E

	return 0;
}
