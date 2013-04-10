#include <iostream>
#include <exception>
# include <stdexcept>
#include "ErrorHandlingModele.h"

namespace SAMSErrorHandling
{
    using namespace std;

	void Initialize(void)
	{
	   cin.exceptions(cin.failbit);
	}

	int HandleNotANumberError(void)
	{
	   cerr<<"Input error - not a number?"<<endl;

	   cin.clear();

	   char BadInput[5];
	   cin>>BadInput;

	   return 1;
	}

	int HandleRuntimeErorr(std::runtime_error theRuntimeError)
	{
	   cerr << theRuntimeError.what() << endl;

	   return 1;
	}
}