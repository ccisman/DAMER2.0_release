extern void abort(void);
void reach_error(){}
void assume_abort_if_not(int cond) {
  if(!cond) {abort();}
}

#include <pthread.h>
#include <assert.h>
#define N 6

// verify t-6.c

int shared = 0;
int judge = 0;

void error(void)
{
  ERROR: {reach_error();abort();}
  return;
}

void *
thread(void *arg)
{
    shared = shared + 1;
}

void *
thread1(void *arg)
{
    if(shared > 3) error();
}

int main(void)
{
	pthread_t t[N],t1;
    for(int i=0;i<N;i++)
	    pthread_create(&t[i], 0, thread, 0);
    pthread_create(&t1, 0, thread1, 0);

    for(int i=0;i<N;i++)
	    pthread_join(t[i], 0);
    pthread_join(t1, 0);
    return 0;
}
