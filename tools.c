#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>


////////////////////////////////  math tests  //////////////////////////////////

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


/////////////////////////////  sorting algorithms  /////////////////////////////

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



///////////////////////////////////  prints  ///////////////////////////////////

void array_pprint(int *array, int size)
{
    int *p = array;
    int *end = array + size;
    char *pad = "{ ";

    while (p < end)
    {
        printf("%s%d", pad, *p++);
        pad = ", ";
    }
    printf(" }\n");
}



////////////////////////////////////////////////////////////////////////////////


int main(){
    srand(time(NULL));
    int TAILLE = 20000;
    int range = 999;
    
    int* list = malloc(TAILLE * sizeof(int));         // allocation memoire
    if(list == NULL){
        exit(0);
    }

    for(size_t i = 0; i < TAILLE; i++){
        list[i] = rand() % range;
    }

    timed_bubble_sort(list, TAILLE);
    shuffle(list, TAILLE);
    timed_coktail_shaker(list, TAILLE);

    

    free(list);                                      // free !!
}