#include <stdio.h>

void insertionSort(int sort[], int size){
    for(int i = 1; i<size; i++){
    	int currentVal = sort[i];
        int insertIndex = i;
        int j = i-1;
        
        while(j>=0 && sort[j] > currentVal){
        	sort[j+1] = sort[j];
            insertIndex = j;
        	j--;
        }
        
        sort[insertIndex] = currentVal;
    }

}

void displayArry(int display[], int size){
    for(int k =0; k<size; k++){
    	printf("%d, ", display[k]);
    }
}

int main(){
	int my_arr[] = {35, 12, 7, 90, 22, 3, 102, 34, 55};
    int size = sizeof(my_arr) / sizeof(my_arr[0]);
    printf("Unsroted Array: ");
    displayArry(my_arr, size);
    printf("\nSorted Array: ");
    insertionSort(my_arr, size);
    displayArry(my_arr, size);
    
    return 0;
}
