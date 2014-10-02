#include "mbed.h"
#include "test_env.h"
#include "rtos.h"

#define THREAD_DELAY     75
#define SEMAPHORE_SLOTS  2
#define SEM_CHANGES      100

void print_char(char c = '*')
{
    printf("%c", c);
    fflush(stdout);
}

Semaphore two_slots(SEMAPHORE_SLOTS);

volatile int change_counter = 0;
volatile int sem_counter = 0;
volatile bool sem_defect = false;

void test_thread(void const *delay) {
    const int thread_delay = int(delay);
    while (true) {
        two_slots.wait();
        sem_counter++;
        const bool sem_lock_failed = sem_counter > SEMAPHORE_SLOTS;
        const char msg = sem_lock_failed ? 'e' : sem_counter + '0';
        print_char(msg);
        if (sem_lock_failed) {
            sem_defect = true;
        }
        Thread::wait(thread_delay);
        print_char('.');
        sem_counter--;
        change_counter++;
        two_slots.release();
    }
}

int main (void) {
    const int t1_delay = THREAD_DELAY * 1;
    const int t2_delay = THREAD_DELAY * 2;
    const int t3_delay = THREAD_DELAY * 3;
    Thread t1(test_thread, (void *)t1_delay);
    Thread t2(test_thread, (void *)t2_delay);
    Thread t3(test_thread, (void *)t3_delay);

    while (true) {
        if (change_counter >= SEM_CHANGES or sem_defect == true) {
            t1.terminate();
            t2.terminate();
            t3.terminate();
            break;
        }
    }

    fflush(stdout);
    notify_completion(!sem_defect);
    return 0;
}
