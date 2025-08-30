//2) Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order. Code the Bubble sort with the following elements:

#include <iostream>
using namespace std;


int printsorted(int arr[],int size){
        cout<<"sorted array: ";
        for(int i=0;i<size;i++){
                cout<<arr[i]<<" ";
        }
        cout<<endl;
        return 0;
}

int main(){
        int temp;
        int array[]={64,34,25,12,22,11,90};
        int size=sizeof(array)/sizeof(array[0]);
        for(int i=0;i<size-1;i++){
                for(int j=0;j<size-i-1;j++){
                        if(array[j]>array[j+1]){
                                temp=array[j];
                                array[j]=array[j+1];
                                array[j+1]=temp;
                        }
                }
        }
        printsorted(array,size);
}

