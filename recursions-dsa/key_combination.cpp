#include<bits/stdc++.h>
using namespace std;

vector<string> combn(vector<string>key)
{
    if(key.size()==0)
    {
        key.push_back("");
        return key;
    }
    vector<string>temp;
 temp.push_back(key[key.size()-1]);
 vector<string>all_keys;

 key.pop_back();
 vector<string>main=combn(key);

for(int i=0;i<temp[0].length();i++)
{for(int j=0;j<main.size();j++)
{
    string s=temp[0][i]+main[j];
    all_keys.push_back(s);

}
}
return all_keys;
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
   
    vector<string>keys_final=combn(keys);
    for(auto x:keys_final)
    {
       cout<<x<<endl;
    }
    return 0;      
}






// //         base case
//         if(digits.length()<=0)
//         {
//             vector<string>st;
//             st.push_back("");
//             return st;
//         }
        
// //        keypad vector
//         vector<string>v={"1","2","abc","def","ghi", "jkl" ,"mno","pqrs", "tuv", "wxyz"};
    
// //         recursive case
//         int temp=digits[0]-'0';
//         string s=v[temp];
//         vector<string>left=letterCombinations(digits.substr(1));
//         vector<string>ans;
//         if(lef.size())
//         for(int i=0;i<s.length();i++)
//         {
//             for(int j=0;j<left.size();i++)
//             {
//                 ans.push_back(s[i]+left[j]);
//             }
//         }
//         return ans;   