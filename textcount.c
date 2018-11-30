#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define W=0;
#define R=1;
#define TRUE=1;
#define FALSE=0;
#define PERIOD='.';

int main(){
    int p[2],q[2];
    int c, total, pid;
    int newline=TRUE;
    pipe(q);
    pipe(p);
    FILE *fdopen(),*fp;
    switch (pid=fork()){
           case FALSE:{
                close(p[W]);
                close(R);dup(p[R]);close(p[R]);close(p[W]);
                close(W);dup(q[W]);close(q[R]);close(q[W]);
                execl(¨/home/usuario/Escritorio/count¨,¨count¨,0);
                printf (“textcount: exec failed”);
                exit(1);}
           case -1:{
                printf(“textcount culd not fork a process”);
                exit(1);}
           default:{
                close(p[R]);
                close(q[W]);
                fp = fdopen(p[W],”w”);}}
while (c=getchar()!=EOF){
      switch (newline){
             case TRUE:{
                  if (c==’\n’)
                     putc(c,fp);
                  else if (c==PERIOD)
                          while ((c=getchar())!=EOF&&c!=’\n’);
                  else{
                       putc(c,fp);
                       newline = FALSE;}}
             break;
             default:{
                      putc(c,fp);
                      if (c==’/n’)
                         newline=TRUE;}
             break;}}
fclose(fp);
close(R);dup(q[R]);close(q[R]);close(q[W]);
scanf(“%d”,&total);
printf(“Total number of characters: %d/n”,total);
exit(0);
}
