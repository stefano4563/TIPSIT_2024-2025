#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define PAGE_SIZE 20 // Numero di righe per pagina

// Funzione che simula il comando "more"
void show_more(int fd) {
    char buffer[1024];
    int line_count = 0;
    
    while (1) {
        ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);
        if (bytes_read <= 0) break; // Fine della lettura o errore
        
        buffer[bytes_read] = '\0'; // Assicurarsi che la stringa sia terminata

        // Mostra il contenuto a schermo, riga per riga
        for (ssize_t i = 0; i < bytes_read; i++) {
            putchar(buffer[i]);
            if (buffer[i] == '\n') {
                line_count++;
                if (line_count == PAGE_SIZE) {
                    printf("\nPress any key to continue...");
                    getchar();  // Aspetta l'input dell'utente per continuare
                    line_count = 0; // Reset del conteggio delle righe
                }
            }
        }
    }
}

// Funzione che simula il comando "cat"
void cat_file(const char *filename, int fd) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Errore nell'aprire il file");
        exit(1);
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file)) {
        write(fd, buffer, strlen(buffer)); // Scrive il contenuto nel pipe
    }

    fclose(file);
}

int main() {
    int pipefd[2];

    // Creazione della pipe
    if (pipe(pipefd) == -1) {
        perror("Errore nella creazione della pipe");
        exit(1);
    }

    int pid = fork();
    if (pid == -1) {
        perror("Errore nella creazione del processo");
        exit(1);
    }

    if (pid == 0) { // Processo figlio - Simula il comando "more"
        close(pipefd[1]); // Chiudi il lato di scrittura della pipe
        show_more(pipefd[0]);
        close(pipefd[0]);
    } else { // Processo padre - Simula il comando "cat"
        close(pipefd[0]); // Chiudi il lato di lettura della pipe
        cat_file("file.txt", pipefd[1]); // Aggiungi il nome del file che vuoi visualizzare
        close(pipefd[1]);
        wait(NULL); // Attende che il processo figlio finisca
    }

    return 0;
}
