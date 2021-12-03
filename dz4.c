#include <stdio.h>
#include <stdlib.h> 
#define M 100 
void bubbleSort(int* num, int* B, int size); 
int main(void) { 
 
 int n; 
 int N; 
 int p; 
 
 int i, j; 
  
 printf("Enter the number of graph vertices: ");
 scanf("%d", &N); 
 /* 
 printf("Enter the number of graph edges: ");
 scanf("%d", &n); 
  
 p = 0.5 * (N - 1) * (N - 2); 
 if (n > p) { 
  printf("Graph connected\n"); 
 } 
 if (n <= p) { 
  printf("Graph not connected\n"); 
 }*/ 
 
  
 int** A = (int**)malloc(N * sizeof(int*)); 
 for (i = 0; i < N; i++) 
  A[i] = (int*)malloc(N * sizeof(int)); 
 
 for (i = 0; i < N; i++) 
  for (j = 0; j < N; j++) 
   scanf("%d", &A[i][j]); 
 
 
 int q = 0; 
 for (i = 0; i < N; i++) { 
  int sum = 0; 
  for (j = 0; j < N; j++) 
   sum = sum + A[i][j]; 
  if (sum % 2 == 0) { 
   q++; 
  } 
 } 
 
 
 
 int* B=(int*)malloc(q * sizeof(int)); 
 int* C = (int*)malloc(q * sizeof(int)); 
 
  
 int k = 0; 
 for (i = 0; i < N; i++) { 
  int s = 0; 
  for (j = 0; j < N; j++) 
   s = s + A[i][j]; 
  if (s % 2 == 0) { 
   B[k] = i + 1; 
   C[k] = s; 
   k++; 
  } 
 } 
  
  
 bubbleSort(C, B, q);
  
 
 for (i = q-1; i >=0; i--) { 
  printf("versh %d - ", B[i]); 
  printf("stepen %d \n", C[i]); 
 } 
 
  
 for (i = 0; i < N; i++) { 
  free(A[i]); 
 } 
 free(A); 
 free(B); 
 free(C); 
 
 return 0; 
} 
  
void bubbleSort(int* num, int* B, int size) { 
int i, j;
 for (i = 0; i < size - 1; i++) 
  for (j = (size - 1); j > i; j--)  
   if (num[j - 1] > num[j]) { 
    int temp = num[j - 1]; 
    num[j - 1] = num[j]; 
    num[j] = temp; 
 
    int t = B[j - 1]; 
    B[j - 1] = B[j]; 
    B[j] = t; 
   } 
}
