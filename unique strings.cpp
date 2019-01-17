#include<iostream>
using namespace std;

int main(){
    string s;
    int r[100];
    int flag = 0;
    getline(cin,s);
    int n = s.length();
    for(int i = 0; i <= n-1; i++){
        for(int j = i + 1; j <= n-1; j++){
            if(s[i] == s[j]){
                flag++;
            }
        }
    }
    if(flag>0){
        cout<<"not unique "<<"repetitive of "<<flag<<" out of "<<s.length();
        
    }
    else{
        cout<<"unique";
    }
    
}

// alternate solution could be to sort the array (string) using sort(str.begin(), str.end()) and then check for adjancent elements same and return . it takes 0(n log(n))