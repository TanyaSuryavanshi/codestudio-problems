/*nversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
 

Example 1:

Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 
has three inversions (2, 1), (4, 1), (4, 3).*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
void merge(long long arr[],long long left,long long right,long long &ans){
      vector<long long int>v;
      long long mid=(left+right)/2,i=left,j=mid+1;
      while(i<=mid &&j<=right){
          if(arr[i]<=arr[j]){
              v.push_back(arr[i]);
              i++;
          }
          else{
              ans+=mid-i+1;
              v.push_back(arr[j]);
              j++;
          }
      }
      while(i<=mid){
          v.push_back(arr[i]);
          i++;
      }
      while(j<=right){
          v.push_back(arr[j]);
          j++;
      }
      for(long long k =left;k<=right;k++ ){
          arr[k]=v[k-left];
      }
  }
  void mergeSort(long long arr[],long long left,long long right,long long int &ans){
      if(left>=right){
          return;
      }
      long long mid=(left+right)/2;
      mergeSort(arr,left,mid,ans);
      mergeSort(arr,mid+1,right,ans);
      merge(arr,left,right,ans);
  }
    long long int inversionCount(long long arr[], long long N)
    {
        long long int ans=0;
        mergeSort(arr,0,N-1,ans);
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends
