Write a program to implement recursive solution to the Tower of Hanoi puzzle and display the computation time.

#include <stdio.h>
#include <time.h>

void towers(int, char, char, char);

int main()

{
//clock_t start_t, end_t, total_t;
    int num;
    double x=clock();

 
//start_t = clock();
    printf("Enter the number of disks : ");

    scanf("%d", &num);

    printf("The sequence of moves involved in the Tower of Hanoi are :\n");

    towers(num, 'A', 'C', 'B');
    double y=clock();
    double z= y-x;
    printf("Total time taken by CPU: %f\n", z  );
//end_t = clock();
//total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
//   printf("Total time taken by CPU: %f\n", total_t  );
    return 0;

}

void towers(int num, char frompeg, char topeg, char auxpeg)

{

    if (num == 1)

    {

        printf("\n Move disk 1 from peg %c to peg %c", frompeg, topeg);

        return;

    }

    towers(num - 1, frompeg, auxpeg, topeg);

    printf("\n Move disk %d from peg %c to peg %c", num, frompeg, topeg);

    towers(num - 1, auxpeg, topeg, frompeg);

}
