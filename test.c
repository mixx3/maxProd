#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>
int longAlg(int array[],int n){
    int product = INT_MIN;
    for (int i = 0; i < n; i++){
        int a = array[i];
        for (int j = i + 1; j < n; j++){
            int b = array[j];
            if (a * b >= product) product = a * b;
        }
    }
    return product;
}

int fastAlg(int array[], int n){
    int product = INT_MIN, max1 = 0, max2 = 0, index1 = -1,
    min1 = 0, min2 = 0, index2;
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
    int productN = min1 * min2;
    int productP = max1 * max2;
    int product3 = max1 * min1;
    if (productN >= productP && productN != 0){
        return productN;
    }
    else if (productP >= productN && productP != 0){
        return productP;
    }
    else if (n == 2){
        return product3;
    }
}

int main()
{
    srand(time(0));
    int* array, n = 0;
    for (int m = 0; m < 100; m++){
        n = rand() % 9 + 2;
        array = malloc(n * sizeof(array[0]));
        if (!array) {printf("Allocation failed"); exit(1);}
        for (int j = 0; j < n; j++){
            array[j] = (rand() % 7 - 3);
        }
        
        int myProduct = fastAlg(array, n);
        int common = longAlg(array, n);
        if (common != myProduct){
            for (int j = 0; j < n; j++){
                printf("%d ", array[j]);
            } 
            printf("\n %d %d \n", myProduct, common);
        }
    }
    
    return 0;
}
