class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& a) {
        
        
        
        vector<int>adj[V+1];
        for(int i=0;i<a.size();i++){
            
            
            adj[a[i][1]].push_back(a[i][0]);
        }
        
        
        	    vector<int>indegree(V,0);
	    
	    for(int i=0;i<V;i++){
	        
	        
	        for(auto it : adj[i]){
	            
	            indegree[it]++;
	        }
	    }
	    
	    queue<int>q;
	    for(int i=0;i<V;i++){
	        
	        if(indegree[i]==0){
	            
	            q.push(i);
	        }
	    }
	    
	    vector<int>v;
	    while(!q.empty()){
	        
	        
	        
	        
	        int x=q.front();
	        v.push_back(x);
	        q.pop();
	        
	        for(auto it : adj[x]){
	            
	            indegree[it]--;
	            if(indegree[it]==0)q.push(it);
	        }
	        
	        
	    }
	    if(v.size()!=V){
            
            return {};
        }
	    return v;
    }
};
