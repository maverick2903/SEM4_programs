#include <stdio.h>
int n,x;
int arr[100];

int BinarySearch(int low, int high)
{
    if(low<=high)
    {
        int mid = (low + high)/2;
        if(arr[mid] == x)
        {
            return mid;
        }
        else if(arr[mid] > x)
        {
            BinarySearch(low,mid-1);
        }
        else
        {
            BinarySearch(mid+1,high);
        }
    }
    else return -1;
}

void main()
{
    printf("Enter size of array\n");
    scanf("%d",&n);
    printf("Enter elements of array\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter element you want to search\n");
    scanf("%d",&x);
    int low = 0,high=n-1;
    int index = BinarySearch(low,high);
    printf("Element found at index: %d",index);
}
