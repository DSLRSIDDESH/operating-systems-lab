// CS21B2019 DEVARAKONDA SLR SIDDESH
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    pid = fork();
    if(pid < 0)
    {
        printf("Fork Failed\n");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("\n----------Child Process----------\n");
        printf("Child Process ID       : %d\n", getpid());
        printf("Parent Process ID      : %d\n", getppid());
        printf("Return value of fork() : %d\n", pid);
        execlp("./Program32", "Program32", NULL);
        printf("After execlp()\n");
    }
    else
    {
        printf("\n----------Parent Process----------\n");
        printf("Name: Siddesh Devarakonda\n");
        printf("Roll No: CS21B2019\n");
        printf("Institute: IIITDM Kancheepuram\n");
        printf("Process ID             : %d\n", getpid());
        printf("Parent Process ID      : %d\n", getppid());
        printf("Return value of fork() : %d\n", pid);
        wait(NULL);
        printf("After wait()\n");
    }

    return 0;
}