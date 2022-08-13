#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<fcntl.h>
#include<limits.h>

int main(){
	int shmid, semid, fd;

	int *shmaddr;
	pid_t pid1, pid2;
	key_t key;
	struct sembuf P1 = {0,-1,0},P2 = {1,-1,0},P3 = {2,-1,0};
        struct sembuf V1 = {0,1,0}, V2 = {1,1,0}, V3 = {2,1,0} ;
	
	fd = creat("aa.txt", 0664);
	close(fd);
	key = ftok("aa.txt", 'h');
	
	shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
	shmaddr = shmat(shmid, NULL, 0);
	semid = semget(key, 3, IPC_CREAT | 0666);
	
	semctl(semid, 0, SETVAL, 0); semctl(semid, 1, SETVAL, 0);
        semctl(semid, 2, SETVAL, 0);
	
	pid1 = fork(); //son1
	if(pid1 == 0){
		int sum = 0;
		while(1){
			semop(semid, &P1, 1);//10000001
			if(*shmaddr == INT_MAX){
				fprintf(stdout, "son1 %d", sum); 
				fflush(stdout);
				break;
			}
			sum += (*shmaddr);
			semop(semid, &V3, 1);
		}
		semop(semid, &V3, 1);
		return 0;
	}
	pid2 = fork(); //son2
	if(pid2 == 0){
		int sum2 = 0;
		while(1){
			semop(semid, &P2, 1);//10000001
			if(*shmaddr == INT_MAX){
				fprintf(stdout, "son2 %d", sum2); 
				fflush(stdout);
				break;
			}
			sum2 += (*shmaddr);
			semop(semid, &V3, 1);
		}
		semop(semid, &V3, 1);
		return 0;
	}
	//father 
	int n;
	int flag = 1;
//	int counter = 0;

	while(scanf("%d", &n) != EOF){
		//printf("read one number\n");
		//fflush(stdout);
		//counter++;
		//if(counter > 5){
		//	break;
		//}
		*shmaddr = n;
		if(flag){
			flag = 0;
			semop(semid, &V1, 1);
		}
		else{
			flag = 1;
			semop(semid, &V2, 1);
		}
		semop(semid, &P3, 1);
	}
	*shmaddr = INT_MAX;
	semop(semid, &V1, 1);
	semop(semid, &P3, 1);
	
	printf("\n"); fflush(stdout);

	semop(semid, &V2, 1);
	semop(semid, &P3, 1);

	shmdt(shmaddr);
	shmctl(shmid, IPC_RMID, NULL);
	semctl(semid, 0, IPC_RMID, 0);

	return 0;
 }


























