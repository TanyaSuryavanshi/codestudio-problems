#include <bits/stdc++.h> 
bool isPossible(vector<int> &rank, int m, int mid)
{
    int count;
    int dish = 0;
    int time;
    
    for(int i = 0; i<rank.size(); i++)
    {
        time = 0;
        count = 1;
        while(true)
        {
            if( (time + (count * rank[i]) ) <= mid)
            {          
                time += count * rank[i];
                dish++;
                count++;
                if(dish == m)
                    return true;
            }
            else
                break;
        }
    }
    
    return false;
    
}
int minCookTime(vector<int> &rank, int m)
{
    
    int s=0;
    int maxi=-1;
    for(int i=0;i<rank.size();i++){
        maxi=max(maxi,rank[i]);
        
    }
    
    
    int e=maxi*m*(m+1)/2;
    int ans=-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if (isPossible(rank, m, mid)) {
            ans = mid;
            e=mid-1;
        }
        else
            s=mid+1;
            
        mid=s+(e-s)/2;
    
    }
    return ans;
}
