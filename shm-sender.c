#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>

#define SHM_SIZE 300

int main()
{
    int shmid;
    char *shm, *s;
    char *word = "siddesh";

    key_t key = 1234;

    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if(shmid < 0)
     {
        printf("Error");
        exit(1);
    }
    shm = shmat(shmid, NULL, 0);
    if(shm == (char *) -1)
    {
        printf("Error");
        exit(0);
    }
    printf("Writing");
    s = shm;
    for(int i=0; i < strlen(word); i++)
        *s++ = word[i];
    *s = '\0';


    return 0;
}