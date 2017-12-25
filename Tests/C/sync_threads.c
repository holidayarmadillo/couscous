/*
 * Objectives
 * 1. Create two threads; one printing even numbers and other, the odd numbers
 * 2. Make sure the sync is proper
 */

#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond1;

int counter = 0;

void *sync_even_numbers()
{
	for (;;) {
		pthread_mutex_lock(&mutex);

		if (counter%2)
		{
			printf("Odd in even numbered function\n");
			pthread_cond_wait(&cond1, &mutex);
		}

		printf("%d\n", counter);
		counter++;

		pthread_cond_signal(&cond1);

		if (counter >= 10)
		{
			pthread_mutex_unlock(&mutex);
			return (void *)NULL;
		}

		pthread_mutex_unlock(&mutex);
	}
}

void *sync_odd_numbers()
{
	for (;;) {
		pthread_mutex_lock(&mutex);

		if (!(counter%2))
		{
			printf("Even in odd numbered function\n");
			pthread_cond_wait(&cond1, &mutex);
		}

		printf("%d\n", counter);
		counter++;

		pthread_cond_signal(&cond1);

		if (counter == 10)
		{
			pthread_mutex_unlock(&mutex);
			return (void *)NULL;
		}

		pthread_mutex_unlock(&mutex);
	}
}

int main(void)
{
	pthread_t thread1, thread2;

	if (pthread_cond_init(&cond1, NULL))
		return -1;

	pthread_create(&thread1, NULL, sync_even_numbers, NULL);
	pthread_create(&thread2, NULL, sync_odd_numbers, NULL);

	pthread_join(thread2, NULL);
	pthread_join(thread1, NULL);

	if (pthread_cond_destroy(&cond1))
		return -1;

	return 0;
}
