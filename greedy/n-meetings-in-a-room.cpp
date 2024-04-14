//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int startTimes[], int finishTimes[], int numMeetings)
    {
        int endTime;
        int meetingsCount = 0;
        vector<pair<int, int>> meetings; // {finish_time, start_time}
        
        // Create the meetings vector
        for (int i=0; i<numMeetings; i++) {
            meetings.push_back({finishTimes[i], startTimes[i]});
        }
        
        // Sort the meetings by finish time and then by start time
        sort(meetings.begin(), meetings.end());
        
        // Add the first meeting to the answer and set its finish time as the current end time
        meetingsCount++;
        endTime = meetings[0].first;
        
        // Iterate over the rest of the meetings
        for (int i=1; i<numMeetings; i++) {
            // If the start time of the current meeting is greater than the current end time
            if (meetings[i].second > endTime) {
                // Add the meeting to the answer and update the end time
                meetingsCount++;
                endTime = meetings[i].first;
            }
        }
        
        // Return the count of meetings that can be held
        return meetingsCount;
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