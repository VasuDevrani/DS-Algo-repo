// time complexity O(1)
// space complexity O(1)

#include<bits/stdc++.h>
using namespace std;

void print_combn(vector<string>keys,int i,string s)
{
    // base
    if(i==keys.size())
    {
        cout<<s<<endl;
        return;
    }

    // recursion
     string temp=keys[i];
     for(int j=0;j<temp.length();j++)
     {
         print_combn(keys,i+1,s+temp[j]);
     }

}


int main ()
{
    int n;
    vector<string>v={"?!","abc","def","ghi", "jkl" ,"mnop","qrst", "uv", "wx", "yz"};
    cout<<"enter the number of keys \n";
    cin>>n;
    cout<<"choose the keys \n";
    vector<string>keys;
    for(int i=0;i<n;i++)
    {int k;
    cin>>k;
    keys.push_back(v[k]);   
    }
    print_combn(keys,0,"");

    return 0;
}
























// #include<bits/stdc++.h>
// using namespace std;

// void combn(vector<string>v,int n,vector<char>s,int max)
// {
//     if(n>=max)
//     {
//       for(auto x:s)
//       cout<<x;
//       cout<<endl;
//        return ;
//     }
//     for(int i=0;i<v[n].length();i++)
//     {
//         char temp=v[n][i];
//         s.push_back(v[n][i]);
//         combn(v,n+1,s,max);
//         s.pop_back();
//     }
// }

// int main ()
// {
//      int n;
//     vector<string>v={"?!","abc","def","ghi", "jkl" ,"mnop","qrst", "uv", "wx", "yz"};
//     cout<<"enter the number of keys \n";
//     cin>>n;
//     cout<<"choose the keys \n";
//     vector<string>keys;
//     for(int i=0;i<n;i++)
//     {int k;
//     cin>>k;
//     keys.push_back(v[k]);   
//     }

//     vector<char>s;
//     combn(keys,0,s,n);

//     return 0;
// }