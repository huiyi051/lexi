#include <iostream>

#include "PromptModuleH.h"

using namespace std;

namespace SAMSPrompt
{
	void PauseForUserAcknowledgement(void)
	{
		//Note:you must type something before enter
		char StopCharacter;
		cout<<endl<<"Press a key and \"Enter\":";
		cin>>StopCharacter ;
	}

	bool UserWantsToContinue(const char* theThingWeAreDoing)
	{
		char DoneCharacter;

		bool InvalidCharacterWasEntered = false;

		do{
			cout << endl << theThingWeAreDoing << " - Press \"n\" and \"Enter\" to stop or Press \"y\" to continue:";

			cin >> DoneCharacter ;

			InvalidCharacterWasEntered = !((DoneCharacter=='y')||(DoneCharacter=='n'));

			if(InvalidCharacterWasEntered)
			{
			   cout << "...Error - "<<"please enter \"y\" or \"n\"."<<endl;
			}
		}while(InvalidCharacterWasEntered);

		return (DoneCharacter != 'n');
	}
}