// _KM02_4.c

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <limits.h>//ULONG_MAX

int main(int argc, char **argv){//3 процессы: son1  son2  son3
	if(argc < 2){ perror("no enough parameter"); return 1; }
	
	FILE * fi;
	fi = fopen(argv[1], "r");
	if(fi == NULL){ perror("can't open file"); return 2; }

	unsigned long num;
	int shmid, semid, fd;
	
	pid_t pid1, pid2, pid3;//процесс 1 2 3
	key_t key;
	
	unsigned long *shmaddr;
	struct sembuf P1 = {0,-1,0}, P2 = {1,-1,0}, P3 = {2,-1,0};
	struct sembuf V1 = {0, 1,0}, V2 = {1, 1,0}, V3 = {2, 1,0};

	fd = creat("a.txt", 0664);
	if(fd < 0){ perror("creat"); return 3; }

	key = ftok("a.txt", 'a');
	if(key < 0){ perror("ftok"); return 3; }
	
	close(fd);

	shmid = shmget(key, sizeof(long), IPC_CREAT | 0666);
	if(shmid < 0){ perror("shmget"); return 4; }

	shmaddr = shmat(shmid, NULL, 0);
	if(shmaddr == (void*)-1){ perror("shmat"); return 5; }

	semid = semget(key, 3, IPC_CREAT | 0666);
	if(semid < 0){ perror("semget"); return 3; }

	semctl(semid, 0, SETVAL, 0); 
	semctl(semid, 1, SETVAL, 0);
	semctl(semid, 2, SETVAL, 0);

	pid1 = fork();//*******************************************
	if(pid1 < 0){ perror("fork1"); return 4; }
	if(pid1 == 0){//son1 
		int flag = 1;//при flag = 1 передать число son2
			     //при flag = 0 передать чилсо son3
		while(fscanf(fi, "%lu", &num) == 1){
			*shmaddr = num;
			if(flag){
				flag = 0;
				semop(semid, &V2, 1);
			}
			else{
				flag = 1;
				semop(semid, &V3, 1);
			}
			semop(semid, &P1, 1);
		}

		*shmaddr = ULONG_MAX;
		
		semop(semid, &V2, 1);//завершить son2
		semop(semid, &V3, 1);//завершить son3
		
		return 0;	//son1 завершиться
	}
	
	pid2 = fork();//*******************************************
	if(pid2 < 0){ perror("fork2"); return 5; }
	if(pid2 == 0){//son2
		while(1){
			semop(semid, &P2, 1);
			if(*shmaddr == ULONG_MAX)
				break;
			fprintf(stdout, "%lu\n", (*shmaddr)+1); fflush(stdout);
			semop(semid, &V1, 1);
		}
		return 0;
	}

	pid3 = fork();//*******************************************
	if(pid3 < 0){ perror("fork3"); return 6; }
	if(pid3 == 0){//son3
		while(1){
			semop(semid, &P3, 1);
			if(*shmaddr == ULONG_MAX)
				break;
			fprintf(stdout, "%lu\n", (*shmaddr)*2); fflush(stdout);
			semop(semid, &V1, 1);
		}
		return 0;
	}

	wait(NULL);
	wait(NULL);
	wait(NULL);
	
	fclose(fi);

	shmdt(shmaddr);
	shmctl(shmid, IPC_RMID, NULL);
	semctl(semid, 0, IPC_RMID, 0);
	
	return 0;
}






















