#include <stdio.h>

int partion(int input[], int low, int high){
  int pivotElement = input[high]; // Assuming last elment as pivot.
  int leftOfPivot = low-1; // Assuming, initially there is no elment in the left of pivot
  
  for(int i=low; i<high; i++){
    if(input[i] < pivotElement){
      leftOfPivot++;
      int temp = input[leftOfPivot];
      input[leftOfPivot] = input[i];
      input[i] = temp;
    }
  }
  // Taking the Pivot to its right place
  int temp = input[high];
  input[high] = input[leftOfPivot+1];
  input[leftOfPivot+1] = temp;
  
  // Return the Pivot index;
  return leftOfPivot +1;
}

void quickSort(int input[], int low, int high){
  if(low < high){
    int pivotElementIndex = partion(input,  low,  high);
    // Call quickSort for the lef partion
    quickSort(input, low,pivotElementIndex-1);
    // Call quickSort for the right partion
    quickSort(input, pivotElementIndex+1, high);
    
  }
}

void display(int arr[], int size){
  for(int i=0; i<size; i++){
    printf("%d ", arr[i]);
  }
}

int main(){
  int myARR[] = {65, 11, 13, 9, 77, 100, 48, 37, 22, 51, 42};
  int size = sizeof(myARR)/ sizeof(myARR[0]);
  
  printf("Unsorted Array: ");
  display(myARR, size);
  
  quickSort( myARR, 0, size-1);
  
  printf("\nSorted Array: ");
  display(myARR, size);
  
  
  return 0;
}