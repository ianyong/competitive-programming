class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adjList(numCourses, vector<int>());
        for (int i = 0; i < prerequisites.size(); i++) {
            int source = prerequisites[i][0];
            int dest = prerequisites[i][1];
            indegree[dest]++;
            adjList[source].push_back(dest);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] != 0) {
                continue;
            }
            q.push(i);
        }
        int num = 0;
        while (!q.empty()) {
            int source = q.front();
            q.pop();
            num++;
            for (int i = 0; i < adjList[source].size(); i++) {
                int dest = adjList[source][i];
                indegree[dest]--;
                if (indegree[dest] == 0) {
                    q.push(dest);
                }
            }
        }
        return num == numCourses;
    }
};
