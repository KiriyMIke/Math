#include "translator.h"

std::string intToStr(double n)
{
    return std::to_string(static_cast<int>(n));
}


Telega::Telega(double curX, double curY)
	:
	_curX(curX),
	_curY(curY),
	_curAlpha(0.0),
	_gotoAlpha(0.0),
	_commandForTurning(""),
	_commandForMoving(""),
	_radius(300.0),
	_spdKoef(0.0)
{

}

void Telega::setPoints(double curX, double curY, double  gotoX, double gotoY)
{
	_curX = curX;
	_curY = curY;
	_gotoX = gotoX;
	_gotoY = gotoY;
}

void Telega::turnOnAngle()
{
	double alpha = atan2(_gotoY - _curY, _gotoX - _curX) * 180.0 / M_PI;
	double thisAngleSmaller;
	double orThisAngleSmaller;
	
	if (_curAlpha > alpha)
	{
		thisAngleSmaller = _curAlpha - alpha;
		orThisAngleSmaller = alpha - _curAlpha + 360.0;
	}
	else
	{
		thisAngleSmaller = alpha - _curAlpha;
		orThisAngleSmaller = _curAlpha - alpha + 360.0;
	}

	(thisAngleSmaller > orThisAngleSmaller) ? _gotoAlpha = orThisAngleSmaller : _gotoAlpha = thisAngleSmaller;

   	(_gotoAlpha + _curAlpha == alpha) ? _spdKoef = -1.0 : _spdKoef = 1.0;

	double arcLength = round(M_PI * _radius * _gotoAlpha / 180.0 * 10.0) / 10.0;
	_spdKoef = _spdKoef * 255.0;

	_curAlpha = alpha;

	if (arcLength == 0.0)
	{
        _commandForTurning = intToStr(_curAlpha) + ".0 0.0 0.0 ";
        _commandForTurning += intToStr(_curAlpha) + ".0 0.0 0.0 ";
        _commandForTurning += intToStr(_curAlpha) + ".0 0.0 0.0";
	}
	else
    {
		_commandForTurning =  "30.0 " + intToStr(_spdKoef) + ".0 " + intToStr(arcLength) + ".0 ";
		_commandForTurning += "-30.0 " + intToStr(-_spdKoef) + ".0 " + intToStr(arcLength) + ".0 ";
		_commandForTurning += "-90.0 " + intToStr(_spdKoef) + ".0 " + intToStr(arcLength) + ".0";

	}
}

void Telega::goOnLine()
{
	double hypotenuse = sqrt(pow((_gotoX - _curX), 2) + pow((_gotoY - _curY), 2));
	if (hypotenuse == 0)
	{
		_commandForMoving = "ok";
	}
	else
	{
		_commandForMoving =  "0.0 255.0 " + intToStr(hypotenuse) + ".0 ";
		_commandForMoving += "0.0 255.0 " + intToStr(hypotenuse) + ".0 ";
		_commandForMoving += "0.0 255.0 " + intToStr(hypotenuse) + ".0";
	}
}

void Telega::pognali(double curX, double curY, double gotoX, double gotoY)
{
	setPoints(curX, curY, gotoX, gotoY);

	turnOnAngle();
	goOnLine();

	_curX = _gotoX;
    _curY = _gotoY;

	std::string command1 = getCommandTurn();
	std::string command2 = getCommandMove();


   std::cout << command1 << "\n";

   std::cout << command2 << "\n";
}

void Telega::angleForsecondTypeOfMoving()
{
	double alpha = atan2(_gotoY - _curY, _gotoX - _curX) * 180.0 / M_PI;
	if (abs(alpha) <= 90.0)
	{
		_gotoAlpha = alpha;
		_spdKoef = 1.0;
	}
	if (alpha < 180.0 && alpha > 90.0)
	{
		_gotoAlpha = alpha - 180;
		_spdKoef = -1;
	}
	if (alpha > -180.0 && alpha < -90.0)
	{
		_gotoAlpha = 180 + alpha;
		_spdKoef = -1.0;
	}
	if (abs(alpha) == 180.0)
	{
		_gotoAlpha = 0.0;
		_spdKoef = -1.0;
	}
}

void Telega::secondTypeOfMoving(double curX, double curY, double gotoX, double gotoY)
{
    setPoints(curX, curY, gotoX, gotoY);
    angleForsecondTypeOfMoving();


	double hypotenuse = sqrt(pow((_gotoX - _curX), 2) + pow((_gotoY - _curY), 2));
	_spdKoef *= 255.0;

	_commandForMovingBySecondTypeOfMoving = intToStr(_gotoAlpha) + ".0 " + intToStr(_spdKoef) + ".0 " + intToStr(hypotenuse) + ".0 ";
	_commandForMovingBySecondTypeOfMoving += intToStr(_gotoAlpha) + ".0 " + intToStr(_spdKoef) + ".0 " + intToStr(hypotenuse) + ".0 ";
	_commandForMovingBySecondTypeOfMoving += intToStr(_gotoAlpha) + ".0 " + intToStr(_spdKoef) + ".0 " + intToStr(hypotenuse) + ".0";

	std::cout << grtCommandMoveBySecondType() << "\n";

	_curX = _gotoX;
    _curY = _gotoY;
}

std::string Telega::grtCommandMoveBySecondType()
{
	return _commandForMovingBySecondTypeOfMoving;
}

std::string Telega::getCommandTurn()
{
	return _commandForTurning;
}

std::string Telega::getCommandMove()
{
	return _commandForMoving;
}
