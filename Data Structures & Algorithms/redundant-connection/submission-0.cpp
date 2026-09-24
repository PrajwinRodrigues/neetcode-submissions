class Solution {
public:
    class DSU{
        private:
        vector<int> parent;
        vector<int> size;
        public:
        DSU(int n){
            parent.resize(n+1,0);
            size.resize(n+1,1);
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }

        int getParent(int u){
            if(parent[u]==u) return u;
            return parent[u]=getParent(parent[u]);
        }

        void join(int u,int v){
            int pu=getParent(u);
            int pv=getParent(v);
            if(size[pu]>size[pv]){
                size[pu]+=size[pv];
                parent[pv]=pu;
            }
            else{
                size[pv]+=size[pu];
                parent[pu]=pv;
            }
        }
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU ds(n);
        vector<int> ans(2,-1);
        for(auto it:edges){
           if(ds.getParent(it[0])==ds.getParent(it[1])){
            ans[0]=it[0];
            ans[1]=it[1];
           }
           else{
            ds.join(it[0],it[1]);
           }
        }
        return ans;
    }
};
