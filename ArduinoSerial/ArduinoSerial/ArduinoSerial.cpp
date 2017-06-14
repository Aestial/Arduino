// MathFuncsDll.cpp : Defines the exported functions for the DLL application.

//#include "stdafx.h"
#include "ArduinoSerial.h"
#include <stdexcept>
#include <stdio.h>
#include <tchar.h>
#include "SerialClass.h"	// Library described above
#include <string>

float circleArea(float radius)
{
	return 3.1416f * radius * radius;
}

float ReadValue(float port)
{
	Serial* SP = new Serial("COM9");    // adjust as needed

	char incomingData[256] = "";			// don't forget to pre-allocate memory
	//printf("%s\n",incomingData);
	int dataLength = 256;
	int readResult = 0;

	if (SP->IsConnected())
	{
		readResult = SP->ReadData(incomingData, dataLength);
		float i = atof(incomingData);
		return i;
	}
	return -1.00f;
}
