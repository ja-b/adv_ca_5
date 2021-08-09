#include<stdio.h>
#include<stdlib.h>

#ifdef OMP
#include<omp.h>
#endif

#ifdef PAPI
#include<papi.h>
#endif

int main(int argc, char **argv)
{
  int x=0;
  int i=0;
  int N = atoi(argv[1]);
  double ts, tf;
  char* event_name;

  long_long *values;
  int Events[] = {PAPI_BR_MSP, PAPI_BR_INS, PAPI_RES_STL};
  int num_events = sizeof(Events) / sizeof(int);
  PAPI_start_counters(Events, num_events);
  event_name = (char*)malloc(128);

  values = (long_long*)malloc(num_events*sizeof(long_long));

  for (i=0;i<N;++i){
    if (i < N/2) {
      x += 1;
    } else {
      x -= 1;
    }
  }
  PAPI_stop_counters(values, num_events);

  for(i=0; i < num_events; i++) {
    PAPI_event_code_to_name(Events[i], event_name);
    printf("%s:%lld\n", event_name, values[i]);
  }

 printf("array sum:%i\n", x);

}



