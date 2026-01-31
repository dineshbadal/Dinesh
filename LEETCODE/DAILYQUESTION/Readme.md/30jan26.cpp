  //Question number 2977 //   https://leetcode.com/problems/minimum-cost-to-convert-string-ii/
class Solution {
public:
    typedef long long ll;
    unordered_map<string, vector<pair<string, ll>>> adj; // Graph
    set<int> vaild_len;
    typedef pair<ll, string> P;
    string Source;
    string Target;
    ll infinty = 1e10;
    ll Dijstra(string& start, string& end) {
        unordered_map<string, ll> dist; // { int , string }
        //  if(end==start) return adj[cost].second;
        priority_queue<P, vector<P>, greater<P>> pq; // {int , string}
        pq.push({0, start});
        dist[start] = 0;
        while (!pq.empty()) {
            string node = pq.top().second;
            ll cost = pq.top().first;
            pq.pop();
            if (node == end) {
                break;
            }
            //     if (cost > dist[node]) continue;
            for (auto& it : adj[node]) {
                string neg = it.first;
                ll negcost = it.second;
                // Relaxation of the nodes
                if (!dist.count(neg) || cost + negcost < dist[neg]) {
                    dist[neg] = cost + negcost;
                    pq.push({dist[neg], neg});
                }
            }
        }
        ll finalresult = dist.count(end) ? dist[end] : infinty;
        return finalresult;
    }
    vector<ll> dp;
    ll solve(int idx) {
        // base case
        ll countans = infinty;
        if (idx >= Source.size()) {
            return 0;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }
        if (Source[idx] == Target[idx]) {
            countans = solve(idx + 1);
        }
        for (auto len : vaild_len) {
            if (idx + len > Source.length()) {
                break;
            }
            string start = Source.substr(idx, len);
            string end = Target.substr(idx, len);
            if (!adj.count(start)) {
                continue;
            }
            ll PossiblePath = Dijstra(start, end);
            if (PossiblePath == infinty) {
                continue;
            }
            countans = min(countans, PossiblePath + solve(idx + len));
        }
        return dp[idx] = countans;
    }
    long long minimumCost(string source, string target,
                          vector<string>& original, vector<string>& changed,
                          vector<int>& cost) {
        Source = source;
        Target = target;
        dp.assign(10001, -1);
        for (int i = 0; i < original.size(); i++) {
            adj[original[i]].push_back({changed[i], cost[i]});
        }
        for (auto it : original) {
            vaild_len.insert(it.length());
        }
        ll ans = solve(0);
        if (ans == infinty)
            return -1;
        return ans;
    }
};
