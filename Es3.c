//
// Created by Alessia Di Paolo on 14/10/2026.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/_types/_pid_t.h>

int main() {
    pid_t pid1, pid2;

    //nonno -> padre
    pid1 = fork();
    if (pid1 > 0) {
        printf("pid del nonno = %d\n", pid1);
        wait(NULL);
    }
    else {
        //padre -> figlio
        pid2 = fork();
        if (pid2 > 0) {
            printf("pid del padre = %d\n", pid2);
            wait(NULL);

        }
        else {
            printf("Il figlio ha completato");
            sleep(1);
            exit(0);
        }
        exit(0);
    }
    return 0;
}