#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>

void wait_or_die() {
    int rc = wait(NULL);
    assert(rc > 0);
}

int fork_or_die() {
    int rc = fork();
    assert(rc >= 0);
    return rc;
}

int main(int argc, char *argv[]) {
    // process a
    if (fork_or_die() == 0) {
        sleep(1);
        // process b
        if (fork_or_die() == 0) {
            sleep(1);
            // process c
            if (fork_or_die() == 0) {
                sleep(8);
                // process d
                if (fork_or_die() == 0) {
                    sleep(5);
                    // process e
                    exit(0);
                }
                if (fork_or_die() == 0) {
                    sleep(10);
                    // process f
                    exit(0);
                }
                wait_or_die();
                wait_or_die();
                exit(0);
            }
            if (fork_or_die() == 0) {
                sleep(10);
                // process g
                exit(0);
            }
            wait_or_die();
            wait_or_die();
            exit(0);
        }
        wait_or_die();
        exit(0);
    }
    wait_or_die();
    if (fork_or_die() == 0) {
        sleep(9);
        // process h
        exit(0);
    }
    wait_or_die();
    return 0;
}

