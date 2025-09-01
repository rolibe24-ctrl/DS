#include<iostream>
using namespace std;

int binarysearch(int arr[],int n, int value){
    int s=0;
    int e=n;
    while(s<=e){
        int mid=(s+e)/2;
        if(arr[mid]==value){
            return mid;
        }else if(arr[mid]>value){
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    return -1;
}

int main(){
    int arrr[100], n , value;

    cout<<"\n enter the size of array:";
    cin>>n;
    cout<<"enter the element of array:";
    for(int i=0; i<n; i++){
        cin>>arrr[i];
    }
    cout<<"enter the element to search:";
    cin>>value;
    cout<<"the element found is:"<<binarysearch(arrr, n, value);
    return 0;
}