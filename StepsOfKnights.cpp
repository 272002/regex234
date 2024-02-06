//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int n = N;

	    int tx = TargetPos[0]-1,ty = TargetPos[1]-1;
	    int sx = KnightPos[0]-1,sy = KnightPos[1]-1;

	    int vis[n][n] = {0};
	    queue< pair<pair<int,int>,int> > q;

	    q.push({{sx,sy},0});

	    int delRow[8] = {1,2,2,1,-1,-2,-2,-1};
	    int delCol[8] = {2,1,-1,-2,2,1,-1,-2};
	    
	    if((sx == tx) && (sy == ty)) return 0;

	    vis[sx][sy] = 1;
	    

        while (!q.empty())
        {
            auto it = q.front();
            int row = it.first.first;
            int col = it.first.second;
            int steps = it.second;
            q.pop();
            for (int i = 0; i < 8; i++)
            {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if (nrow == tx && ncol == ty)
                {
                    return steps+1;
                }
                
                if (vis[nrow][ncol] == 0 && nrow>=0 && nrow < n && ncol >= 0 && ncol < n)
                {
                    vis[nrow][ncol] = 1;
                    q.push({{nrow,ncol},steps + 1});
                }
                
            }
            
        }
        
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends