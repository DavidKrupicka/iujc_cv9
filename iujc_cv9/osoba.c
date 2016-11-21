
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "osoba.h"


static tOsoba *prvni = NULL; static tOsoba *akt = NULL;
static char *GenerujJmeno();
static int GenerujVek();

static char *GenerujJmeno(){
	char iStr[3], *genStr = calloc(10, sizeof(char));
	strcpy(genStr, "jmeno");
	static int i;
	i++;
	itoa(i, iStr, 10);//integer to ascii
	strcat(genStr, iStr);
	return genStr;
}
static int GenerujVek(){
	return rand() % 100;
}
tOsoba *AlokujOsobu(char * jm, int vek){
	tOsoba *os = malloc(sizeof(tOsoba));
	strcpy(os->jmeno, jm);
	os->vek = vek;
	os->dalsi = NULL;
	return os;
}
tOsoba *GenerujOsobu(){
	return AlokujOsobu(GenerujJmeno(), GenerujVek());
}
void VlozNaPosledni(tOsoba *os){
	if (prvni == NULL){
		prvni = os;
	}
	else
		akt->dalsi = os;
	akt = os;
}
void Vypis(){
	tOsoba *os = prvni;
	while (os != NULL){
		printf("\n ---- jmeno: %s vek: %d ----\n", os->jmeno, os->vek);
		os = os->dalsi;
	}
}