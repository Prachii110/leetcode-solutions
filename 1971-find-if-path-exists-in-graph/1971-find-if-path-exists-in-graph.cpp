class Solution {
public:

    // traversing using DFS ( Recursively )
    bool checkExist(unordered_map<int,vector<int>>&mp,int source,int destination,vector<bool>&vis)
    {
        if(source==destination)
        return true;

        //to prevent looping in single direction
        if(vis[source]==true)   
        return false;

        vis[source]=true;

        //explore
        for(int v : mp[source])
        {
            if(!vis[v])
            {
                bool ans=checkExist(mp,v,destination,vis);

                if(ans==true)
                return true;
            }
        }

        return false;

    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        unordered_map<int,vector<int>>mp;  // storing the vertices and the list of their edges

        //creating the adjacency list for the given graph
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];

            // because its bidirectional graph
            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        // creating the visited array
        vector<bool>vis(n,false);

        return checkExist(mp,source,destination,vis);
    }
};