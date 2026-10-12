class LRUCache {
public:
    struct node{
        int val;
        node *next;
        node *prev;
        int key;

        node(int key,int val){
            this->val=val;
            this->next=NULL;
            this->prev=NULL;
            this->key=key;
        }
    };

    void addNode(node *n){
        n->next=start->next;
        start->next->prev=n;
        start->next=n;
        n->prev=start;
    }

    int deleteNode(){
        auto n=end->prev;
        auto newEnd=n->prev;
        int k=n->key;
        newEnd->next=end;
        end->prev=newEnd;
        delete n;
        return k;
    }

    void deleteNode(node *n){
        auto previousNode=n->prev;
        previousNode->next=n->next;
        n->next->prev=previousNode;
    }

    node *start;
    node *end;
    int c;
    unordered_map<int,node*> m;
    LRUCache(int capacity) {
        start=new node(-1,-1);
        end=new node(-1,-1);
        start->next=end;
        end->prev=start;
        c=capacity;
    }
    int get(int key) {
     if(m.find(key)==m.end()) return -1;
     else{
        deleteNode(m[key]);
        addNode(m[key]);
        return m[key]->val;
     }  
    }
    
    void put(int key, int value) {
     if(m.find(key)==m.end()){
        node *n=new node(key,value);
        m[key]=n;
        if(c==0){
            int k=deleteNode();
            m.erase(k);
            addNode(n);
        }
        else{
            addNode(n);
            c-=1;
        }
     }
     else{
        node *n=m[key];
        deleteNode(n);
        n->val=value;
        addNode(n);
     }   
    }
};
