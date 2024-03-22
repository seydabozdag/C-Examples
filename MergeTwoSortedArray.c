#include <stdio.h>

void mergeSorted(int src1[], int src2[], int newArr[], int n1, int n2) {
  
  int i = 0, j = 0, k = 0; 

  while(i < n1 && j < n2) { 

    if(src1[i] <= src2[j]) { 
      newArr[k++] = src1[i++]; 
    }else { 
      newArr[k++] = src2[j++]; 
    } 
  }      
  while(i < n1) {
    newArr[k++] = src1[i++]; 
  } 
  while (j < n2) {   
    newArr[k++] = src2[j++]; 
  } 
}

int main() {

  int src1[] = {10, 11, 25, 48, 51};
  int src2[] = {20, 34, 45, 56, 64};

  int n1 = sizeof(src1)/sizeof(src1[0]);
  int n2 = sizeof(src2)/sizeof(src2[0]);
      
  int newArr[n1+n2];

  mergeSorted(src1, src2, newArr, n1, n2);

  printf("New array = ");
  for(int i = 0; i < n1+n2; i++) {
    printf("%d ",newArr[i]);
  }

  return 0;
}