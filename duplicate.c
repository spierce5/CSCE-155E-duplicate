#include<stdlib.h>
#include<stdio.h>

void orderArray(int length, int *arr){
  for(int j=0; j < length; j++){                   //Orders array from small to large
    for(int i=0; i < length - 1; i++){
      int z;
      if(arr[i] > arr[i+1]){
        z = arr[i+1];
        arr[i+1] = arr[i];
        arr[i] = z;
      }
    }
  }
  return;
}

int numDuplicates(int length, int *arr){
  orderArray(length, arr);
  int sum = length;
  for(int i=0; i < length - 1; i++){
    if(arr[i] == arr[i+1]){
      sum--;
    }
  }
  if(sum < length){
    sum -= 1;
  }
  return length - sum;
}

int main(){
  int lengthArr;
  printf("Enter array length\n");
  scanf("%d", &lengthArr);

  int userArr[lengthArr];
  for(int i=0; i < lengthArr; i++){
    scanf("%d", &userArr[i]);
  }

  printf("The number of duplicates is %d\n", numDuplicates(lengthArr, userArr));

  return 0;
}
