// time complexity O(n^2)
// space complexity O(1)

#include <bits/stdc++.h>
using namespace std;

void insert_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        /*for(int j=i-1;j>=0;j--)   //using for loop
        {
            if(arr[j]>temp)
            {
                arr[i]=arr[j];
                arr[j]=temp;
            }
            else
            break;
            i--;
        }*/
        int j = i-1;
        while (j >= 0) // using while loop
        {
            if (arr[j] > temp)
            {
                arr[i] = arr[j];
                arr[j] = temp;
            }
            else
                break;
            i--;
            j--;
        }
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[7] = {10, 1, 7, 4, 8, 2, 11};
    insert_sort(arr, 7);

    return 0;
}