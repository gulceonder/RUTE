#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

void *myfunc1(void *ptr);
void *myfunc2(void *ptr);
pthread_t thrd[2];
int a[20];

int main(int argc, char *argv[])
{int i=0;
	 pthread_t thrd1, thrd2;
	int thret1, thret2;
	char *msg1 ="First Tread: ";
	char *msg2 ="Second Tread: ";
	memset(a,0, sizeof(a) );
	
	thret1 = pthread_create(&thrd[0],NULL, myfunc1, (void*)msg1);
	thret2 = pthread_create(&thrd[1],NULL, myfunc2, (void*)msg2);
	pthread_join(thrd[0],NULL);
	pthread_join(thrd[1],NULL);

	printf("thret1 = %d\n", thret1);
	printf("thret1= %d\n", thret2);

	return 0;
	}



void *myfunc1(void *ptr){
	 int i;
	char *msg= (char*)ptr;
	printf("msg: %s\n", msg);

	for(i=0; i <100; i++){

	printf("X");
sleep(0.5);
	a[i] =i;
	}

}

void *myfunc2(void *ptr){
	 int i;
	char *msg= (char*)ptr;
	printf("msg: %s\n", msg);

	for(i=0; i <100; i++){

	printf("%d, ",a[i]);
sleep(0.5);

	}

}
