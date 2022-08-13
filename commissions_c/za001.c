#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/wait.h>
#include <unistd.h>



int main(int argc, char** argv){
	pid_t pid;
	key_t key;

	FILE* fptr = fopen(argv[1], "r");
	FILE* fptr2 = fopen(argv[2], "w+");

	int fd[2];
	char chr;


	// argv[1]    argv[2]
	if(pipe(fd) == -1){ perror("pipe"); return 1; }
	pid = fork();
	if(pid == 0){//son
		close(fd[1]);
		char c;
		int count = 0;
		while(read(fd[0], &c, 1) > 0){
			fprintf(fptr2, "%c", c);
			count++;
			if(count == 100)
				break;
		}
		close(fd[0]);
			
		return 0;		
}



	close(fd[0]);
	//father
	while(fscanf(fptr, "%c", &chr) != EOF){
		write(fd[1], &chr, sizeof(char));
	}
	close(fd[1]);
	wait(NULL);
	
	fclose(fptr);
	fclose(fptr2);
	return 0;
}















