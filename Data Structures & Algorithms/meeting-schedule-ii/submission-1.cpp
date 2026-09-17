/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        //Line sweeping can be used
        //At any point, the max number of intersections is the number of meeting
        //rooms needed

        vector<pair<int,int>> events;
        for(auto it:intervals){
            events.push_back({it.start,1});
            events.push_back({it.end,-1});
        }
        int c=0;
        int max=0;
        sort(events.begin(),events.end());
        for(auto it:events){
            c+=it.second;
            if(c>max){
                max=c;
            }
        }
        return max;
    }
};
