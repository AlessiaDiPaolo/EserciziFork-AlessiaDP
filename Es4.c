//
// Created by Alessia Di Paolo on 14/10/2026.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    int n;
    int status;

    if (pid < 0) {
        perror("Errore nella fork");
        exit(1);
    }

    if (pid == 0) {
        printf("Inserisci un numero: ");
        scanf("%d", &n);

        if (n < 0) {
            printf("Errore\n");
            exit(0);
        }

        int i;
        for (i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                break;
            }
        }

        if (n > 1 && i * i > n) {
            exit(1);
        }
        else if (n % 2 == 0) {
            exit(2);
        }
        else {
            exit(3);
        }
    }
    //padre
    else if (pid > 0) {
        wait(&status); //wait, per aspettare la fine

        //legge codice letto e
        int codice = WEXITSTATUS(status);
        printf("Il figlio ha restituito il codice: %d\n", codice);
        printf("Il numero è: ");

        if (codice == 1) {
            printf("Primo\n");
        }
        else if (codice == 2) {
            printf("Pari\n");
        }
        else if (codice == 3) {
            printf("Dispari\n");
        }
    }
    return 0;
}