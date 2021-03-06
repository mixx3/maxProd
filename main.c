#include <stdio.h>
#include <stdlib.h>

int fastAlg(int array[], int n){
    int max1 = 0, max2 = 0, index1 = -1,
    min1 = 0, min2 = 0, index2 = -1;
    for (int i = 0; i < n; i++){
        if (array[i] > max1) {
            max1 = array[i];
            index1 = i;
        }
        else if (array[i] < min1){
            min1 = array[i];
            index2 = i;
        }
    }
    for (int i = 0; i < n; i++){
        if (array[i] > max2 && i != index1){
            max2 = array[i];
        }
        else if (array[i] < min2 && i != index2){
            min2 = array[i];
        }
    }
    if (n == 2){
        return array[0] * array[1];
    }
    else return ((max1 * max2) >= (min1 * min2)) ? max1 * max2 : min1 * min2;
}

int main()
{
    int n;
    scanf("%d", &n);
    if (n < 2) printf("Too few elements in array!");
    else{
        int* array = malloc(n * sizeof(array[0]));
        if (!array) {printf("Allocation failed\n"); exit(1);}
        for (int j = 0; j < n; j++){
            scanf("%d", &array[j]);
        } 
        printf("%d", fastAlg(array, n));
        free(array);
    }
    return 0;
}


