#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>


int main(){
	int tuberia1[2], tuberia2[2], tuberia3[2], pid1, pid2;
	
	pipe(tuberia1); 
	pipe(tuberia2);
	pipe(tuberia3);
	
	int n1, n2, n;
	n1 = 0, n2 = 1;
	
	
	pid1 = fork();
	if (pid1 == 0) {
		pid2 = fork();}
	
	write(tuberia1[1], &n1, sizeof(n1));
	write(tuberia2[1], &n2, sizeof(n2));
	
	for (int i=0; i<10; i++) {
		if (pid1 == 0) {
			
			if (pid2 == 0){  
				while( pid1 != wait(0));	
				
				read(tuberia1[0], &n2, sizeof(n2));
				n1 = n2;
				
				write(tuberia1[1], &n1, sizeof(n1));
				
				 
			} else { 
				while( pid1 != wait(0));
				
				read(tuberia2[0], &n, sizeof(n));
				
				n2 = n;
				write(tuberia2[1], &n2, sizeof(n2));
				
			}
			
		} else { 
			read(tuberia1[0], &n1, sizeof(n1));
			printf("proceso1 me manda n1: %d\n", n1);
			read(tuberia2[0], &n2, sizeof(n2));
			printf("proceso2 me manda n2: %d\n", n2);
			n = n1 + n2;
			
			write(tuberia1[1], &n2, sizeof(n2));
			write(tuberia2[1], &n, sizeof(n));
			
			printf("proceso3: %d\n\n", n);
			 
		}
	}
	
	close(tuberia1[1]);
	close(tuberia1[0]);
	close(tuberia2[0]);
	close(tuberia2[1]);
	close(tuberia3[1]);
	close(tuberia3[0]);
	
	return 0;
}

