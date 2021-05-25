#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
void *myfunc1(void *ptr);
void *myfunc2(void *ptr);
pthread_t thrd[2];
pthread_mutex_t lock;
int a[20];

int main(int argc, char *argv[])
{	int i=0;
	 
	int thret1, thret2;
	char *msg1 ="First Tread: ";
	char *msg2 ="Second Tread: ";
	memset(a,0, sizeof(a) );
	
	if(i==0){thret1 = pthread_create(&thrd[0],NULL, myfunc1, (void*)msg1);
	i++;}
sleep(0.5);
	if(i==1){thret1 = pthread_create(&thrd[1],NULL, myfunc2, (void*)msg2);
	
	
	
	
	}
i=0;
	pthread_join(thrd[i],NULL);
	i++;
	pthread_join(thrd[i],NULL);

	//printf("thret1 = %d\n", thret1);
	

	return 0;
	}



void *myfunc1(void *ptr){
	 int i;
	char *msg= (char*)ptr;
pthread_mutex_lock(&lock);
	printf("msg: %s\n", msg);

	for(i=0; i <20; i++){

	printf("X");
	sleep(0.5);
	a[i] =i;
	}
pthread_mutex_unlock(&lock);
}

void *myfunc2(void *ptr){
	 int i;
	char *msg= (char*)ptr;
pthread_mutex_lock(&lock);
	printf("msg: %s\n", msg);

	for(i=0; i <20; i++){

	printf("%d, ",a[i]);
	sleep(0.5);

	}
pthread_mutex_unlock(&lock);

}
