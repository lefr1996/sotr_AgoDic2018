#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <limits.h>

void main(){
	int x,y,n,i,r;
	n=0;
	x=47;
	y=100;
	printf("\nAnalizando numeros primos desde %d hasta %d.",x,y);
	//while (x<=y){
		printf("\nAnalizando %d...",x);
		for (i=1;i++;i<x){
			r=x-(x/i)*i;
			if (r==0)
				n++;
		}
		if (n==1)
			printf("-> Es primo\n",x);
		else
			printf("-> No es primo");
		n=0;
		x++;
	//}
}
