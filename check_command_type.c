#include "main.h"

int check_command_type(char *command)
{
    //check whether command is internal/external
    char *builtins[] = {"echo", "printf", "read", "cd", "pwd", "pushd", "popd", "dirs", "let", "eval", "set", "unset", "export", "declare", "typeset", "readonly", "getopts", "source", "exit", "exec", "shopt", "caller", "true", "type", "hash", "bind", "help", NULL};

    //check if the user press the enter key
    if(strcmp(command, "\0") == 0)
        {

                return NO_COMMAND;
        }

    
    //check if the command is builtin
    for(int i = 0; builtins[i] != NULL; i++) //builtin-array so loop is used
    {   
        if(strcmp(command,builtins[i]) == 0)
        {
        return BUILTIN;
        }
    }
    
    //To extract the external commands
    char *external_commands[155]={NULL};
    extract_external_commands(external_commands);

    //check if the command is external command
        for(int i = 0; external_commands[i] != NULL; i++)
        {
            if(strcmp(command,external_commands[i]) == 0)
            {
                return EXTERNAL;
            }
        }
    
    return NO_COMMAND;
}