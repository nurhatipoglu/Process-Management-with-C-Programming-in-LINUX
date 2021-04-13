#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#include <sys/wait.h>
#include <mqueue.h>
#include <stddef.h>

int main()
{
    srand(time(NULL));
    mqd_t mqd;
    int priority;
    struct mq_attr atributos = {.mq_maxmsg = 10, .mq_msgsize = 50};
    int status;
    int num_children=4;
    int buffer[num_children];
    int rcvmsg[num_children];
    int *ptr1;
    int *ptr2;
    int pid;
    ptr1 = buffer;
    ptr2 = rcvmsg;

    for(int i=0;i<num_children;i++){
       buffer[i] = i+1;
    }
    for (int i = 0; i < num_children; i++)
    {
      if (pid=fork()==0)
      {
        if((mqd = mq_open("/queuetest.txt", O_CREAT | O_WRONLY, 0666, &atributos))==-1)
          {
              perror("child mq_open");
              exit(1);
          }
        if((mq_send(mqd, (char *)(ptr1+i), 50, i))==-1)
        {
            perror("mq_send");
            exit(1);
        }
        mq_close(mqd);
  }
}
for (int i=0;i< num_children;i++){
  if((mqd = mq_open("/queuetest.txt", O_CREAT | O_RDONLY, 0666, &atributos))==-1){
    perror("parent mq_open");
    exit(1);
  }
  if((mq_receive(mqd, ( char *)(ptr2+i), 50, &priority))==-1)
  {
      perror("mq_recieve(burda da hata yapmazsın btw)");
      exit(1);
  }
  printf("Received (priority:%s,%d): %d\n", (priority == 0) ? "NORMAL" : "URGENT",priority, rcvmsg[i]);
  pid_t childpid;

  if ((childpid = waitpid(-1, &status, 0)) > 0)
  {
      if (WIFEXITED(status))
          printf("PID %d exited normally.  Exit status: %d\n",
                 childpid, WEXITSTATUS(status));
      else
          if (WIFSTOPPED(status))
              printf("PID %d was stopped by %d\n",
                     childpid, WSTOPSIG(status));
          else
              if (WIFSIGNALED(status))
                  printf("PID %d exited due to signal %d\n.",
                         childpid,
                         WTERMSIG(status));
  }
  mq_close(mqd);
}
}
