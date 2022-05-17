#include <bits/stdc++.h>
using namespace std;
bool check_balanced(string s)
{
    stack<char> letter;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            letter.push(s[i]);
        else
        {
           if(s[i]==')')
           {
               if(letter.top()=='(')
               letter.pop();
           }
           else if(s[i]=='}')
           {
               if(letter.top()=='{')
               letter.pop();
           }
           else if(s[i]==']')
           {
               if(letter.top()=='[')
               letter.pop();
           }
           else
                return false;
        }
    }
    if (letter.empty())
        return true;
    else
        return false;
}
int main()
{
    string s;
    cin >> s;
    bool ans = check_balanced(s);
    cout << ans << endl;
    if (ans == true)
        cout << "balanced" << endl;
    else
        cout << "unbalanced" << endl;
    return 0;
}

/*#include <bits/stdc++.h>
using namespace std;
int main ()
{
    stack<char>s;
    string str;
cout<<"enter the string with brackets \n";
cin >>str;

/*for (int i=0;i<str.length();i++)
{
  if (str[i]=='(')
  s.push(str[i]);
  if (str[i]==')')
  {
      if (s.top()=='(')
      {
          s.pop();
          if(str[i+1]==')')
          {
              if (s.top()=='(')
              {
                  cout<<"true";
                  return 0;
              }
          }
      }
  }

}
cout<<"false";

int c=0,n=0;
for(int i=0;i<str.length();i++)
{
    if (str[i]!=')')
    {
        s.push(str[i]);
    }
    if (str[i]==')')
    {
        while (c!=1)
       {
            if(s.top()=='(')
           c++;
           s.pop();
           n++;

       }c=0;
       if(n==1)
       {
           cout<<"false";
           return 0;
       }
       n=0;
    }
}
cout<<"true";

    return 0;
}*/