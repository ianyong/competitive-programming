class MedianFinder {
private:
    priority_queue<int> smallerHalf;
    priority_queue<int, vector<int>, greater<int>> largerHalf;

public:
    void addNum(int num) {
        if (smallerHalf.empty() || num < smallerHalf.top()) {
            smallerHalf.push(num);
        } else {
            largerHalf.push(num);
        }
        if (smallerHalf.size() > largerHalf.size() + 1) {
            largerHalf.push(smallerHalf.top());
            smallerHalf.pop();
        } else if (smallerHalf.size() < largerHalf.size()) {
            smallerHalf.push(largerHalf.top());
            largerHalf.pop();
        }
    }

    double findMedian() {
        if (smallerHalf.size() > largerHalf.size()) {
            return smallerHalf.top();
        }
        return smallerHalf.top() / 2.0 + largerHalf.top() / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
