#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/ipc.h>

#define SHM_SIZE 300

int main()
{
    int shmid;
    char *shm, *s;
    key_t key = 1234;

    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if(shmid < 0)
    {
        printf("Error");
        exit(1);
    }
    shm = shmat(shmid, NULL, 0);
    printf("Printing\n");
    for(s = shm; *s != '\0'; s++)
        putchar(*s);

    return 0;
}