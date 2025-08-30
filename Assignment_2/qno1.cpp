//1) Implement the Binary search algorithm regarded as a fast search algorithm with run-time complexity of Ο(log n) in comparison to the Linear Search.

#include <iostream>
using namespace std;

int binarysearch(int arr[], int size,int element){
        int left=0;
        int right=size-1;
        while (left<=right)
        {
                int mid=left+(right-left)/2;
                if(arr[mid]==element){
                        return mid;
                }
                else if(arr[mid]<element){
                        left=mid+1;
                }
                else{
                        right=mid-1;
                }
        }
        return -1;
}

int main(){
        int element;
        int array[]={1,2,3,4,5,6,7,8,9,10};
        int size=sizeof(array)/sizeof(array[0]);
        cout<<"Enter the element to be searched: ";
        cin>>element;
        int result=binarysearch(array,size,element);
        if(result!=-1){
                cout<<"Element found at: "<<result<<endl;
        }
        else{
                cout<<"Element not found"<<endl;
        }
}