# include <iostream>

#include "PromptModuleH.h"
#include "ErrorHandlingModele.h"
#include "AccumulatorModule.h"

using namespace std;

char GetOperator(void)
{
	char Operator;
	cout<<"Operator "<<endl;
	cin>>Operator;

	return Operator;
}

float GetOperand(void)
{
	float Operand = 0;
	cout<<"Operand "<<endl;
	cin>>Operand;

	return Operand;
}
/*
void DisplayValueOnConsole(float theValue)
{
	cout << endl << theValue << endl;
}

void DisplayMessageOnConsole(const char *theMessage)
{
	cout << theMessage << endl;
}
*/

int main(int argc,char* argv[])
{
	SAMSErrorHandling :: Initialize();
	char Operator;

	do{
		try
		{
			Operator = GetOperator();
			
			if(Operator == '+'||Operator == '-'||Operator == '*'||Operator == '/'||Operator == '@')
			{
			    float Operand = GetOperand();
				
				cout<<"="<<SAMSCalcuator::Accumulator(Operator,Operand)<<endl;
			}
			else if(Operator == '!')
			{
			    SAMSCalcuator::SelfTest();
			}
			else if(Operator == '.')
			{
			    //Do nothing
			}
			else
			{
			    SAMSCalcuator::Accumulator(Operator);
			}
		}
		catch(std::runtime_error RuntimeErorr)
		{
		   SAMSErrorHandling :: HandleRuntimeErorr(RuntimeErorr);
		}
		catch(...)
		{
		   SAMSErrorHandling::HandleNotANumberError();
		};
	}
	while(Operator != '.');

	SAMSCalcuator::Tape('.');

	return 0;
}
