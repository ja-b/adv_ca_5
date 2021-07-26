#include<stdio.h>
#include<stdlib.h>

#ifdef OMP
#include<omp.h>
#endif

#ifdef PAPI
#include<papi.h>
#endif

#define N 1000000000

int main(int argc, char **argv)
{
  long i;
  double a[N], sum=0.0;
  double ts, tf;
  char* event_name;

  
#ifdef OMP
  nt = atoi(argv[1]);
  omp_set_num_threads(nt);
#endif

  for (i=0;i<N;++i){
    a[i] = 1;
  }

#ifdef OMP
  ts = omp_get_wtime();
#endif

#ifdef PAPI
  long_long *values;
  int Events[] = {PAPI_TLB_DM};
  int num_events = sizeof(Events) / sizeof(int);
  PAPI_start_counters(Events, num_events);
  event_name = (char*)malloc(128);

  values = (long_long*)malloc(num_events*sizeof(long_long))
#endif
 
  for (i=0;i<N;++i){
    sum += a[i];
  }
#ifdef PAPI
  PAPI_stop_counters(values, num_events);
#endif
#ifdef OMP
  tf = omp_get_wtime();
#endif

#ifdef PAPI
  for(i=0; i < num_events; i++) {
    PAPI_event_code_to_name(Events[i], event_name);
    printf("%s:%lld\n", event_name, values[i]);
  }
#endif

 printf("array sum:%f\n", sum);

}



