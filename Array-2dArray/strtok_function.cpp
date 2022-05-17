#include<bits/stdc++.h>
using namespace std;

// strtok function is used to break the sentence in multiple portions by spaces or chars etc
// it returns a pointer
// for first timme it takes input a string and breakpoint
// later it takes null and breakpoint


int main ()
{
    char s[100]="Hello my name is Vasu Devrani";
    char *ptr=strtok(s," ");
    
    cout<<ptr<<endl;

   string s1=ptr;
    cout<<s1<<endl;
    
    while(ptr!=NULL)
    {
        ptr=strtok(NULL," ");
        cout<<ptr<<endl;
    }

    return 0;
}