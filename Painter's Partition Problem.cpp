int findfeasible(vector<int> &boards,int n,int limit)
{
    int sum=0;
    int painters=1;
    for(int i=0;i<n;i++){
        
        sum+=boards[i];
        if(sum>limit){
            sum=boards[i];
            painters++;
        }

    }
    return painters;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int m=0; //max board length
    int totallength=0;
    int n= boards.size();
    for(int i=0;i<n;i++){
        m=max(m,boards[i]);
        totallength+=boards[i];
    }
    int low=m;
    int high=totallength;
    while(low<high){
        int mid=(low+high)/2;
        int painters=findfeasible(boards,n,mid);
        if(painters<=k)
            high=mid;
        else
            low=mid+1;
        
    }
    return low;
}
