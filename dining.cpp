#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

pthread_t *philosophers; // Array of threads representing philosophers
pthread_mutex_t *forks;  // Array of mutexes representing forks
int philosophers_count;  // Number of philosophers

void eat(int i)
{

    printf("Philosopher %d is eating\n", i + 1);

    sleep(1 + rand() % 10); // Random sleep time between 1 and 10 seconds
}

void *philosopher(void *args)
{
    int i = 0, first, second;

    // Get philosopher's ID
    while (!pthread_equal(*(philosophers + i), pthread_self()) && i < philosophers_count)
    {
        i++;
    }

    while (1)
    {

        printf("Philosopher %d is thinking\n", i + 1);

        sleep(1 + rand() % 10); // Random sleep time between 1 and 10 seconds

        // Acquire forks
        first = i;
        second = (i + 1) % philosophers_count;

        pthread_mutex_lock(forks + (first > second ? second : first));
        pthread_mutex_lock(forks + (first < second ? second : first));

        // Eat
        eat(i);

        // Release forks
        pthread_mutex_unlock(forks + first);
        pthread_mutex_unlock(forks + second);
    }

    return NULL;
}

int main(void)
{
    int i, err;

    srand(time(NULL)); // Seed random number generator with current time

    // Get number of philosophers
    printf("Enter number of philosophers:");
    scanf("%d", &philosophers_count);

    // Allocate memory for arrays
    philosophers = (pthread_t *)malloc(philosophers_count * sizeof(pthread_t));
    forks = (pthread_mutex_t *)malloc(philosophers_count * sizeof(pthread_mutex_t));

    // Initialize forks
    for (i = 0; i < philosophers_count; ++i)
        if (pthread_mutex_init(forks + i, NULL) != 0)
        {
            printf("Failed initializing fork %d\n", i + 1);
            return 1;
        }

    // Create philosopher threads
    for (i = 0; i < philosophers_count; ++i)
    {
        err = pthread_create(philosophers + i, NULL, &philosopher, NULL);

        if (err != 0)
        {
            printf("Error creating philosopher: %s\n", strerror(err));
        }
        else
        {
            printf("Successfully created philosopher %d\n", i + 1);
        }
    }

    // Wait for philosopher threads to finish
    for (i = 0; i < philosophers_count; ++i)
        pthread_join(*(philosophers + i), NULL);

    // Free allocated memory
    free(philosophers);
    free(forks);

    return 0;
}