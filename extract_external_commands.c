#include "main.h"

void extract_external_commands(char **external_commands)
{
	//variable declaration
	char ch;
	char buffer[25] = {'\0'};
	int i = 0;
	int j = 0;
	//open the file and check
	int fd = open("/home/pravi/LI/project/proj1/external_commands.txt",O_RDONLY);
	//error check
	if(fd == -1)
	{
		printf("Open failed\n");
		exit(1);
	}
	//Read command from file
	while(read(fd, &ch, 1) > 0)
	{
		if(ch != '\n')  //new line encountered,1 command extracted
		{
			buffer[i++] = ch; //bash
		}
		else
		{
			//allocate memory dynamically
			external_commands[j]=calloc(strlen(buffer) + 1, sizeof(char));
			//copy contents
			strcpy(external_commands[j++], buffer);
			//append null char at end
			external_commands[j]='\0';
			//clear the buffer
			memset(buffer,'\0',25);
			i = 0;
		}

	}
	

}
