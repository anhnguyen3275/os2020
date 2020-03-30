#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main() {
	int pid = fork();
	int pid1;
	if(pid == 0) {
		pid1 = fork();
		if(pid1 == 0 ){
			printf("\n The child after fork(), launching ps -ef");
			char *arg[]={"/bin/ps", "-ef", NULL};
			execvp("/bin/ps", arg);
		}
		wait(NULL);
		printf("\n The child after fork(), launching free -h");
		char *args[]={"free", "-h", NULL};
		execvp("free", args);
	}
	else {
		wait(NULL);
		printf("\n Parent after fork()");
	}
	return 0;
}