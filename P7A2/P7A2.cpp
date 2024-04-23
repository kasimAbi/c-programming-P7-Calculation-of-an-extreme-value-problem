/**********************************************************/
/* Autor: Kasim Mermer                                    */
/* Datum: 11.11.2016									  */
/* Projekt: P7A2										  */
/* Beschreibung: Berechnung von Betrag					  */
/**********************************************************/

#include <stdio.h>		// Bibliotheken einbinden
#include <math.h>

int main(void) {
	int betrag = 0;		// Initialisierung
	double betrag2 = 0.0;

	// Wenn man den Betrag durch irgendeine der Zahlen 2-10 teilt, bleibt stets ein Rest, der um 1 kleiner ist, als der benutzte Teiler
	while ((betrag % 10 != 9) || (betrag % 9 != 8) || (betrag % 8 != 7) || (betrag % 7 != 6) || (betrag % 6 != 5) || (betrag % 5 != 4) || (betrag % 4 != 3) || (betrag % 3 != 2) || (betrag % 2 != 1)) {
		betrag++;	// inkrementiert die Variable Betrag
	}
	printf("Der Preis (in CENT):  %i CENT\n ", betrag);	// Textausgabe
	betrag2 = (double)betrag / 100;
	printf("Der Preis (in EURO): %.2f EURO", betrag2);
	getchar();
	return(1);	// Rückgabewert
}