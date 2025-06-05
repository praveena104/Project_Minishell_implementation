#include "main.h"

pid_t pid;
void scan_input(char *prompt, char *input_string)
{
	//variable declaration
	char *command = '\0';
	int command_type,ret_status,status;
	//register the signal--->SIGINT
	signal(SIGINT,signal_handler);
	signal(SIGTSTP,signal_handler);
	while(1)
	{
		memset(input_string , '0', 25);

	//Display the prompt
	printf(ANSI_COLOR_RED"[%s]$"ANSI_COLOR_RESET,prompt);
	//claer output buffer
	fflush(stdout);

	//read input from user
	scanf("%[^\n]s",input_string);
	//clear input buffer
	getchar();

	//customize the prompt
	if(!(strncmp("PS1=",input_string,4)))
	{
		if(input_string[4]!=' ')
		{
		strcpy(prompt,&input_string[4]);
		//flush the input_string
		memset(input_string,'0',25);
		continue;
		}
	}
	//To get the command
	command = get_command(input_string);
	//check command internal/external
	command_type = check_command_type(command);
	printf("Command type = %d\n",command_type);

	//external commands
	if(command_type == EXTERNAL)
	{
		pid = fork();
		if(pid == 0)
		{
			//child will execute command and parent waits
			ret_status = system(input_string);
			if(ret_status == 0)
			{
				exit(0);
			}
			else
				exit(1);
		}
		else if(pid > 0)
		{
			//parent process
			wait(&status);
			if(WIFEXITED(status))
				printf("Child with pid %d terminated normally\n",pid);

		}
		else
		{
			printf("fork failed\n");
			exit(2);
		}
	
	}
	//call function to implement echo command
	echo(input_string,status);
	//function to implement internal commands
	execute_internal_commands(input_string);

	}


}
