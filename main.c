#include "main.h"

int main()
{
	//clear output screen
	system("clear");
	
	//Declare array to store input
	char input_string[25];

	//setting all values to 0
	memset(input_string,'0',25);
	
	//Declare array to store the prompt
	char prompt[25]="minishell";

	//scan the input
	scan_input(prompt,input_string);

	return 0;

}
