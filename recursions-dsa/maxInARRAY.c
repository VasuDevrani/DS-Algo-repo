#include <stdio.h>
int c=0;
 int size;
void arr_max(int arr[],int i)
{
    if(i>size-1)
    return;
   if(arr[i]>c)
   c=arr[i];
   arr_max(arr,i+1);

}

int main()
{
cin>>size;
int arr[size];
for (int i=0;i<size;i++)
{
    cin>>arr[i];
}
arr_max(arr,o);
cout<<c;

    return 0;
}