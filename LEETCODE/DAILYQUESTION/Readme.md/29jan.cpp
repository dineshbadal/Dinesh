//https://leetcode.com/problems/minimum-cost-to-convert-string-i/
#include<stdio.h>

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
  
        int len_org  = original.size();
        
      vector<vector<long long>>mat(26,vector<long long >(26,INT_MAX));
      //fill the diagonal with 0 
      for(int i=0 ; i<26 ;i++){
        for( int j=0 ; j<26 ;j++){
            if(i==j){
                mat[i][j]=0;
            }
        }
      }
      // here to avoid the max cost if min exit so we take min of both 
      //a → b (cost 100)  come first 
      //a → b (cost 5)   then this so we need to update this 

      for(int i=0 ;i<len_org ;i++){
       mat[original[i]-'a'][changed[i]-'a'] =
    min(mat[original[i]-'a'][changed[i]-'a'], (long long)cost[i]);

      }
      // apply the floy warshall now on this mat 
      for(int k=0 ;k<26 ; k ++){
        for( int i=0 ; i< 26 ;i++){
            for(int j=0 ; j<26;j++){
                if(mat[i][k]==INT_MAX || mat[k][j]==INT_MAX)
                continue ;
            
            if(mat[i][j]==INT_MAX){
                mat[i][j]=mat[i][k]+mat[k][j];
            }
            else {
                mat[i][j]=min(mat[i][k]+mat[k][j],mat[i][j]);
            }
            }
        }
      }
      int len_source = source.size();
      long long  ans =0 ;
      for( int i=0 ; i< len_source; i++){
        if(  mat[source[i]-97][target[i]-97]==INT_MAX)   return -1;
        ans += mat[source[i]-97][target[i]-97];
      }
   
      return ans;
    }
};

