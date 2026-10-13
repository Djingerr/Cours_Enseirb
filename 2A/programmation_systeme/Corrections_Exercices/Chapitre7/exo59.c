#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdint.h>
#include <inttypes.h>
#include <semaphore.h>
#include <sys/time.h>
#include <string.h>
#include <assert.h>

#define N 1000000

typedef struct th_arg{
  int64_t *base_ptr;
  int64_t num_elems;
} th_arg_t;


void *sort(void *arg)
{
  int64_t *ptr = ((th_arg_t *)arg)->base_ptr;
  int64_t nelems = ((th_arg_t *)arg)->num_elems;
  int64_t min = *ptr;
  struct timeval t1,t2;
  double time = 0.0;
 
  gettimeofday(&t1,NULL);
  for(int64_t i = 1 ; i < nelems ; i++)
    if( ptr[i] < min)
      min = ptr[i];
  gettimeofday(&t2,NULL);

  time = (t2.tv_sec - t1.tv_sec) + (t2.tv_usec - t1.tv_usec)/1000000.0;
  fprintf(stdout,"Time spent in subsort: %f sec \n",time);
  
  pthread_exit((void *)min);
}

int main(int argc, char *argv[])
{
  int64_t   *garray = NULL;
  int64_t   *marray = NULL;
  pthread_t *tid = NULL;
  th_arg_t  *args = NULL;
  int num_threads = 10;
  int64_t  min;
  struct timeval t1,t2;
  float time = 0.0;
  int seed = 666;
  memset(&t1,0,sizeof(struct timeval));
  memset(&t2,0,sizeof(struct timeval));
  
  if(3 == argc) {
    num_threads = atoi(argv[1]);
    seed = atoi(argv[2]);
  }
    
  fprintf(stdout,"creating %i threads\n",num_threads);
  srand(seed);  
  
  tid =  (pthread_t *)malloc(num_threads * sizeof(pthread_t));
  args =  (th_arg_t *)malloc(num_threads * sizeof(th_arg_t));
  marray = (int64_t *)malloc(num_threads * sizeof(int64_t));
  garray = (int64_t *)malloc(N * sizeof(int64_t));

  for(int64_t i = 0 ; i < N ; i++)
    garray[i] = rand();

  gettimeofday(&t1,NULL);
  for(int i = 0 ; i < num_threads ; i++){
    args[i].base_ptr  = garray + i*(N/num_threads);
    args[i].num_elems = N/num_threads;
  }
  args[num_threads-1].num_elems += N%num_threads;
  
  for(int i = 0 ; i < num_threads ; i++)
    pthread_create(&tid[i],NULL,sort,(void *)&(args[i]));
  
  for(int i = 0 ; i < num_threads ; i++)
    pthread_join(tid[i],(void *)&marray[i]);

  gettimeofday(&t2,NULL);
  
  min = marray[0];
  for(int i = 1 ; i < num_threads ; i++)
    if(marray[i] < min)
      min = marray[i];    

  time  = (t2.tv_sec - t1.tv_sec) + (t2.tv_usec - t1.tv_usec)/1000000.0;
  fprintf(stdout,"Time spent: %f sec\n",time);
  
  free(tid);
  free(args);
  free(marray);
  free(garray);
  
  fprintf(stdout,"End of main: Min  is %" PRId64 "\n",min);

  return 0;  
}
