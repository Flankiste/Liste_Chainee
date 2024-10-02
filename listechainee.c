#include <stdio.h>
#include <stdlib.h>

typedef struct element {
  int nombre;
  struct element *suivant;
} element;

void print_chain(element *premier) {

  element *current = premier;

  while (current != NULL) {
    printf("%d\n", current->nombre);
    current = current->suivant;
  }
}

void count_chain(element *premier) {
  element *current = premier;
  int count = 0;
  while (current != NULL) {
    count++;
    current = current->suivant;
  }
  printf("Il y a %d éléments dans la liste\n", count);
}

void somme(element *premier) {
  element *current = premier;
  int somme = 0;
  while (current != NULL){
    somme += current->nombre;
    current = current->suivant;
  }
  printf("La somme des éléments est %d\n", somme);
}

void minimum(element *premier) {
  element *current = INT_MAX;
  int minimum = premier->nombre;
  while (current != NULL){
    if (current -> nombre < minimum){
      minimum = current->nombre;
    }
    current = current->suivant;
  }
  printf("Le plus petit élément de la liste est %d\n", minimum);
}

element *insert_element(element *p, int nvNombre) {
  /* Création du nouvel élément */
  element *nvElement = malloc(sizeof(element));
  nvElement -> nombre = nvNombre;

  nvElement -> suivant = p -> suivant;
  p -> suivant = nvElement;
  return nvElement;
}  


int main() {
  //Allocation de l'espace pour les éléments de la liste
  element *premier = (element *)malloc(sizeof(element));
  element *a = (element *)malloc(sizeof(element));
  element *b = (element *)malloc(sizeof(element));
  element *c = (element *)malloc(sizeof(element));

  premier->nombre = 12;
  premier->suivant = a;

  a->nombre = 7;
  a->suivant = b;

  b->nombre = 3;
  b->suivant = c;

  c->nombre = 9;
  c->suivant = NULL;
  
  insert_element(b, 4);
  print_chain(premier);
  count_chain(premier);
  somme(premier);
  minimum(premier);
}