#include <cmath>
#include <cstdlib>
#include <string>
#include <iostream>

class Telega
{
	private:
		double _curX;
		double _curY;
		double _gotoX;
		double _gotoY;
		double _curAlpha;
		double _gotoAlpha;
		std::string _commandForTurning;
		std::string _commandForMoving;
		
	public:
		Telega(double curX, double curY);
		void setPoint(double  gotoX, double gotoY);
		void turnOnAngle();
		void goOnLine();
		void pognali(double gotoX, double gotoY);
		std::string getCommandTurn();
		std::string getCommandMove();
};