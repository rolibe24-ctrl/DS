// 2. Given a string, reverse it using STACK. For example “DataStructure” should be output as “erutcurtSataD.”

#include<iostream>
#include<stack>
using namespace std;

int main(){
    string str;
    cout<<"enter the string: ";
    cin>>str;
    
    stack<char> s;
    
    for(int i=0; i<str.length(); i++){
        s.push(str[i]);
    }
    
    string reversed="";
    while(!s.empty()){
        reversed+=s.top();
        s.pop();
    }
    
    cout<<"reversed string: "<<reversed<<endl;
    return 0;
}