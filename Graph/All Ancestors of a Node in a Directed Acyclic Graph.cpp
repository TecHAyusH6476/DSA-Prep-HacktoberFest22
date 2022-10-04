 vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(int i=0;i<edges.size();i++)
            graph[edges[i][0]].push_back(edges[i][1]);
        
        vector<int> indgree(n,0);
        for(int i=0;i<n;i++){
            for(int x:graph[i])
                indgree[x]++;
        }
        vector<set<int>> tans(n);
        queue<int> mp;
        for(int x=0 ;x<n;x++)
            if(indgree[x]==0)
                mp.push(x);
        
                
       while(mp.empty()==false){
           int t=mp.front();
           mp.pop();
           
           for(int x:graph[t]){
               indgree[x]--;
               tans[x].insert(t);
               for(int y:tans[t])
                   tans[x].insert(y);
       
               if(indgree[x]==0)
                   mp.push(x);
           }
           
       }         
               vector<vector<int>> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=vector<int>(tans[i].begin(),tans[i].end());
        }
                return ans;
    }
