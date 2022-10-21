long long trappingWater(int arr[], int n){
        int left[n];
        int right[n];
        int max1= arr[0] , max2=arr[n-1]; 
        for(int i=0;i<n;i++)
        {
            max1=max(arr[i],max1);
            left[i]=max1;
            max2=max(arr[(n-i)-1],max2);
            right[(n-i)-1]=max2;
        }
        long long sum=0;
        
        for(int i=0;i<n;i++)
        {
            sum+=abs(arr[i]-min(left[i],right[i]));
        }
        return sum;
    }
