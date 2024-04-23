/**********************************************************/
/* Autor: Kasim Mermer                                    */
/* Datum: 12.11.2016									  */
/* Projekt: P7A1										  */
/* Beschreibung: Berechnung einer Extremwertaufgabe		  */
/**********************************************************/

#include <stdio.h>
#include <stdlib.h>		// f�r atoi- Funktion
#include <string.h>		// f�r strlen- Funktion
#include <ctype.h>		// f�r isDigit- Funktion
#include <math.h>		// f�r pow
#define laengeArray 50
#define pi_konstant 3.141592

// double ist r�ckgabewert, pruefen der name, char test[] ist der �bergabeparameter
double pruefen(char test[laengeArray]);	// Funktionsdeklaration

int main(void) {
	double schrittlaenge = 0.0;		// Initialisierungen
	double Vsand = 0.0, Vwasser = 0.0, indexDouble = 0.0, indexDouble2 = 0.0, zeit_sand = 0.0, zeit_wasser = 0.0, zeit_gesammt = 0.0, weg_gesammt = 0.0;
	double hypotenuse_sand = 0.0, hypotenuse_wasser = 0.0;	// F�r die Dreiecksformel // indexDpuble und indexDouble2 werden f�r die Seiten des 100m langen untere Linie �bernommen, weil ich nicht wusste wie 
															// ich sonst die Seite nennen sollte. Dachte erst an b wegen a^2 + b^2 = c^2 also Seite b aber habs dann gelassen und einfach index genannt
															// und double wegen der gr��e in Kommastelle
	double zeiten[laengeArray] = { 0 };
	double weg[laengeArray] = { 0 };
	double winkel[laengeArray] = { 0 };
	int ende = 0, beenden = 1, index = 0, index2 = 0;
	double  sand_entfernung = 50.0, wasser_entfernung = 50.0;
	char eingabe[laengeArray];		// Array Deklaration

	while (beenden != 0) {
		printf("Geben sie die Schrittlaenge in Metern ein:\t");
		fgets(eingabe, laengeArray, stdin);		// String eingeben
		fflush(stdin);	// Tastaturpuffer leeren
		schrittlaenge = pruefen(eingabe);	// Funktionsaufruf f�rs Fehlerabfangen
		if (schrittlaenge == true) {	// �berpr�fen ob eine 1 zur�ckgegeben wurde
			schrittlaenge = atof(eingabe);		// Den String Wert in einen Double Wert umwandeln
			if (schrittlaenge > 100.0 || schrittlaenge < 0.01) {	// �berpr�fen ob die Grenze �berschritten wurde
				Vsand = false;		// setzt einfach den Vsand wert auf 0 f�r false
			}
			else {		// wenn schrittlaenge die grenze nciht �berschritten hat dann f�hrt er folgende befehle aus
				printf("Geben sie die Geschwindigkeit auf dem Sand in Meter / Sekunde ein:\t");
				fgets(eingabe, laengeArray, stdin);		// String eingeben
				fflush(stdin);	// Tastaturpuffer leeren
				Vsand = pruefen(eingabe);	// Funktionsaufruf f�rs Fehlerabfangen
			}
		}
		if (Vsand == true) {
			Vsand = atof(eingabe);		// Den String Wert in einen Double Wert umwandeln
			printf("Geben sie die Geschwindigkeit auf dem Wasser in Meter / Sekunde ein:\t");
			fgets(eingabe, laengeArray, stdin);		// String eingeben
			fflush(stdin);	// Tastaturpuffer leeren
			Vwasser = pruefen(eingabe);	// Funktionsaufruf f�rs Fehlerabfangen
		}
		
		index = 0;				// setze alle Variablen sicherheitshalber auf 0. sonst funktioniert evtl mein Programm nciht richtig
		index2 = 0;
		indexDouble = 0.0;
		indexDouble2 = 0.0;
		ende = 0;
		printf("\n");		// Zeilensprung
		if (Vwasser == true) {
			Vwasser = atof(eingabe);		// Den String Wert in einen Double Wert umwandeln
			for (indexDouble = 0.0; indexDouble2 != 1000.0; index++) {
				if (indexDouble >= 100.0) {		// wenn die Seite wo die 100m steht gr��er als 100 ist dann soll er nur f�r die 100m rechnen und darum der Befehl hier
					indexDouble = 100.0;		// setzt einfach die Seite auf 0. Also die mittlere Seite von der Raute
					ende = 1;		// ist damit das Programm anschlie�end beenden nachdem es die unten stehenden Befehle ausf�hrt.
				}
				hypotenuse_sand = pow(sand_entfernung, 2) + pow(indexDouble, 2);
				hypotenuse_sand = sqrt(hypotenuse_sand);		
				winkel[index] = acos(sand_entfernung / hypotenuse_sand);		// Winkelberechnung
				winkel[index] = (winkel[index] * 180.0) / pi_konstant;			// Damit der Richtige Wert raus kommt.
				// winkel[index] = acos(winkel[index]);
				// berechnung der hypotenuse also weg auf dem Sand
				// printf("hypotenuse von Sand: %lf\n", hypotenuse_sand);
				zeit_sand = hypotenuse_sand / Vsand;							// berechnung der zeit auf dem sand bis zum wasser
				// printf("zeit von Sand: %lf sekunden\n\n", zeit_sand);

				indexDouble2 = 100.0 - indexDouble;		// wird f�r die Wasser Seite verwendet f�r die Seite 'c' also wo die 100m sind.
				hypotenuse_wasser = pow(wasser_entfernung, 2) + pow(indexDouble2, 2);
				hypotenuse_wasser = sqrt(hypotenuse_wasser);						// berechnung der hypotenuse also weg auf dem wasser
				// printf("hypotenuse von Wasser: %lf\n", hypotenuse_wasser);
				zeit_wasser = hypotenuse_wasser / Vwasser;						// berechnung der zeit auf dem wasser bis zum mensch
				// printf("zeit von Wasser: %lf sekunden\n\n", zeit_wasser);

				weg_gesammt = hypotenuse_sand + hypotenuse_wasser;
				weg[index] = weg_gesammt;
				zeit_gesammt = zeit_sand + zeit_wasser;					// berechnung zeit gesammt um es in array zu speichern f�r sp�ter k�rzeste zeit zu berechnen
				zeiten[index] = zeit_gesammt;							// speichert in array rein
				printf("Zeit: \t%lf Sekunden auf einer Strecke von %lf Metern\n", zeit_gesammt, weg_gesammt);
				indexDouble = indexDouble + schrittlaenge;		// wird als die Seite 'c' benutzt also da wo die 100m weite ist.
				if (ende == 1) {		// Wenn ich das nciht so mache f�hrt er die letzte Schrittweite (100m erreicht) nicht aus weil es die Vor- Schleife fr�hzeitig verl�sst.
					indexDouble2 = 1000.0;	// Nun verl�sst er die for- Schleife.
				}
			}
			// gleichzeitig hat die variable index aufgez�hlt, wie oft ein wert in dem array gespeichert worden ist. das kann cih direkt unten mit ber�cksichtigen
			for (index2 = 0; index2 < index; index2++) {	// der wert index wird von oben �bernommen, weil es mir die anzahl zum rechnen erspart, wieviele werte in dem array gespeichert worden zu ermitteln
				if (zeiten[0] >= zeiten[index2]) {		// �berpr�ft ob zeiten [0] gr��er als die i.te stelle des arrays ist.
					zeiten[0] = zeiten[index2];			// setze array[0] mit der n�chsten stelle des arrays gleich um weiter zu pr�fen ob gr��er / kleiner
					weg[0] = weg[index2];				// um die Strecke f�r die Zeit zu ermitteln
					winkel[0] = winkel[index2];
					if (index2 != 0) {
						zeiten[index2] = 0.0;		// setze alle werte bis auf die array[0] auf 0
						weg[index2] = 0.0;
						winkel[index2] = 0.0;
					}
				}
			}
			printf("\n\n\nDie Strecke ist %lf meter lang \nund man braucht dafuer %lf Sekunden.\nWinkel wo man anfaengt zu laufen: %.2f\n\n\n", weg[0], zeiten[0], winkel[0]);
			winkel[0] = 0.0;
			weg[0] = 0.0;			// um den Weg zu ermittlen
			zeiten[0] = 0.0;		// ich setze die Stelle erst hier auf 0 weil ich oben diese Stelle des Arrays als zwischenspeicher nutze und der dort nciht auf 0 gesestzt werden darf
		}
	}
	getchar();
	return 0;
}


