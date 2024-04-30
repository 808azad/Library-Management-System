/***********************************************************************
// OOP244 Utils Module
// File	Utils.h
// Version 
// Date	
// Author	
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// 
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__

#include <string>
#include <iostream>

namespace sdds {
	class Utils {
	public:
		void flushKey();
		int readInt(int min, int max, const char message[]);
	};
}
#endif // SDDS_UTILS_H__
