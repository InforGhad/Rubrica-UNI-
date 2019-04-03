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
		printf("Cognome:%s, Nome%s, Telefono:%s\n", R[i].cognome, R[i].nome, R[i].tel);
	}
}

int compare(const void *e1, const void *e2) {
	int cmp;
	elemento v1, v2;

	v1 = *(elemento*)e1;
	v2 = *(elemento*)e2;

	if ((cmp = strcmp(v1.cognome, v2.cognome)) != 0)
		return cmp;
	else
		return strcmp(v1.nome, v2.nome);
}

void ricerca(rubrica R, int n, elemento e) {
	int pos;
	printf("Stai cercando %s %s.\n", e.cognome, e.nome);
	pos=ricercabin(R, n, e);
	if (pos >= 0) {
		printf("Il numero di %s %s e': %s\n", R[pos].cognome, R[pos].nome, R[pos].tel);
	}
	else {
		printf("\nElemento non trovato!\n");

	}

}

int ricercabin(rubrica R, int n, elemento e) {
	int inizio=0, fine, med;
	boolean find=FALSE;
	fine = n / 2;
	do {
		if (strcmp(e.cognome, R[fine].cognome)==0 && strcmp(e.nome, R[fine].nome)==0) return fine;
		else if (fine == inizio) {
			//printf("\n**\n%d\n**\n", inizio);
			//printf("\nelse**\n");
			find = TRUE;
		}
		else if (strcmp(e.cognome, R[fine].cognome)< 0) {
			//printf("\n**Primo else if**\n");
			inizio = 0;
			fine = fine / 2;
		}

		else if (strcmp(e.cognome, R[fine].cognome) > 0) {

			//printf("\n**Secondo else if**\n");
			inizio = fine;
			med = (n - fine) / 2;
			fine = fine + med;
		}
		else {
			//printf("\n**\ncognNome ugualee, nome diverso.\n**\n");
			if (strcmp(e.nome, R[fine].nome)==0) {
				return fine;
			}
			else if (strcmp(e.nome, R[fine].nome)< 0) {
				//printf("\n**Primo else if Nome**\n");
				inizio = 0;
				fine = fine / 2;
			}

			else if (strcmp(e.nome, R[fine].nome) > 0) {

				//printf("\n**Secondo else if Nome**\n");
				inizio = fine;
				med = (n - fine) / 2;
				fine = fine + med;
			}

		}

	} while (!find);

	return -1;
}
