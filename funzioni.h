#define DIM 25


typedef enum{FALSE, TRUE}boolean;


typedef struct {
	char cognome[20];
	char nome[20];
	char tel[16];
} elemento;


typedef elemento rubrica[DIM];

int inserimento(rubrica R, int n);

int compare(const void *e1, const void *e2);

void stampa(rubrica R, int dim);

int ricercabin(rubrica R, int n, elemento e);

void ricerca(rubrica R, int n, elemento e);
