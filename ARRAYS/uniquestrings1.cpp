// @author sourav kumar , 21-01-2019

//program to check for unique strings


#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int r[100];
    int flag = 0;
    getline(cin,s);
    sort(s.begin(),s.end());
    for(int i = 0; i <= s.length()-1; i++){
        if(s[i] == s[i+1]){
            flag++;
        }
    }
    if(flag>0){
        cout<<"not unique "<<"repetitive of "<<flag<<" out of "<<s.length();
        
    }
    else{
        cout<<"unique";
    }
   cout<<s; 
}

// alternate solution could be to sort the array (string) using sort(str.begin(), str.end()) and then check for adjancent elements same and return . it takes 0(n log(n))