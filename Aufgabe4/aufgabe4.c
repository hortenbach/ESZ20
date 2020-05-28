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

/* functions */
double n_4(int);
void * a3(void *data);

int main(int argc, char *argv[])
{    
    /* check user input */
    if (argc > 2){
        fprintf(stderr, "Too many Arguments!\nUsage: aufgabe4"
                "[RT priority (-19 to 19)]\nUser might add no or one optional argument.\n");
        exit(EXIT_FAILURE);
    }

    /* if we got a thread priority */
    if(argc == 2){
        int prio;
        int ret, rc;
        pthread_t tid;
        pid_t pid = getpid();
        struct sched_param param;
        pthread_attr_t tattr;

        /* initialized with default attributes */
        pthread_attr_init (&tattr);
        
        /* choose real time policy FIFO */
        pthread_attr_setschedpolicy(&tattr, SCHED_FIFO);

        /* get prio from command line and convert to int */
        prio = atoi(argv[1]);
        printf("debug prio: %d\n", prio);
        if((prio >= (-20)) && (prio <= 19)){        // accoridng to sched(7)
            param.sched_priority = prio;
        } else {
            printf("Ignoring invalid priority.\n");
        }
        /* setting the new scheduling param */
        ret = pthread_attr_setschedparam(&tattr, &param);
        if(ret != 0){
            fprintf(stderr, "Couldnt set priority: %d\n", ret);
            exit(EXIT_FAILURE);
        }
        printf("Priority: %d\n", param.sched_priority);
        
        rc = pthread_create(&tid, NULL, a3, NULL);
        if(rc)			/* could not create thread */
        {
            printf("\n ERROR: return code from pthread_create is %d \n", rc);
            exit(1);
        }
        /* wait for thread tid     */
        pthread_join(tid, NULL);
    } else {
        void *tmp;
        a3(tmp);
    }
        
    return 0;
}

/* code form aufgabe 3 */
void * a3(void *data){

    const int FAK = 26; // Faktor, der n erhöht für die n^4 Berechnung (24 bei Urs)
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
