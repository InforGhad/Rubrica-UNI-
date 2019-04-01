#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"

int inserimento(rubrica R, int n) {
	printf("\n");
	printf("Inserisci Cognome, Nome, Numero di telefono: ");
	scanf("%s %s %s", R[n].cognome, R[n].nome, R[n].tel);
	printf("\n");
	n++;
	qsort(R, n, sizeof(elemento), compare);
	return n;
}


void stampa(rubrica R, int dim) {
	int i;
	for (i = 0; i < dim; i++) {
		printf("Cognome:%s, Nome:%s, Telefono:%s\n", R[i].cognome, R[i].nome, R[i].tel);
	}
}

int compare(const void *e1, const void *e2) {
	int cmp;
	elemento v1, v2;

	v1 = *(elemento*)e1;
	v2 = *(elemento*)e2;
	// Con strcmp si esegue un confronto case SENSITIVE (A < a, Z<a)
	if ((cmp = strcmp(v1.cognome, v2.cognome)) != 0)
		return cmp;
	else
		return strcmp(v1.nome, v2.nome);

	return 0;
}

void ricerca(rubrica R, int n, elemento e){
	printf("Ricerca di: %s %s\n", e.cognome, e.nome);






}
