#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 10; ++i)
    {
        int id = fork();
        if (id)
        {
            printf("fork %d\n", id);
            char *args[3] = {"./client", argv[1],  NULL};
            execvp(args[0], args);
        }
        sleep(1);
    }
    
    return 0;
}
