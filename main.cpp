#include <stdio.h>
#include <errno.h>  
#include <stdlib.h>  

static void KillByPID(char* ProcessLine)
{
    char cmdKILL[16]= {0};
    strcat(cmdKILL,"kill ");
    memcpy(cmdKILL+5,ProcessLine+10,5);//process USER length is 10,PID length is 5
    //printf("execute %s  \n",cmdKILL);
    system(cmdKILL);
}
static bool ExecuteShellCmd(char* cmd)
{
    FILE* fStream = NULL;
    fStream = popen(cmd,"r");
    if(fStream == NULL)
    {
        printf("execute %s failed (%s) \n",cmd,strerror(errno));
        return false;
    }
    char aLine[128] = {0};
    while(fgets(aLine,128,fStream))
    {
	KillByPID(aLine);
    }
    pclose(fStream);
    return true;
}
int main(int argc, char** argv)
{
    if(argc<2)
    {
	printf("\n please input process name \n");
        return 0;
    }
    const char* ProcessName = argv[1];
    if(strlen(ProcessName)>60)
    {
	printf("\n process name fatal!!!!\n");
    }
    char cmd[64] = {0};
    sprintf(cmd,"ps|grep -iE %s",ProcessName);
    ExecuteShellCmd(cmd);

    return 0;
} 
