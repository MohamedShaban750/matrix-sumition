#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 

 
#define NUM_THRDS 8
#define M1 4 
#define M2 3 


pthread_t thrds[NUM_THRDS]; 
int Matrix_A[M1][M2] = { 
						{1,2,3}, 
						{1,7,8}, 
						{2,5,8}, 
						{4,2,3} };
int Matrix_B[M1][M2] = { 
    					{0,3,2}, 
    					{4,0,2}, 
    					{2,3,2}, 
    					{4,3,2} };
int sum[M1][M2]; 

void* Add(void* prm) { 
	int i, j; 
	for (i = 0; i < M1; i++)
		for (j = 0; j < M2; j++) 
			sum[i][j] = Matrix_A[i][j] + Matrix_B[i][j]; 
} 


int main() { 
    int i, j, itt = 0; 

    for(i = 0; i < NUM_THRDS; i++)
      pthread_create(&thrds[i], NULL, &Add, (void*)itt++);
      
  
    for(i = 0; i < NUM_THRDS ; i++) 
      pthread_join(thrds[i], NULL); 
    

    printf("\nSum = \n"); 
    for (i = 0; i < M1; i++){ 
      for (j = 0; j < M2; j++)
        printf("%d ", sum[i][j]); 
      
      printf("\n"); 
    } 

    return 0; 
} 