double pruefen (char eingabe[]) {	// Funktion
	int i = 0, laenge = 0, fehler = 0, punkt = 0, wert2 = 0;
	double wert = 0.0;
	laenge = strlen(eingabe);		// laenge von der Anzahl des Strings ausrechnen bzw herausfinden
	if (eingabe[0] == '+') {
		laenge = laenge - 2;		// laenge um 2 Stellen k�rzen wegen dem + am Anfang und \0 ganz zum Schluss
		for (i = 0; i < laenge; i++) {	// Damit man das + weg bekommt
			eingabe[i] = eingabe[i + 1];	// ersetzt die "i.te" stelle mit der "i+1.te stelle
			eingabe[i + 1] = 0;		// setzt die i+1 stelle auf 0
		}
	}
	else {
		laenge--;		// laenge um 1 Stelle k�rzen wegen \0 ganz zum Schluss
	}

	for (i = 0; i < laenge; i++) {
		if (isdigit(eingabe[i]) == 0) {		// kontrolliert ob die "i.te" Stelle von dem String die Werte von 0-9 besitzt,
											// indem es eine "0" also "false" oder eine "1" also "true" als r�ckgabeparameter zur�ck gibt.
			fehler++;			// wenn der rueckgabeparameter von der Funktion isDigit eine 1 ist, setzt er die Variable fehler auf 1.
			if (eingabe[i] == '.') {	// �berpr�ft ob ein '.' also eine Komma vorhanden ist. Bzw mehrere Kommas vorhanden sind
				fehler--;
				punkt++;	// F�r die Fehlerabfange falls mehrere Komams vorhanden sind
			}
		}
	}
	if (eingabe[0] == '.' || eingabe[laenge-1] == '.') {		// �berpr�ft ob die erste oder die letzte Stelle des Arrays ein '.' ist, wenn ja gibt er eine Fehlermeldung aus.
		fehler++;
	}	
	if (fehler == 0 && punkt == 0) {		// Falls der User einen Integer Wert eingegeben hat
		wert2 = atoi(eingabe);		// in Integer umwandeln und auf die Variable wert2 gleichsetzen
		wert = (double) wert2;		// wert2 als double in wert einschreiben
		// printf("eingabe:\t%lf\n\n", wert);	// Verwendungszweck: Kontrolle
		return 1.0;		// die Zahl zur�ckgeben
	}

	else if (fehler == 0 && punkt == 1) {		// wenn fehler = 0 ist und punkt = 0 ist f�hrt er das aus
		wert = atof(eingabe);		// Den String Wert in einen Double Wert umwandeln
		// printf("eingabe:\t%lf\n\n", wert);	// Verwendungszweck: Kontrolle
		return 1.0;	// die Zahl zur�ckgeben
	}
	else {		// wenn fehler auf 1 gesetzt wurde dann f�hrt er das aus
		printf("Sie haben einen Ungueltigen Wert eingegeben.\n\n");
		fehler = 0;		// setzt den fehler Wert wieder auf 0
	}
	return 0.0;	// Gibt eine 0 als 'False' zur�ck
} 

// String zu Double: https://www.proggen.org/doku.php?id=c:lib:stdlib:start von hier hab ich diesen Befehl her