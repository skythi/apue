#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<pthread.h>

void *thr_fn1(void *arg) {
	printf("thread1 returning\n");
	return((void *)1);
}

void *thr_fn2(void *arg) {
	printf("thread2 returning\n");
	return((void *)2);
}

int main() {
	int err;
	pthread_t tid1, tid2;
	void *tret;

	err = pthread_create(&tid1, NULL, thr_fn1, NULL);
	if (err != 0) 
		printf("can't create thread1");
	err = pthread_create(&tid1, NULL, thr_fn2, NULL);
	if (err != 0)
		printf("can't create thread2");
	err = pthread_join(tid1, &tret);
	if (err != 0)
		printf("can't join with thread1");
	printf("thread 1 exit code %ld\n", (long)tret);
	err = pthread_join(tid2, &tret);
	if(err != 0)
		printf("can't join with thread2");
	printf("thread 2 exit code %ld\n", (long)tret);
	exit(0);
}
