class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char slowestKey = keysPressed[0];
        int longest = releaseTimes[0];
        int duration;
        for (int i = 1; i < keysPressed.size(); i++) {
            duration = releaseTimes[i] - releaseTimes[i - 1];
            if (duration > longest) {
                slowestKey = keysPressed[i];
                longest = duration;
            } else if (duration == longest && keysPressed[i] > slowestKey) {
                slowestKey = keysPressed[i];
            }
        }
        return slowestKey;
    }
};
