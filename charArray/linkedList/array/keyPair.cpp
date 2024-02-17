

class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool twoSum2Pointer(int arr[],int n,int x){
	    int l=0;
	    int h=n-1;
	    int csum=0;
	    while(l<h){
	        csum=arr[l]+arr[h];
	        if(csum==x) return true;
	        else if(csum>x) h--;
	        else l++;
	    }
	    return false;
	}
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	   // for(int i=0;i<n;i++){
	   //     for(int j=i+1;j<n;j++){
	   //         if(arr[i]+arr[j]==x){
	   //             return true;
	   //         }
	   //     }
	   // }
	   // return false;
	   
	//    sort(arr,arr+n);
	   return twoSum2Pointer(arr,n,x);
	}
};