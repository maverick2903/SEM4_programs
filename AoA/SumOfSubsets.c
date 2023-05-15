#include <stdio.h>
#define MAX_ELEMENTS 6

int numElements = 6;
int weights[MAX_ELEMENTS] = {5, 10, 12, 13, 15, 18}; //Works even if not sorted
int targetSum = 30;
int subset[MAX_ELEMENTS] = {0};

void printSubset() 
{
    for (int i = 0; i < numElements; i++) 
    {
        printf("%d ", subset[i]);
    }
    printf("\n");
}

void findSumOfSubset(int currentIndex, int currentSum) 
{
    if (currentSum == targetSum) //If solution found then return to prev iteration
    {
        printf("Subset Found: ");
        printSubset();
        return;
    }

    if (currentIndex >= numElements || currentSum > targetSum) //If you reach end of weights or if sum is exceeded then also return to prev iteration
    {
        return;
    }

    // Include the current element in the subset (This causes the recursion)
    subset[currentIndex] = 1;
    findSumOfSubset(currentIndex + 1, currentSum + weights[currentIndex]);

    // Exclude the current element from the subset(This executes after exiting from above recursion)
    subset[currentIndex] = 0;
    findSumOfSubset(currentIndex + 1, currentSum);
}

int main() 
{
    findSumOfSubset(0, 0);
    return 0;
}
