#include <iostream>
#include <vector>
#include <unordered_set>

using std::vector;
using std::pair;
using std::unordered_set;

int reach(vector<vector<int> > &adj, int x, int y);
bool dfs(vector<vector<int>> &graph, unordered_set<int> &visited, int curr, int target);

int reach(vector<vector<int> > &adj, int x, int y) {
  //write your code here
  unordered_set<int> visited;
  if (dfs(adj, visited, x, y)) return 1;
  return 0;
}

bool dfs(vector<vector<int>> &graph, unordered_set<int> &visited, int curr, int target) {
  if (curr == target) return true;
  if (visited.find(curr) != visited.end()) return false;
  
  visited.insert(curr);
  for (int i = 0; i < graph[curr].size(); i++) {
    if (dfs(graph, visited, graph[curr][i], target)) return true;
  }
  return false;
}

int main() {
  size_t n , m;
  std::cin >> n >> m;
  // size_t n = 4, m = 2;
  // vector<std::pair<int, int>> arr = { {1, 2}, {3, 2} };
  // int x = 1, y = 4;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
    // adj[arr[i].first - 1].push_back(arr[i].second - 1);
    // adj[arr[i].second - 1].push_back(arr[i].first - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
