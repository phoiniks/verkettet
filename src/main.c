#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person
{
  char* vorname;
  char* nachname;
  struct person* naechste;
} person;

typedef struct name
{
  char* vorname;
  char* nachname;
} name;

void initialisieren(char* vorname, char* nachname, person* p);
void hinzufuegen(char* vorname, char* nachname, person* p);

int main(int argc, char** argv)
{
  person *p = NULL, *kopf = NULL;

  char* personen[][5] = {{"Nuria", "Acacio López"}, {"Laura", "Grell Acacio"},
			 {"Frans", "Hals"}, {"Carmen", "Acacio López"}, {"Lucy Maud", "Montgomery"}};

  p = malloc(sizeof(person));
  
  printf("\nGesamtlänge des Programmnamens: %ld\n", strlen(argv[0]));
  printf("\nProgrammname: %s\n", *argv);

  initialisieren("Andreas", "Grell", p);

  kopf = p;

  for(int i = 0; i < 5; i++)
    {
      hinzufuegen(personen[i][0], personen[i][1], p);
      p = p->naechste;
    }

  hinzufuegen("Honoré", "de Balzac", p);

   p = p->naechste;
  
  hinzufuegen("Jane", "Austen", p);

   p = p->naechste;
  
  hinzufuegen("Carmen", "Acacio López", p);

  /* p->naechste = NULL; */
    
  p = kopf;

  while(p)
    {
      kopf = p;
      printf("%s %s\n", p->vorname, p->nachname);
      p = p->naechste;
      free(kopf);
    }  
}


void initialisieren(char* vorname, char* nachname, person* p)
{
  p->vorname	= vorname;
  p->nachname	= nachname;
}

void hinzufuegen(char* vorname, char* nachname, person* p)
{
  p->naechste   = malloc(sizeof(person));
  p             = p->naechste;
  
  p->vorname  	= vorname;
  p->nachname	= nachname;
}
