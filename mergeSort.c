#include <stdio.h>

void display(int input[], int size);
void mergeSort(int input[], int left, int right);
void merge(int input[], int left, int mid, int right);

int main(){
    int myARR[] = {3,10, 9, 29, 34, 15, 40, 24, 27, 68};
    int size = sizeof(myARR) / sizeof(myARR[0]);

    printf("Unsorted Array: ");
    display(myARR, size);

    mergeSort(myARR, 0, size-1);

    printf("\nSorted Array: ");
    display(myARR, size);

    return 0;
}

void display(int input[], int size){
    for(int i=0; i<size; i++){
        printf("%d ", input[i]);
    }
}

void mergeSort(int input[], int left, int right){
    if(left < right){
        int mid = (left + right) /2;
        mergeSort(input, left, mid);
        mergeSort(input, mid + 1, right);
        merge(input, left, mid, right); // merger left and right sub-array
    }
}

void merge(int input[], int left, int mid, int right){
    int leftArrSize = mid - left +1;
    int rightArrSize = right - mid;

    int tempLeftArr[leftArrSize];   // Create temporary left sub-array
    int tempRightArr[rightArrSize]; // Create temporary right sub-array

    // filling temp left sub-array
    for(int i=0; i<leftArrSize; i++){
        tempLeftArr[i] = input[left +i];
    }

    // filling temp right sub-array
    for(int i=0; i<rightArrSize; i++){
        tempRightArr[i] = input[mid +1 +i];
    }

    // putting sorted values from left and right sub-array to original array
    // it is same as sortin 2 arrays and putting the value in another array
    int i=0, j=0, k=left;
    while(i < leftArrSize && j < rightArrSize){
        if(tempLeftArr[i] < tempRightArr[j]){
            input[k] = tempLeftArr[i];
            i++;
        }else{
            input[k] = tempRightArr[j];
            j++;
        }
        k++;
    }

    // handelign lef-over elements of temp left sub-array, if any.
    while (i < leftArrSize)
    {
        input[k] = tempLeftArr[i];
        i++;
        k++;
    }
    // handeling remaining elements of tem right sub-array, if any.
    while (j < rightArrSize)
    {
        input[k] = tempRightArr[j];
        j++;
        k++;
    }
    
    
}