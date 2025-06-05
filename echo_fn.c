#include "main.h"

void echo(char *input_string, int status)
{
	//echo $?, echo $$, echo $SHELL
	if(strncmp("echo $?", input_string, 7) == 0)
		printf("%d\n",status);

	if(strncmp("echo $$", input_string, 7) == 0)
		printf("%d\n",getpid());
	//To print executable path of minishell
	if(strncmp("echo $SHELL", input_string, 11) == 0)
		system("pwd");


}
