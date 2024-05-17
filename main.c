
#include "tools.h"

int main(){

    srand(time(NULL));
    int TAILLE = 10;
    int range = 200;
    
    int* list = malloc(TAILLE * sizeof(int));         // allocation memoire
    if(list == NULL){
        exit(0);
    }

    for(size_t i = 0; i < TAILLE; i++){
        list[i] = rand() % range;
    }

    array_pprint(list, TAILLE);

    bogo_sort(list, TAILLE);

    array_pprint(list, TAILLE);

    free(list);                                      // free !!
}