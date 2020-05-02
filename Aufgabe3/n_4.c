#include <sys/time.h>
#include <stdio.h>


double n_4(int);

int main(){
  /*
  int gettimeofday(struct timeval *tv, struct timezone *tz);

  The functions gettimeofday() and settimeofday() can get and set the time as well as a timezone.  The tv argument is a struct timeval (as specified in <sys/time.h>):

    struct timeval {
        time_t      tv_sec;     / seconds /
        suseconds_t tv_usec;    / microseconds /
    };

and gives the number of seconds and microseconds since the Epoch (see time(2)).  The tz argument is a struct timezone:

    struct timezone {
        int tz_minuteswest;     / minutes west of Greenwich /
        int tz_dsttime;         / type of DST correction /
    };
*/
  const int FAK = 24; // Faktor, der n erhöht für die n^4 Berechnung
  double res = 0.0;
  struct timeval start,end;
  unsigned long seconds, microseconds;


  for(int i=0;i<10;i++){

    gettimeofday(&start,NULL);
    res = n_4(FAK*i);
    gettimeofday(&end,NULL);

    seconds = end.tv_sec - start.tv_sec;
    microseconds = seconds * 1000000 + end.tv_usec - start.tv_usec;

    printf("%f\t%lu.%lu s\n\r",res,seconds,microseconds);
  }
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
