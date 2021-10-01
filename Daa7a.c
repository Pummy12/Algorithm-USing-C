#include <stdio.h>

// typedef struct items
// {
//    float profit;
//    float weight;
// }item;

void sort(int num, float weight[], float profit[], float capacity, float ratio[])
{
    float temp;
    for (int i = 0; i < num; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            if (ratio[i] < ratio[j])
            {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }
}

void knapsack(int n, float weight[], float profit[], float capacity)
{
    float x[20], p = 0;
    int i, j, m = capacity;

    for (i = 0; i < n; i++)
    {
        x[i] = 0.0;  // x --> stores ratio.
    }

    for (i = 0; i < n; i++)
    {
        // if (weight[i] > m)
        //     break;
        if (m>0 && weight[i]<=m)
        {
            x[i] = 1.0;
            p = p + profit[i];
            m = m - weight[i];
        }
        else
           break;
    }

    if (i < n)
        x[i] = m / weight[i];

    p = p + (x[i] * profit[i]);

    printf("\nThe result vector is:- ");
    for (i = 0; i < n; i++)
        printf("%f\t", x[i]);

    printf("\nMaximum profit is:- %f", p);
}

int main()
{
    float weight[20], profit[20], capacity, ratio[20], temp;
    int num, i, j;

    printf("\nEnter total number of objects:");
    scanf("%d", &num);

    printf("\nEnter weights and profits of each object: ");
    for (i = 0; i < num; i++)
    {
        scanf("%f %f", &weight[i], &profit[i]);
    }

    printf("\nEnter maximum Capacity of knapsack :");
    scanf("%f", &capacity);

    
    //Calculating ratio(Pi/Wi)
    for (i = 0; i < num; i++)
    {
        ratio[i] = profit[i] / weight[i];
    }

    //Bubble Sort 
    sort(num, weight, profit, capacity, ratio);
    
    knapsack(num, weight, profit, capacity);
    return (0);
}