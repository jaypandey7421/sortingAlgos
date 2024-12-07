#include <stdio.h>
#include <stdbool.h>

void selectionSort(int input[], int size){
  
  for(int i=0; i<size; i++){
    int min_index = i;
    int temp;
    for(int j = i+1; j<size; j++){
      if(input[j] < input[min_index]){
        min_index = j;
      }
    }
   temp = input[min_index];
   input[min_index] = input[i];
   input[i] = temp;
  }

}

void displayList(int input[], int size){
  for(int i=0; i<size; i++){
    printf("%d ", input[i]);
  }
}

int main()
{
    int list[] = {64, 34, 25, 5, 22, 11, 90, 12};
    int size = sizeof(list)/ sizeof(list[0]);
    printf("Unsorted array: ");
    displayList(list, size);
    selectionSort(list, size);
    printf("\nSorted array: ");
    displayList(list, size );
    
    return 0;
}
