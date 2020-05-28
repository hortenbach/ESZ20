/******************************
 * ESZ Aufgabe 4 gruppe 10
 * Note:
 * + Sheduling klasse frei wählbar
 * + 1 Argument Echtzeit Prio
 *****************************/
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

double n_4(int);
void * a3(void *vargp);

int main(int argc, char *argv[])
{    
    if (argc > 2){
        fprintf(stderr, "Too many Arguments!\nUsage: aufgabe4 [RT priority (-19 to 19)]\nUser might add no or one optional argument.\n");
        exit(EXIT_FAILURE);
    }

    pthread_attr_t *tattr;
    if((tattr = (pthread_attr_t *)malloc(sizeof(pthread_attr_t))) == NULL)
            printf("Couldnt allocate memory\n");
            
    pthread_t tid;
    pid_t pid = getpid();
    /* choose real time policy FIFO */
    int policy = SCHED_FIFO;
    int prio;
    int ret, rc;
    struct sched_param param;

    /* initialized with default attributes */
    pthread_attr_init (tattr);

    /* safe to get existing scheduling param */
    pthread_attr_getschedparam (tattr, &param);

    if(argc == 2){
        prio = atoi(argv[1]);
        if((prio > (-19)) && (prio < 19)){
            /* set the priority; others are unchanged */
            param.sched_priority = prio;
            /* setting the new scheduling param */
            ret = pthread_attr_setschedparam (tattr, &param);
            if(ret != 0){
                fprintf(stderr, "Couldnt set priority!\n");
                exit(EXIT_FAILURE);
            }
           printf("Priority: %d\n", param.sched_priority);
        } else {
            printf("Ignored invalid priority.\n");
        }
    }

    /* setting the new scheduling policy */
    ret = pthread_attr_setschedpolicy (tattr, policy);
    //pthread_create(&tid, &tattr, &a3, NULL);
    rc = pthread_create(&tid, NULL, a3, NULL);
    //rc = pthread_create(&thread_id, NULL, PrintHello, (void*)t);  
    if(rc)			/* could not create thread */
    {
        printf("\n ERROR: return code from pthread_create is %d \n", rc);
        exit(1);
    }
    pthread_join(tid, NULL);            /* wait for thread tid     */
    
    return 0;
}

void * a3(void *vargp){

    const int FAK = 16; // Faktor, der n erhöht für die n^4 Berechnung (24 bei Urs)
    double res = 0.0;
    struct timeval start,end;
    unsigned long seconds, microseconds;
    char line[80]={' '};

    // Ausgabe Titelzeile
    sprintf(line," n%18sn_4%2sdelta_t[s]\n\r","","");
    write(STDOUT_FILENO, &line[0], sizeof(line));

    for(int i=0;i<10;i++){

    // Startzeit ermitteln
    gettimeofday(&start,NULL);

    // n^4 berechnen
    res = n_4(FAK*i);

    // Endzeit ermitteln
    gettimeofday(&end,NULL);

    // Ausgabe der vergangen Zeit
    seconds = end.tv_sec - start.tv_sec;
    microseconds = seconds * 1000000 + end.tv_usec - start.tv_usec;
    sprintf(line,"%2d %20f %2lu.%-10lu\n\r",FAK*i,res,seconds,microseconds);
    write(STDOUT_FILENO, &line[0], sizeof(line));
    //printf("n = %d, n_4 = %f, delta_t = %lu.%lu s\n\r",FAK*i,res,seconds,microseconds);
    }
    pthread_exit(NULL); 
    //return NULL;
}

double n_4(int n)
{
  int a,b,c,d;
  double s=0;
  for(a=1; a<=n; a++)
    for (b=1; b <=n; b++)
      for (c=1; c <= n; c++)
        for (d=1; d <=n; d++)
          s+=1;
  return s;
}
