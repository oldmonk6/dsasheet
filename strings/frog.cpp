class Solution {
public:
  int dp[2000][2000];
  unordered_map<int,int>mp;
 
  
    bool cross(int i,int k,int n,vector<int>&stones){
        if(k==0)return 0;
        if(i==n-1)return 1;
        if (dp[i][k] != -1) return dp[i][k];
         int idx=0;
         bool val1=false;
         bool val2=false;
         bool val3=false;
        
        if(mp.count(stones[i]+k)){
            idx=mp[stones[i]+k];
          val1=dp[i][k]=cross(idx,k,n,stones);
        } 
        if(mp.count(stones[i]+k-1)){
            idx=mp[stones[i]+k-1];
           val2=dp[i][k-1]=cross(idx,k-1,n,stones);

        } 
        if(mp.count(stones[i]+k+1)){
            idx=mp[stones[i]+k+1];
            val3=cross(idx,k+1,n,stones);
        }
        return dp[i][k]=val1 || val2 ||val3;
         
    }
    bool canCross(vector<int>& stones) {
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<stones.size();i++){
            mp.insert({stones[i],i});
        }
        if(stones[1]!=1)return false;
        return cross(1,1,stones.size(),stones);
        
        
    }
};