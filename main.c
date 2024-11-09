#include <pthread.h>
#include "login_queue.h"

#define NUM_USERS 10  // Total number of users trying to log in

int main() {
    pthread_t users[NUM_USERS];
    int user_ids[NUM_USERS];

    // Initialize the login queue system
    initialize_login_queue();

    // Create threads for each user trying to log in
    for (int i = 0; i < NUM_USERS; i++) {
        user_ids[i] = i + 1;
        pthread_create(&users[i], NULL, user_login, &user_ids[i]);
    }

    // Wait for all users to finish their login attempts
    for (int i = 0; i < NUM_USERS; i++) {
        pthread_join(users[i], NULL);
    }

    // Clean up the login queue system
    destroy_login_queue();

    printf("All users have completed their login attempts.\n");

    return 0;
}
