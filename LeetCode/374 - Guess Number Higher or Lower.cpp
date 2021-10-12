/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;
        int mid, result;
        while (true) {
            mid = low + (high - low) / 2;
            result = guess(mid);
            if (result == 0) {
                return mid;
            }
            if (result == -1) {
                high = mid;
                continue;
            }
            if (result == 1) {
                low = mid + 1;
            }
        }
    }
};
