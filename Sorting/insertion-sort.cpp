#include<iostream>

using namespace std;

int main()
{
    int i,j,size,temp;

    cout << "\n******************************";
    cout << "\n\tINSERTION SORT";
    cout << "\n******************************";
    
    cout<<"\nEnter the size of array : ";
    cin>>size;
    
    int a[size];

    cout<<"\nEnter the elements of the array : ";
    for(i=0;i<size;i++)
        cin>>a[i];
    
    for(i=1;i<=size-1;i++) {
        temp=a[i];
        j=i-1;
        while((temp<a[j])&&(j>=0)) {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=temp;
    }

    cout<<"\nSorted array : ";
    for(i=0;i<size;i++)
        cout<<a[i]<<" ";
        
    return 0;
}


