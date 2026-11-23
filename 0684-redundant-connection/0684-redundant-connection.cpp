class Solution {
public:
    unordered_map<int,vector<int>>mp;   // to store the connect4ed edges

    bool dfs(int u,int v,vector<bool>&vis)
    {
        if(u==v)
        return true;

        vis[u]=true;

        for(int i : mp[u])
        {
            if(vis[i])
            continue;
           
            if(dfs(i,v,vis))
            return true;
        }

        return false;

    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            vector<bool>vis(edges.size(),false);

            if(mp.find(u)!=mp.end() && mp.find(v)!=mp.end() && dfs(u,v,vis)) // condition to check whether u and v present in map and they are connected or not
            {
                return edges[i];
            }

            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        return {};
        
    }
};