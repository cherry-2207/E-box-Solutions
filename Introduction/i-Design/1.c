#include<stdio.h>
#include<stdlib.h>
int main() {
    int n, count = 0;
    int *A;
    printf("Enter the number of elements in the array\n");
    scanf("%d", &n);
    A = (int *)malloc(n*sizeof(int));
    printf("Enter the elements in the array\n");
    for(int i = 0; i < n; i++)
        scanf("%d", A+i);
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(*(A+i) > *(A+j))
                count++;
        }
    }
    printf("The inversion count of the array is %d\n", count);
    return 0;
}
