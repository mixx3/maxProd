#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

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
    int n;
    scanf("%d", &n);
    array = malloc(n * sizeof(array[0]));
        if (!array) {printf("Allocation failed"); exit(1);}
        for (int j = 0; j < n; j++){
            scanf("%d", &array[j]);
        }
    printf("%d", fastAlg(array, n));
    return 0;
}

