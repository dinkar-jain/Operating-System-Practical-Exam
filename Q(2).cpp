#include <iostream>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

int main()
{
    pid_t pid;
	/* fork a child process */
	pid = fork();
    if (pid < 0)
    {
		/* error occurred */
		cout << "Fork Failed";
        return 1;
    }
    else if (pid == 0)
    {
		/* child process */
		/* child will wait for the parent to complete */
		wait(NULL);
		cout << "Child Complete"<<endl;
    }
    else
    {
		/* parent process */
        cout << "Parent Complete"<<endl;
    }
    return 0;
}
