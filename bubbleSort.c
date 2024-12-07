#include <stdio.h>
#include <stdbool.h>

void bubbleSort(int input[], int size){
  
  for(int i=0; i<size; i++){
    bool swap = false;
    
    for(int j=0; j<(size-i-1); j++){
      
      int temp;
      if(input[j] > input[j+1]){
        temp = input[j+1];
        input[j+1] = input[j];
        input[j] = temp;
        swap = true;
      }
    }
    // Break the loop if array is sorted.
    if(!swap) break;
  }
  
}
void displayList(int input[], int size){
  for(int i=0; i<size; i++){
    printf("%d ", input[i]);
  }
}

int main()
{
    int list[] = {35, 12, 7, 90, 22, 3, 102, 34, 55};
    int size = sizeof(list)/ sizeof(list[0]);
    printf("Unsorted array: ");
    displayList(list, size);
    bubbleSort(list, size);
    printf("\nSorted array: ");
    displayList(list, size );
    
    return 0;
}
