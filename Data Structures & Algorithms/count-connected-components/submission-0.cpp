class Solution {
public:
    class DSU{
        private:
        vector<int> parent;
        vector<int> size;
        public:
        DSU(int n){
           parent.resize(n+1,0);
           size.resize(n+1,0);
           for(int i=0;i<n;i++) parent[i]=i;
        }

        int getParent(int u){
            if(parent[u]==u) return u;
            return parent[u]=getParent(parent[u]);
        }

        int count(int n){
            int c=0;
            for(int i=0;i<n;i++){
                if(parent[i]==i) c+=1;
            }
            return c;
        }

        void join(int u,int v){
            int pu=getParent(u);
            int pv=getParent(v);
            if(pu==pv) return;
            if(size[pu]>size[pv]){
               parent[pv]=pu;
               size[pu]+=size[pv];
            }
            else{
                parent[pu]=pv;
                size[pv]+=size[pu];
            }
        }
    };
    int countComponents(int n, vector<vector<int>>& edges) {
         DSU ds(n);
         for(auto it:edges){
           ds.join(it[0],it[1]);
         }

         int c= ds.count(n);
         return c;
    }
};
