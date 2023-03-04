int findDuplicate(vector<int> &arr) 
{
    int ans=0;
    //here xor of elements 
    for(int i=0;i<arr.size();i++){
        ans=ans^arr[i];
    }
    //ans=0 beause of xor with same array
    //here xor of elements 1 to n-1
    for(int i=1;i<arr.size();i++){
        ans=ans^i;
    }
    return ans;
    //ans=0^x
    //ans=x   1,2,3  ..x...n-1....x
    //ans 1 till n-1 is 0 then its xor with left element
	
}


int findUnique(int *arr, int size)
{
    int ans=0;
    for(int i=0;i<size;i++){
        ans=ans^arr[i];
    }
    return ans;
}
//xor with same no. give 0 and xor 0 with any no. give that no.
