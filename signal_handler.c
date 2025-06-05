#include "main.h"

extern pid_t pid;
void signal_handler(int sig_num)
{
	if(pid != 0)
	{
		if(sig_num == SIGINT)
		{
			//terminate process
			kill(pid,SIGKILL);
		}
		//else handle SIGTSTP signal--->handler
		else if(sig_num == SIGTSTP)
		{
			printf("\nProcess %d suspended\n", pid);
			kill(pid,SIGSTOP);
		}
	}

	//if no foreground process exits--->redisplay the prompt
	else
	{
		printf("\n[minishell]$ ");
        	fflush(stdout);
	}
}	

