#include <stdio.h> 
#include <unistd.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <fcntl.h> 
#define NOMBREFIFO "mififo" 
#define TAM_BUF 100 
#define TRUE 1 

int main(void) {       //NO ACABADOOO!
	int fp;   
	char buffer[TAM_BUF];   
	int nbytes;   
	
	//mkfifo(NOMBREFIFO,S_IFIFO|0660.0);  
	mkfifo(NOMBREFIFO,S_IFIFO);    
	while(TRUE) {      
		fp=open(NOMBREFIFO,O_RDONLY);     
		nbytes=read(fp,buffer,TAM_BUF-1);     
		//buffer[nbytes]='\0';   
		buffer[nbytes]=;   
		printf("Cadena recibida: %s \n",buffer);     
		close(fp); 
		break;  
	}    
	
	return 0; 
}
