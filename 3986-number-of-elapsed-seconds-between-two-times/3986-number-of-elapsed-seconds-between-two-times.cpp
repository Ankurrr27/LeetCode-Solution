class Solution {
private:
    int inSeconds(string t){
        int hour = stoi(t.substr(0,2));
        int minute = stoi(t.substr(3,2));
        int second = stoi(t.substr(6,2));

        return hour*3600 + minute*60 + second;
    }
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        return inSeconds(endTime)-inSeconds(startTime);
    }
};