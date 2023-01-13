class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // Idea is to realize how many nodes are going to be there.
        // Total nodes will be between 0..9999 as start will always lie within that bound.
        
        vector<int> minSteps(1e5, INT_MAX);
        queue<pair<int, int>> q;
        
        q.push({0, start});        // {steps to reach start, start}
        minSteps[start] = 0;
        
        while(q.empty() == false) {
            int stepsToReachNode = q.front().first;
            int node = q.front().second;
            q.pop();
            
            for(int neighbour: arr) {
                int newStart = (node * neighbour) % 100000;
                if(stepsToReachNode + 1 < minSteps[newStart]) {
                    minSteps[newStart] = stepsToReachNode + 1;
                    if(newStart == end) return stepsToReachNode + 1;
                    q.push({minSteps[newStart], newStart});
                }
            }
        }
        
        return -1;
    }
};