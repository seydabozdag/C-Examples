#include<stdio.h>

void transposeMatrix(int a[10][10], int b[10][10], int row, int column) {

  for(int i = 0; i < column; i++) {

    for(int j = 0; j < row; j++) {
      b[i][j] = a[j][i];
    }

  }
}

void readMatrix(int matrix[10][10], int row, int column) {

  for(int i = 0; i < row; ++i) {

    for(int j = 0; j < column; ++j) {
      scanf("%d", &matrix[i][j]);
    }

  }
}

void displayMatrix(int matrix[10][10], int row, int column) {

  for(int i = 0; i < row; ++i) {

    for(int j = 0; j < column; ++j) {
      printf("%d ", matrix[i][j]);
    }

    printf("\n"); 
  }
}

int main() {

  int matrix[10][10]; // First matrix
  int transpose[10][10]; // Second matrix

  int row, column;
  printf("Enter Row and Column of Matrix: ");
  scanf("%d %d", &row, &column);

  printf("Enter Matrix Elements: \n");
  readMatrix(matrix, row, column);

  // Transpose of matrix
  transposeMatrix(matrix, transpose, row, column);

  int trow = column;
  int tcolumn = row;

  printf("Resultant Matrix: \n");
  displayMatrix(transpose, trow, tcolumn);

  return 0;
}
