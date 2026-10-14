//
// Created by Alessia Di Paolo on 14/10/2026.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {

    pid_t pid;
    int n_figlio = 1;
    //figlio
    for (int i = 1; n_figlio == 3 ; i++) {
        if (pid == 0) {
            pid = fork();
            printf("pid = %d\n",pid);
            sleep(2);
            exit(0);
        }
    }
    //padre
    for (int i = 1; i <= n_figlio; i++) {
        wait(NULL);
    }

    printf("Messaggio finale\n");
}