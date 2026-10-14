//
// Created by Alessia Di Paolo on 14/10/2026.
//

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main() {

    pid_t pid = fork();
    //figlio
    if ( pid == 0) {
        printf("I numeri del figlio sono i seguenti\n:");
        for (int i = 1; i <= 5; i++) {
            //velocizzare la stampa
            fflush(stdout);
            printf("- %d ",i);
            sleep(1);
        }
    }
    //padre
    else if (pid > 0) {
        wait(NULL);
        printf("I numeri del padre sono i seguenti\n:");
        for (int i = 6; i <= 10; i++) {
            //velocizzare la stampa
            fflush(stdout);
            printf("- %d ",i);
        }
    return 0;
    }
}