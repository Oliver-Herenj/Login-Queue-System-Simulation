#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include "login_queue.h"

#define MAX_CONCURRENT_LOGINS 3  // Maximum number of concurrent logins allowed

sem_t login_semaphore;  // Semaphore to control concurrent logins

void initialize_login_queue() {
    // Initialize the semaphore with the max concurrent logins allowed
    sem_init(&login_semaphore, 0, MAX_CONCURRENT_LOGINS);
}

void* user_login(void* user_id) {
    int id = *(int*)user_id;

    printf("User %d is trying to log in...\n", id);

    // Wait for an available slot in the semaphore (simulating login queue)
    sem_wait(&login_semaphore);

    // Critical section: simulate login process
    printf("User %d is logging in...\n", id);
    sleep(2);  // Simulate login time

    printf("User %d has logged in.\n", id);

    // Release the semaphore slot (user has finished login)
    sem_post(&login_semaphore);

    return NULL;
}

void destroy_login_queue() {
    // Clean up the semaphore
    sem_destroy(&login_semaphore);
}
