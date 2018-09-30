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
	_radius(280.0)
{

}

void Telega::setPoint(double  gotoX, double gotoY)
{
	_gotoX = gotoX;
	_gotoY = gotoY;
}

void Telega::turnOnAngle()
{
	double spdKoef;
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

   	(_gotoAlpha + _curAlpha == alpha) ? spdKoef = -1.0 : spdKoef = 1.0;

	double arcLength = round(M_PI * _radius * _gotoAlpha / 180.0 * 10.0) / 10.0;
	spdKoef = round(spdKoef * 255.0 * 10.0) / 10.0;

	_curAlpha = alpha;
 	std::cout << alpha << " alpha _gotoAlpha " << _gotoAlpha << "\n"; 
	if (arcLength == 0.0)
	{
        _commandForTurning = intToStr(_curAlpha) + ".0 0.0 0.0 ";
        _commandForTurning += intToStr(_curAlpha) + ".0 0.0 0.0 ";
        _commandForTurning += intToStr(_curAlpha) + ".0 0.0 0.0";
	}
	else
    {
		_commandForTurning =  "30.0 " + intToStr(spdKoef) + ".0 " + intToStr(arcLength) + ".0 ";
		_commandForTurning += "-30.0 " + intToStr(-spdKoef) + ".0 " + intToStr(arcLength) + ".0 ";
		_commandForTurning += "-90.0 " + intToStr(spdKoef) + ".0 " + intToStr(arcLength) + ".0";

	}
}

void Telega::goOnLine()
{
	double gip = sqrt(pow((_gotoX - _curX), 2) + pow((_gotoY - _curY), 2));
	if (gip == 0)
	{
		_commandForMoving = "ok";
	}
	else
	{
		_commandForMoving =  "0.0 -255.0 " + intToStr(gip) + ".0 ";
		_commandForMoving += "0.0 -255.0 " + intToStr(gip) + ".0 ";
		_commandForMoving += "0.0 -255.0 " + intToStr(gip) + ".0";
	}
}

void Telega::pognali(double gotoX, double gotoY)
{
	setPoint(gotoX, gotoY);

	turnOnAngle();
	goOnLine();

	_curX = _gotoX;
    _curY = _gotoY;

	std::string command1 = getCommandTurn();
	std::string command2 = getCommandMove();


   std::cout << command1 << "\n";//отправляем дальше

   std::cout << command2 << "\n";//отправляем дальше
}

void Telega::secondTypeOfMoving(double gotoX, double gotoY)
{
    setPoint(gotoX, gotoY);
    
    double alpha = atan2(_gotoY - _curY, _gotoX - _curX) * 180.0 / M_PI;
	double thisAngleSmaller;
	double orThisAngleSmaller;
	double spdKoef = 0.0;
	
	if (alpha <= 90.0  && alpha <= 0.0)
	{
		spdKoef = 1.0;
	}
	if (alpha < 180.0 && alpha > 90.0)
	{
		_gotoAlpha = alpha - 180;
		spdKoef = -1;
	}
	if (alpha > -180.0 && alpha < -90.0)
	{
		_gotoAlpha = 180 + alpha;
		spdKoef = -1.0;
	}
	if (alpha >= -90 && alpha <= 0.0)
	{
		spdKoef = 1.0;
	}
	if (abs(alpha) == 180.0)
	{
		_gotoAlpha = 0.0;
		spdKoef = -1.0;
	}


	std::cout << _gotoAlpha << " _gotoAlpha spdKoef "<< spdKoef << "\n";

	double gip = sqrt(pow((_gotoX - _curX), 2) + pow((_gotoY - _curY), 2));

	_commandForMoving = intToStr(_gotoAlpha) + ".0 " + intToStr(spdKoef * 255.0) + ".0 " + intToStr(gip) + ".0 ";
	_commandForMoving += intToStr(_gotoAlpha) + ".0 " + intToStr(spdKoef * 255.0) + ".0 " + intToStr(gip) + ".0 ";
	_commandForMoving += intToStr(_gotoAlpha) + ".0 " + intToStr(spdKoef * 255.0) + ".0 " + intToStr(gip) + ".0";

	std::cout << _commandForMoving << "\n";

}

std::string Telega::getCommandTurn()
{
	return _commandForTurning;
}

std::string Telega::getCommandMove()
{
	return _commandForMoving;
}
