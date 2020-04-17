#include <cctype>
#include <cstddef>

#include "digit-sum.hh"

int
digitSum(const char* str)
{
	int acc = 0;
	bool wantsDigit = true;
	for (const char* p = str; p; ++p) {
		char c = *p;
		if(!((c >= '0' && c <= '9') || c == ' ' || c == '+')) break;
		if(c == 0 ) break;
		if(c == '+'){ 
			if(wantsDigit) break;
			wantsDigit = true;
		}
		else if (isdigit(c)){
			if (wantsDigit == false) break;
		       	acc = acc + *p - '0';
			wantsDigit = false;
		}
    	}
	return acc;
}
