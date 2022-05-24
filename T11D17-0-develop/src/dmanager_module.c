#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID 100000

void initialize_doors(struct door* doors);
void swap(int* xp, int* yp);
void buble_sort(int arr[], int n);
void print_array(struct door* doors);

int main() {
  struct door doors[DOORS_COUNT];

  initialize_doors(doors);
  for (int i = 0; i < DOORS_COUNT; i++) {
    doors[i].status = 0;
  }
  print_array(doors);
  return 0;
}

void initialize_doors(struct door* doors) {
  srand(time(0));
  int seed = rand() % MAX_ID;
  for (int i = 0; i < DOORS_COUNT; i++) {
    doors[i].id = (i + seed) % MAX_ID;
    doors[i].status = rand() % 2;
  }
}

void swap(int* xp, int* yp) {
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void bubbleSort(struct door* doors) {
  for (int i = 0; i < DOORS_COUNT - 1; i++)
    for (int j = 0; j < DOORS_COUNT - i - 1; j++)
      if (doors[j].id > doors[j + 1].id) swap(&doors[j].id, &doors[j + 1].id);
}

void print_array(struct door* doors) {
  for (int i = 0; i < DOORS_COUNT; ++i) {
    if (i != DOORS_COUNT - 1)
      printf("%d, %d\n", doors[i].id, doors[i].status);
    else
      printf("%d, %d", doors[i].id, doors[i].status);
  }
}
