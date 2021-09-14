class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b = 0, a = 0, l = 0, o = 0, n = 0;
        for (int i = 0; i < text.size(); i++) {
            switch (text[i]) {
                case 'b':
                    b++;
                    break;
                case 'a':
                    a++;
                    break;
                case 'l':
                    l++;
                    break;
                case 'o':
                    o++;
                    break;
                case 'n':
                    n++;
                    break;
            }
        }
        return min(b, min(a, min(l / 2, min(o / 2, n))));
    }
};
