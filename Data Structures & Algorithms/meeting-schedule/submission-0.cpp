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
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),[](auto &a,auto &b){
            return a.end < b.end;
        });
        int s=intervals[0].end;
        int n=intervals.size();
        for(int i=1;i<n;i++){
            if(intervals[i].start<s){
                return false;
            }
            else{
                s=intervals[i].end;
            }
        }
        return 1;
    }
};
