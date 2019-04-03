#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"
int main() {
	int noe=8;//NumberOfElement
	rubrica R = {
		"Grissom","Cyrus","555 01071967",
		"Krueger","Frederick","555 14051945",
		"Lecter","Hannibal","555 02081950",
		"Malfoi","Draco","555 23111980",
		"Malfoi","Lucius","555 12051965",
		"Price","Elijah","555 30091970",
		"Voorhees","Jason","555 13061946",
		"Voorhees","Pamela","555 22081930"
	};
	int caso;
	boolean scelta=FALSE;
	do {
		printf("1)Inserimento\n2)Stampa\n3)Ricerca\n4)Uscita.");
		printf("\nScelta: ");
		scanf("%d", &caso);
		switch (caso)
		{
		case 1: {
			int k;
			noe = inserimento(R, noe);
			printf("\nSono stati inseriti: %d Elementi\n", noe);
			break;
		}
		case 2: {
			stampa(R, noe);
			break;
		}
		case 3: {
			elemento e;
			printf("Inserisci elemento da cercare:");
			scanf("%s %s", e.cognome, e.nome);
			ricerca(R, noe, e);

			break;
		}

		default: scelta = TRUE;
			break;
		}
	} while (!scelta);
}
