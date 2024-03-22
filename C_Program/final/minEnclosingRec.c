#include <stdio.h>


int findMin(int[],int);
int findMax(int [], int);

int main(void)
{
    int ptNums;
    scanf("%d",&ptNums);
    int arrX[ptNums],arrY[ptNums];

    for(int i=0; i < ptNums; i++){
        scanf("%d %d",&arrX[i],&arrY[i]);
    }

    printf("%d %d %d %d",findMin(arrX,ptNums),findMin(arrY,ptNums),findMax(arrX,ptNums),findMax(arrY,ptNums));

    return 0;
}

int findMin(int arr[], int length){
    int min = arr[0];
    for(int i=0; i< length; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}

int findMax(int arr[], int length){
    int max = arr[0];
    for(int i=0; i< length; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}