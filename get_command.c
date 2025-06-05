#include "main.h"


//Extract command until space encountered eg:ls -l,echo $
char *get_command(char *input_string)
{
	//Declare an array to store the command
	static char command[25]={'\0'};  
	
//bcoz we cannot return address of local variable so static bcoz local variable create stack and it will be deleted after process over so if itsaddress returns it will create segmentation fault

	int i = 0;
	//run a loop
	while(1)
	{
		if(*input_string == ' ' ||*input_string == '\0')
			break;
		command[i++] = *input_string;
		input_string++;
	}
	command[i] = '\0';
	return command;

}
