//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    class compare{
        public:
        bool operator()(pair<int,int> a,pair<int,int> b)
        {
            return a.second<b.second;
        }
    };
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>> vec(n);
        for(int i=0;i<n;i++)
        {
            vec[i]={start[i],end[i]};
        }
        sort(vec.begin(),vec.end(),compare());
        int ans=1;int en=vec[0].second;
        for(int i=1;i<n;i++)
        {
            if(vec[i].first>en){ans++;en=vec[i].second;}
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends