// Roll: CS21B2019
// Name: Devarakonda SLR Siddesh

// Write two different programs (Sender and Receiver) in C to demonstrate IPC using message queue. 
// Process "Sender.c" will take input of atleast 10 numbers and share these numbers with the "Receiver.c" process 
// using message queue. The "Receiver.c" will check each numbers and displays 
// how many odd numbers are there among those numbers and displays them.  
// NOTE- Write the program in your own/Lab unix system and after successful execution/showing to TAs. 
// Finally, before the deadline copy-paste the corresponding Receiver.c's Code In this File

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int fd1; // File descriptor for the FIFO
    char *myfifo = "/tmp/myfile1.txt"; // Path to the named pipe (FIFO)

    // Create a named pipe with read and write permissions
    if (mkfifo(myfifo, 0666) == -1) {
        printf("Error in creating named pipe\n");
        return 1;
    }

    int a;
    printf("Enter a number : ");
    scanf("%d", &a);

    // Open the named pipe for writing
    printf("[Sent] Sending %d into fifo file\n", a);
    fd1 = open(myfifo, O_WRONLY);

    // Write the value of 'a' into the named pipe
    write(fd1, &a, sizeof(a));
    close(fd1);

    int b;

    // Open the named pipe for reading
    fd1 = open(myfifo, O_RDONLY);

    // Read the 1's complement of 'a' from the named pipe
    read(fd1, &b, sizeof(b));

    // Print the received value
    printf("[Received] The 1's complement of %d : %d\n", a, b);

    // Close the file descriptor and remove the named pipe
    close(fd1);
    unlink(myfifo);

    return 0;
}
