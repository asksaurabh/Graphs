// Follow up: what if dict is wrong. For eg: sorted dict = [abcd, abc] or dict = [abc, bcd, ace]

class Solution {
public:
    string findOrder(string dict[], int N, int K) {
        // You need ordering(who before who ==> topo sorting)
        // Your graph will have K nodes(alphabets) each pointing to some other.
        // Pick two words and analyze why one word is appearing before another.

        vector<int> adj[K];
        vector<int> indegree(K, 0);
        string res = "";

        for (int i = 0; i < N - 1; i++) {
            string word1 = dict[i], word2 = dict[i + 1];
            for (int j = 0; j < min(word1.length(), word2.length()); j++) {
                char ch1 = word1[j], ch2 = word2[j];
                if (ch1 != ch2) {
                    // ch2 must appear after ch1
                    adj[ch1 - 'a'].push_back(ch2 - 'a');
                    indegree[ch2 - 'a']++;
                    break;
                }
            }
        }

        queue<int> q;
        for (int i = 0; i < K; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (q.empty() == 0) {
            int node = q.front();
            q.pop();

            res.push_back(node + 'a');
            for (int neighbour : adj[node]) {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0)
                    q.push(neighbour);
            }
        }

        return res;
    }
};