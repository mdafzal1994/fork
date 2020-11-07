#include<stdio.h>
#include<pthread.h>
#include <unistd.h>

pthread_barrier_t  barrier;


void *serial(void *t)
{

   printf("inilzing serial \n");
  sleep(1);
  pthread_barrier_wait (&barrier);
printf(" serial started\n");

}

void *lcd(void *t)
{

   printf("inilzing lcd \n");
  sleep(3);
  pthread_barrier_wait (&barrier);
printf(" lcd started\n");

}
void *ethernet(void *t)
{

   printf("inilzing ethernet \n");
  sleep(7);
  pthread_barrier_wait (&barrier);
printf(" ethernet started\n");

}
void *adc(void *t)
{

   printf("inilzing adc\n");
  sleep(17);
  pthread_barrier_wait (&barrier);
printf(" adc started\n");

}



int main()
{

	pthread_t s,l,e,a;
 pthread_barrier_init(&barrier,NULL,4);

 pthread_create(&s,NULL,serial,NULL);

 pthread_create(&l,NULL,lcd,NULL);
 pthread_create(&e,NULL,ethernet,NULL);
 pthread_create(&a,NULL,adc,NULL);


 pthread_join(s, NULL);

 pthread_join(l, NULL);
 pthread_join(e, NULL);
 pthread_join(a, NULL);

 pthread_barrier_destroy (&barrier);
  

return 0;
}

