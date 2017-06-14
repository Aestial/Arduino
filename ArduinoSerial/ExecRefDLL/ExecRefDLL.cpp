// ExecRefDLL.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "stdafx.h"
#include "ArduinoSerial.h"


int _tmain(int argc, _TCHAR* argv[])
{	
	std::cout << ReadValue(8) << std::endl;
	std::cout << circleArea(10.0) << std::endl;
	return 0;
}