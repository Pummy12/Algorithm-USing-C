
#include<stdio.h>
int main(){
   int matr[5][5];
   int i, j;
   for(i=0; i<5; i++) {
      for(j=0;j<5;j++) {
         printf("Enter value for matr[%d][%d]:", i, j);
         scanf("%d", &matr[i][j]);
      }
   }
   
   printf("Two Dimensional array elements:\n");
   for(i=0; i<5; i++) {
      for(j=0;j<5;j++) {
         printf("%d ", matr[i][j]);
         if(j==4){
            printf("\n");
         }
      }
   }

   int min = __INT_MAX__;
   int max = 0;
   int sum = 0;
   int maxInd, minInd;

   for(int i=0; i<5; i++){
       for(int j=0; j<5; j++){
           sum+=matr[i][j];
       }
       if(max<sum){
           max = sum;
           maxInd = i;
       }
       if(min>sum){
           min = sum;
           minInd = i;
       }
       sum = 0;
   }

   printf("Max Edge weight: %d of node %d\n", max, maxInd);
   printf("\nMin Edge weight: %d of node %d\n", min, minInd);


   return 0;
}
