# Login Queue System Simulation

This project simulates a login queue system that handles concurrent login attempts and prevents server overload. A semaphore is used to limit the number of simultaneous logins.

## Files

- **main.c**: Entry point of the application.
- **login_queue.c**: Implements the login queue logic and controls access.
- **login_queue.h**: Header file for login queue functions.
- **Makefile**: Automates the build process.

## Build and Run

1. Compile the project:
   ```bash
   make

2. Run the executable:
   ```bash
   ./login_queue_system

3. Clean up the build:
   ```bash
   make clean


Features
Simulates a login queue system with concurrent users.
Limits concurrent logins using a semaphore for synchronization.
Logs user actions and prevents overload.
Dependencies
POSIX threads (pthread library)
Semaphore (semaphore.h)


