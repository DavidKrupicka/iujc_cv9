#include <stdlib.h>
#include <stdio.h>
#include "osoba.h"





int main(int argc, char *argv[]){
	int volba = 0, vek;
	tOsoba *os;
	char jm[10];

	do{
		printf("1-vloz z klavesnice \n");
		printf("2-vloz z generatoru\n");
		printf("3-vzpis\n");

		printf("0-konec\n");
		printf("vase vloba:");
		scanf("%d", &volba);

		switch (volba){
		case 1:
			printf("zadej jm:");
			scanf("%s", jm);
			printf("zadej vek:");
			scanf("%s", &vek);
			os = AlokujOsobu(jm, vek);
			VlozNaPosledni(os);
			break;
		case 2:
			os = GenerujOsobu();
			VlozNaPosledni(os);
			break;
		case 3:
			Vypis();
		}
	} while (volba != 0);
	
	return 0;
}
