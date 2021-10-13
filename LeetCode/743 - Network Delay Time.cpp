class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adjList(n, vector<pair<int, int>>());
        vector<int> dist(n, INT_MAX);
        for (vector<int> time : times) {
            adjList[time[0] - 1].push_back(make_pair(time[1] - 1, time[2]));
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[k - 1] = 0;
        pq.push(make_pair(k - 1, 0));
        while (!pq.empty()) {
            int currNode = pq.top().first;
            int currDist = pq.top().second;
            pq.pop();
            for (pair<int, int> neighbour : adjList[currNode]) {
                int updatedDist = currDist + neighbour.second;
                if (updatedDist >= dist[neighbour.first]) {
                    continue;
                }
                dist[neighbour.first] = updatedDist;
                pq.push(make_pair(neighbour.first, updatedDist));
            }
        }
        int maxDist = 0;
        for (int d : dist) {
            maxDist = max(maxDist, d);
        }
        return maxDist == INT_MAX ? -1 : maxDist;
    }
};
