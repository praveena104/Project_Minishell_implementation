#include "main.h"

void execute_internal_commands(char *input_string)
{
	//variable
	char *path,*backup_path;

	//cd, exit, pwd
	
	//terminate the program-exit
	if(strncmp("exit",input_string,4) == 0)
		exit(1);
	//to print present working directory-pwd
	if(strncmp("pwd",input_string,3) == 0)
		system("pwd");
	//changing directory-cd
	if(strncmp("cd",input_string,2) == 0)
	{
		//cd-->chdir function used to change working directory 
		//cd LI
		//01234
		//chdir(&input_string[3]);  //without space
		//with space
		path = strtok(input_string," ");
		while(path!=NULL)
		{
			backup_path = path;
			path = strtok(NULL," ");
		}
		chdir(backup_path);
	
	}



}
