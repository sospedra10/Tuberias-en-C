#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>



int main() {
	int tuberia1[2], tuberia2[2], pid, i, val;
	i = 0, val = 0;
	
	pipe(tuberia1); 
	pipe(tuberia2);
	
	pid = fork(); 
	
	if (pid == 0) {
		while (i < 5){
			char mensaje[101] = "Mensaje transmitido del padre";
			i++;   
			val++;    
			//enviar	
			
			write(tuberia1[1], &val, sizeof(val));
			
			//recibir
			read(tuberia2[0], &mensaje, sizeof(mensaje));
			
			printf("Valor leído(hijo): %d\n\n",  val);
			
		}//
	} else { 
		while (i < 5) {
			
			char mensaje[101] = "Mensaje transmitido del hijo";
			i++;    
			val = val + 1;
			//enviar
			   
			write(tuberia2[1], &val, sizeof(val));
			
			//recibir
			
			read(tuberia1[0], &mensaje, sizeof(mensaje));
			
			printf("Valor leído(padre): %d\n\n", val);
		
		}
	}
	
	
	close(tuberia1[1]);
	close(tuberia2[0]);
	close(tuberia1[0]);
	close(tuberia2[1]);
	
	return 0;
}

