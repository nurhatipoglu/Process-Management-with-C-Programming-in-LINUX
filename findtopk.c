#include <stdio.h>
#include <stdlib.h>
#include <wait.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include <sys/stat.h>
int yaprak(){
char isim[20];
sprintf(isim,"%d.txt",getpid());
int fd,i=0;
srand(getpid());
fd=open(isim,O_RDWR|O_CREAT|O_TRUNC,0755);

if(fd!=0){
for(int i=0; i<6; i++){
    int buffer=rand()%100;
        write(fd,&buffer,sizeof(int));
    }
int temp=0,values[6];
for(int i=0; i<6; i++){
    lseek(fd,i*sizeof(int),SEEK_SET);
    read(fd,&temp,sizeof(int));
    values[i]=temp;
}
close(fd);
printf("\n\n");
    int j=0;
    temp=0;
    for(i=0;i<5;i++){
        for(j=i+1;j<6;j++){
            if(values[i]<values[j]){
                temp=values[i];
                values[i]=values[j];
                values[j]=temp;
            }
        }
    }

    i=0;
    wait(NULL);
while(i<6){
        printf("->%d ", values[i]);
        i=i+1;
    }
printf("\n");
    for(i=0;i<6;i++){
        if(i==3){
        printf("Dosyadaki %d.en buyuk eleman:%d\n",3,values[2]);
	return values[2];
        }
    }
}
}
int ara(int max, int N, int parent){
    return max;
}
void agac_olustur(int N){
   int i=0,max, parent;
   for(i=0; i<N; i++){
            if(fork()==0){
	                parent=getppid();
                    wait(NULL);
                    max= yaprak();
                    //ara(max,N,parent);
                    printf("İÇERDE MAX=%d ",max);
              		wait(NULL);
                    printf("[son] pid %d from [parent] pid %d\n",getpid(),parent);
                    break;
                    }
   }
}

int main(){
    agac_olustur(4);
}
