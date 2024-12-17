#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char jmeno[20];
    int vek;
} Osoba;

int main () {
  Osoba *p_os;
  
  p_os = (Osoba *) malloc(sizeof(Osoba));

  if (p_os == NULL) {
    printf("Nedostatek pameti\n");
    return 1;
  }

  printf("Zadej jmeno: ");
  scanf("%s", p_os->jmeno);
  printf("Zadej vek: ");
  scanf("%d", &p_os->vek);

  printf("Jmeno: %s, Vek: %d\n", p_os->jmeno, p_os->vek);

  free(p_os);
  p_os = NULL;

}