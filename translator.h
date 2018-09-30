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
		double _spdKoef;
		std::string _commandForTurning;
		std::string _commandForMoving;
		std::string _commandForMovingBySecondTypeOfMoving;
		const double _radius;
		
	public:
		Telega(double curX, double curY);
		void setPoint(double gotoX, double gotoY);
		void turnOnAngle();
		void goOnLine();
		void pognali(double gotoX, double gotoY);
		void secondTypeOfMoving(double gotoX, double gotoY);
		void angleForsecondTypeOfMoving();
		std::string getCommandTurn();
		std::string getCommandMove();
		std::string grtCommandMoveBySecondType();
};
