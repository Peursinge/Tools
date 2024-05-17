#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>


////////////////////////////////  math tests  /////////////////////////////////

int min(int a, int b){
    if (a > b)
        return a;
    else
        return b;
}

int max(int a, int b){
    if (a > b)
        return b;
    else
        return a;
}

int abs(int a){
    if (a<0)
        a = -a;
    return a;
}

bool coinflip(){
    return rand()%2;
}

/////////////////////////////  sorting algorithms  ////////////////////////////

void swap(int *x, int *y){
    if (x==y)
        return;
    // XOR binaire, ça swap tkt
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
}

int is_sorted(int *arr, int size){
    int cpt = 0;
    while(cpt < size){
        if(arr[cpt] > arr[cpt+1])
            return false;
    }
    return true;
}

void shuffle(int *arr, int size){
    int i, j, tmp;
    for (i=0; i<size; i++){
        j = arr[i];
        tmp = rand() % size;
        arr[i] = arr[tmp];
        arr[tmp] = j;
    }
}

int length(int *arr){
    int n = sizeof(arr)/sizeof(arr[0]);
    return(n);
}


void bubble_sort(int arr[], int size)
{
    int i, j;
    bool swapped;
    for (i = 0; i < size - 1; i++) {
        swapped = false;
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

void timed_bubble_sort(int arr[], int size)
{
    clock_t begin = clock();
    int i, j;
    bool swapped;
    for (i = 0; i < size - 1; i++) {
        swapped = false;
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
    clock_t end = clock();
    double timer = (double)(end-begin)/CLOCKS_PER_SEC;
    printf("sorted in %f seconds with bubble_sort\n", timer);
}

void coktail_shaker(int arr[], int size){
    int i, j;
    bool swapped;
    for (i = 0; i < size - 1; i++) {
        swapped = false;
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }

    for (i = size-1; i > 0; i--) {
        swapped = false;
        for (j = size - i - 1; j > 0; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
    
}

void timed_coktail_shaker(int arr[], int size){
    clock_t begin = clock();
    int i, j;
    bool swapped;
    for (i = 0; i < size - 1; i++) {
        swapped = false;
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }

    for (i = size-1; i > 0; i--) {
        swapped = false;
        for (j = size - i - 1; j > 0; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
    clock_t end = clock();
    double timer = (double)(end-begin)/CLOCKS_PER_SEC;
    printf("sorted in %f seconds with cocktail shaker\n", timer);
}

int partition(int arr[], int low, int high) {
  
  // select the rightmost element as pivot
  int pivot = arr[high];
  
  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the arr
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (arr[j] <= pivot) {
        
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      
      // swap element at i with element at j
      swap(&arr[i], &arr[j]);
    }
  }

  // swap the pivot element with the greater element at i
  swap(&arr[i + 1], &arr[high]);
  
  // return the partition point
  return (i + 1);
}

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(arr, low, high);
    
    // recursive call on the left of pivot
    quickSort(arr, low, pi - 1);
    
    // recursive call on the right of pivot
    quickSort(arr, pi + 1, high);
  }
}

void timed_quickSort(int arr[], int low, int high) {
    clock_t begin = clock();
    if (low < high) {
    
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(arr, low, high);
    
    // recursive call on the left of pivot
    quickSort(arr, low, pi - 1);
    
    // recursive call on the right of pivot
    quickSort(arr, pi + 1, high);
  }
    clock_t end = clock();
    double timer = (double)(end-begin)/CLOCKS_PER_SEC;
    printf("sorted in %f seconds with quick_sort\n", timer);
}

void stalin_sort(int arr[], int size){
    for(size_t i = 0; i < size; i++){
            if(arr[i] >= arr[i+1]){
                arr[i+1] = 0;
                i++;
            }
        }
    bubble_sort(arr, size);
}

void bogo_sort(int arr[], int size){
    int i = 0;
    while (!is_sorted(arr, size))
    {
        shuffle(arr, size);
        i++;
        if(i%100 == 0){
            printf("%d", i);
        }
    }
    printf("%d", i);
}

void timed_bogo_sort(int arr[], int size){
    clock_t begin = clock();
    printf("%d\n", is_sorted(arr, size));
    while (!is_sorted(arr, size))
    {
        shuffle(arr, size);
        printf("bogosorting...\n");
        
    }
    clock_t end = clock();
    double timer = (double)(end-begin)/CLOCKS_PER_SEC;
    printf("sorted in %f seconds \n", timer);
}

///////////////////////////////////  prints  //////////////////////////////////

void array_pprint(int *arr, int size)
{
    int *p = arr;
    int *end = arr + size;
    char *pad = "{ ";

    while (p < end)
    {
        printf("%s%d", pad, *p++);
        pad = ", ";
    }
    printf(" }\n");
}

///////////////////////////////////////////////////////////////////////////////

int main(){
    srand(time(NULL));
    int TAILLE = 10000;
    int range = 100;
    bool neg = true;
    
    int* list = malloc(TAILLE * sizeof(int));         // allocation memoire
    if(list == NULL){
        exit(0);
    }

    for(size_t i = 0; i < TAILLE; i++){
        int val = rand() % range;
        if(neg && coinflip()){
            list[i] = - val;
        }
        else
            list[i] = val;
    }

    timed_bubble_sort(list, TAILLE);
    shuffle(list, TAILLE);
    timed_coktail_shaker(list, TAILLE);
    shuffle(list, TAILLE);
    timed_quickSort(list, 0, TAILLE-1);
    // array_pprint(list, TAILLE);
    // stalin_sort(list, TAILLE);
    // array_pprint(list, TAILLE);


    free(list);                                      // free !!
}