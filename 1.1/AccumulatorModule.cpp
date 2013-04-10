#include <iostream>
#include <exception>
#include <ios>

#include "AccumulatorModule.h"
#include "PromptModuleH.h"
#include "ErrorHandlingModele.h"



namespace SAMSCalcuator
{
	using namespace std;
/*
	typedef char (*ToGetAnOperator)(void);
	typedef char (*ToGetAnOperand)(void);
	typedef char (*ToHandleResults)(const float theResult);
	typedef char (*ToDisplayMessage)(const char *theMessage);

	struct aCalculatorExternalInterface
	{
	    ToGetAnOperator ToGetAnOperator;
		ToGetAnOperand ToGetAnOperand;
		ToHandleResults ToHandleResults;
		ToDisplayMessage ToDisplayMessage;
	};
*/

	void PrintTape(aTapeElement *TapeRoot)
	{
		static aTapeElement *p = TapeRoot;
		while(p)
		{
		   cout<<p->Operator<<p->Operand<<endl;
		   p=p->NextElement;
		}
	}

	void DeleteTape(aTapeElement **TapeRoot)
	{
	    static aTapeElement *p1,*p2;

		p1=(*TapeRoot);
		p2=(*TapeRoot);

		while(p1)
		{
           p1 = p1->NextElement;
		   delete p2;
		   p2 = p1;
		}

		(*TapeRoot)->NextElement = NULL;
	}


	void Tape(const char theOperator,const float theOperand)
	{
		/*static const int myTapeChunk = 3;
		static char *myOperator = new char[myTapeChunk];
		static float *myOperand = new float[myTapeChunk];

		static int myTapeSize = myTapeChunk;//Array Size

		static int myNumberOfEntries = 0;

		switch(theOperator)
		{
			case '?': for(int index = 0;index < myNumberOfEntries;index++)
						{
							cout << myOperator[index]<<myOperand[index]<<endl;
						};break;
			case '.':delete []myOperator;
						delete []myOperand;
						break;
			default:
				if(myNumberOfEntries == myTapeSize)
				{
					char *ExpandedOperator = new char[myNumberOfEntries + myTapeChunk];
					float *ExpandedOperand = new float[myNumberOfEntries + myTapeChunk];

					char *FromOperator = myOperator;
					float *FromOperand = myOperand;

					char *ToOperator =ExpandedOperator;
					float *ToOperand = ExpandedOperand;

					for(int index = 0;index < myNumberOfEntries;index++)
					{
						*ToOperator++ = *FromOperator++;//如果用【】访问实际上是【index*（char）】，大量的乘法会使复制操作变慢
						*ToOperand++ = *FromOperand++;
					}

					delete []myOperator;
					delete []myOperand;

					myOperator = ExpandedOperator;
					myOperand = ExpandedOperand;

					myTapeSize +=myTapeChunk;
				}

			myOperator[myNumberOfEntries]=theOperator;
			myOperand[myNumberOfEntries]=theOperand;
			myNumberOfEntries++;
		}
		*/

		static aTapeElement *TapeRoot = NULL;

		if(theOperator == '?')
		{
		   PrintTape(TapeRoot);
		}
		else if(theOperator == '.')
		{
		   DeleteTape(&TapeRoot);
		}
		else
		{
		   aTapeElement *NewElement = new aTapeElement;
		   NewElement ->Operand = theOperand ;
		   NewElement ->Operator = theOperator ;
		   NewElement ->NextElement = NULL;

		   if(TapeRoot == NULL)
		   {
		       TapeRoot = NewElement;
		   }
		   else
		   {
		       aTapeElement *CurrentTapeElement = TapeRoot;//利用Current指针找到队尾元素，然后将新元素插入

			   while(CurrentTapeElement ->NextElement != NULL)
			   {
			       CurrentTapeElement = CurrentTapeElement ->NextElement;
			   }

			   CurrentTapeElement ->NextElement = NewElement;
		   }
		}
	}

		bool TestOK(const char theOperator,const float theOperand,const float theExpectedResult)
	{
		float Result = SAMSCalcuator::Accumulator(theOperator,theOperand);

		if(Result == theExpectedResult)
		{
			cout << theOperator << theOperand << " - succeeded." << endl;

			return true;
		}
		else
		{
			cout << theOperator << theOperand << " - failed." << "Expected " << theExpectedResult << ", got " << Result << endl;

			return false;
		}
	}


	void SelfTest(void)
	{
		float OldValue = SAMSCalcuator::Accumulator('@');//记录原来累加器当前值，防止当前值在测试时被改变
    
		try
		{
			if(TestOK('@',0,0)&&TestOK('+',3,3)&&TestOK('-',2,1)&&TestOK('*',4,4)&&TestOK('/',2,2))
			{
				cout << "Test completed successfully." << endl;
			}
			else
			{
				cout << "Test failed" << endl;
			}
		}
		catch(...)
		{
			cout << "An exception occured during self test." << endl;
		}

		SAMSCalcuator::Accumulator('@',OldValue);
	}

	float Accumulator(const char theOperator,const float theOperand)
	{
		static float myAccumulator = 0;

		switch(theOperator)
		{
			case '+':
				myAccumulator = myAccumulator + theOperand ;
				Tape(theOperator ,theOperand);
				break;
			case '-':
				myAccumulator = myAccumulator - theOperand ;
				Tape(theOperator ,theOperand);
				break;
			case '*':
				myAccumulator = myAccumulator * theOperand ;
				Tape(theOperator ,theOperand);
				break;
			case '/':
				myAccumulator = myAccumulator / theOperand ;
				Tape(theOperator ,theOperand);
				break;
			case '@'://重置操作数
				myAccumulator = theOperand;
				Tape(theOperator ,theOperand);
				break;
			case '=':
				cout << endl << myAccumulator << endl;
				break;
			case '?':
				Tape(theOperator);
				break;
			default:
				throw runtime_error ("Error - Invalid operator");
		}

		return myAccumulator;
	}
}