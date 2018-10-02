#include "translator.h"

int main()
{
	Telega t;
   	t.secondTypeOfMoving(0.0, 0.0, 100.0, 0.0);//A
  	t.secondTypeOfMoving(100.0, 0.0, 100.0, -200.0);//B
   	t.secondTypeOfMoving(100.0, -200.0, 200.0, -200.0);//C
   	t.secondTypeOfMoving(200.0, -200.0, 200.0, 0.0);//D
   	t.secondTypeOfMoving(200.0, 0.0, 0.0, 0.0);//E

 	// t.firstTypeOfMoving(0.0, 0.0, 100.0, 0.0);//A
  // 	t.firstTypeOfMoving(100.0, 0.0, 100.0, -200.0);//B
  //  	t.firstTypeOfMoving(100.0, -200.0, 200.0, -200.0);//C
  //  	t.firstTypeOfMoving(200.0, -200.0, 200.0, 0.0);//D
  //  	t.firstTypeOfMoving(200.0, 0.0, 0.0, 0.0);//E

	return 0;
}
