#ifndef TOOLS_H
#define TOOLS_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

int min(int a, int b);
int max(int a, int b);
int abs(int a);
void swap(int *x, int *y);
int is_sorted(int *arr, int size);
void shuffle(int *arr, int size);
int length(int *arr);
void bubble_sort(int arr[], int size);
void timed_bubble_sort(int arr[], int size);
void coktail_shaker(int arr[], int size);
void timed_coktail_shaker(int arr[], int size);
void bogo_sort(int arr[], int size);
void timed_bogo_sort(int arr[], int size);

void array_pprint(int* list, int TAILLE);


#endif