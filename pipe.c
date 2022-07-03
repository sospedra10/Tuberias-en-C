#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h>


int main() {
	int tuberia[2], pid;
	pipe(tuberia); 
	pid = fork(); 
	
	if (pid == 0) {           
		char  *cadena;            
		cadena = "Hola mundo";           
		close(tuberia[0]);            
		write(tuberia[1], cadena, strlen(cadena)+1);           
		close(tuberia[1]);            
		exit(1);  
		
	} else {           
		char  *cadena;            
		int  bytesLeidos;        
		cadena = (char *) malloc(100 * sizeof(char));           
		close(tuberia[1]);            
		bytesLeidos = read(tuberia[0], cadena, 100);           
		printf("(padre) Mensaje leído: %s\n", cadena );           
		close(tuberia[0]);            
		exit(1);  
	}
}
