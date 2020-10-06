#Problem Name :All Paths From Source to Target
#Problem Link: https://leetcode.com/problems/all-paths-from-source-to-target/
/*
Given a directed acyclic graph of N nodes. Find all possible paths from node 0 to node N-1, and return them in any order.

The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.
*/

class Solution {
public:
    void dfs(vector<vector<int>>&graph,int v,vector<int> temp,vector<vector<int>>& res){
        temp.push_back(v);
        if(v==graph.size()-1)
        {
            res.push_back(temp);
        }
        for(int x:graph[v]){
            dfs(graph,x,temp,res);
        }
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>res;
        vector<int> temp;
        dfs(graph,0,temp,res);
        return res;
    }
};
