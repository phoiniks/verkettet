#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>


typedef struct person
{
  char* vorname;
  char* nachname;
  char* lokalzeit;
  struct person* naechste;
} person;

typedef struct name
{
  char* vorname;
  char* nachname;
} name;

char* zeit(void);
void initialisieren(char* vorname, char* nachname, person* p);
void hinzufuegen(char* vorname, char* nachname, person* p);

int main(int argc, char** argv)
{
  setlocale(LC_ALL, "");

  person *p = NULL, *kopf = NULL;

  char* personen[][2] = {{"Nuria", "Acacio López"}, {"Laura", "Grell Acacio"}};

  p = malloc(sizeof(person));
  
  printf("\nGesamtlänge des Programmnamens: %ld\n", strlen(argv[0]));
  printf("\nProgrammname: %s\n", *argv);

  initialisieren("Andreas", "Grell", p);

  kopf = p;

  for(int i = 0; i < 2; i++)
    {
      hinzufuegen(personen[i][0], personen[i][1], p);
      p = p->naechste;
    }

  hinzufuegen("Honoré", "de Balzac", p);

  p = p->naechste;

  hinzufuegen("Jane", "Austen", p);
    
  p = kopf;

  for(int i = 0; i < 5; i++)
    {
      printf("%s %s, %s\n", p->vorname, p->nachname, p->lokalzeit);
      p = p->naechste;
    }  
}


char* zeit(void)
{
  time_t jetzt;
  struct tm* lokaljetzt;
  char* lokalzeit;
  
  time(&jetzt);
  lokaljetzt = localtime(&jetzt);
  
  lokalzeit = malloc(sizeof(char) * 64);
  strftime(lokalzeit, 64, "%A, %d. %B %Y, %H:%M Uhr und %S Sekunden", lokaljetzt);
  
  return lokalzeit;
}

void initialisieren(char* vorname, char* nachname, person* p)
{
  p->vorname	= vorname;
  p->nachname	= nachname;
  p->lokalzeit	= zeit();
}

void hinzufuegen(char* vorname, char* nachname, person* p)
{
  p->naechste			= malloc(sizeof(p));
  
  p->naechste->vorname  	= vorname;
  p->naechste->nachname		= nachname;
  p->naechste->lokalzeit        = zeit();
}
