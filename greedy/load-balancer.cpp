// simple solution of Load Balancer
// just take the access or deficiemcy of load in different elements and the absolute max of all such is answer

#include<bits/stdc++.h>
using namespace std;
 
int main() {
    while(1){
        long int n;
        cin>>n;
        if(n == -1)
        break;

        long int mx = INT_MIN;
        long int sum = 0;
        
        long int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
            sum += arr[i];
        }
        
        if(sum%n != 0)
            cout<<-1<<endl;
        else{
            long int req = sum/n;
            long int ct = 0;
            
            for(int i=0;i<n;i++)
            {
                ct = ct + arr[i] - req;
                mx = max(abs(ct), mx);
            }
            
            cout<<mx<<endl;
        }	
    }
	return 0;
} 