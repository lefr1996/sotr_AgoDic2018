#include <stdio.h>
#include <stdlib.h> 
#include <pthread.h> 
#include <unistd.h> /*sleep()*/ 
 
void task1(int *counter); 
void task2(int *counter); 
void cleanup(int counter1,int counter2); 
void enter_region(int process);
void leave_region(int proces);
void p();
void q();

int g1=0; 
int g2=0; 
int FALSE=0;
int TRUE=1;
const int N=2;
int turn;
int interested[2];

int main (int argc,char *argv[]) {
	pthread_t thrd1,thrd2; 
	int ret;                    
	/*Crea el primer hilo*/ 
        ret=pthread_create(&thrd1,NULL,(void*)task1,(void*)&g1); 
	if (ret) { 
	   perror("pthread_create: task1"); 
           exit(EXIT_FAILURE);} 
	/*Crea el segundo hilo*/ 
	ret=pthread_create(&thrd2,NULL,(void*)task2,(void*)&g1); 
	if (ret) { 
           perror("pthread_create: task2"); 
	   exit(EXIT_FAILURE);} 
	pthread_join(thrd2,NULL); 
	pthread_join(thrd1,NULL); 
	printf("g1=%d",g1); 
	exit(EXIT_SUCCESS); 
}/* end main()*/ 
 
void task1(int *counter){  
	   p();} 
 
void task2(int *counter){
           q();}
	
void enter_region(int process) /* process 0 o 1 */{
	int other; /* Numero del otro proceso */
	other=1-process; /* Lo opuesto de process */
	if (g1<10)
	   g1=g1+1;
	else
	   exit(EXIT_SUCCESS);
	printf("Process %d increased g1 to %d\n",process,g1);
	interested[process]=TRUE; /* mostrar interes */
	turn=process; /*establecer bandera*/
	while((turn==process)&&(interested[other]==TRUE));/* instruccion nula */	}
	
void leave_region(int process) /* process: quien sale */{
	interested[process]=FALSE;}
	
	/* process 0 */
void p(){
	while(1){
	enter_region(0);
	leave_region(0);
	sleep(1);}}
	
	/* process 1 */
void q(){
	while(1){
	enter_region(1);
	leave_region(1);
	sleep(1);}} 
