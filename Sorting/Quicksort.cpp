#include<iostream>
using namespace std;
void swapp(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partitionn(int arr[],int h,int l)
{
    int pivot=arr[h];
    int pi=l-1;
    for(int i=l;i<h;i++)
    {
        if(arr[i]<=pivot)
        {
            pi++;
            swapp(&arr[i],&arr[pi]);
        }
    }
    swapp(&arr[pi+1],&arr[h]);
    return (pi+1);
}
void qsort(int arr[],int h,int l)
{
    if(l<h)
    {
        int pi=partitionn(arr,h,l);
        qsort(arr,pi-1,l);
        qsort(arr,h,pi+1);
    }
}
void insertion(int arr[],int n)
{

    for(int i=0;i<=n;i++)
    {
        int val=arr[i];
        int hole=i;
        while(hole>0&&arr[hole-1]>val)
        {
            arr[hole]=arr[hole-1];
            hole=hole-1;
        }
        arr[hole]=val;
    }
}
void print(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}
int main()
{
    int n ;
    cout<<"Enter the number of elements : ";
    cin>>n;
    int a[n];
for(int i=0;i<n;i++){
    cout<<"Enter the element "<<i+1<<" : ";
    cin>>a[i];

}


   
    qsort(a,n-1,0);
    
    cout<<endl<<"Sorted Array : "<<endl;
    print(a,n);


}