class PrefixTree {
public:
    struct Node{
        Node *links[26];
        bool end;
        Node(){
            end=false;
            for(int i=0;i<26;i++){
                links[i]=NULL;
            }
        }

            bool exists(char a){
                return links[a-'a']!=NULL;
            }
            void insert(char c,Node *n){
                links[c-'a']=n;
            }

            void setEnd(){
                end=true;
            }

            Node * get(char c){
                return links[c-'a'];
            }
    };
    Node *root;
    PrefixTree() {
       root=new Node(); 
    }
    
    void insert(string word) {
        int n=word.length();
        Node *temp=root;
        for(int i=0;i<n;i++){
            if(!temp->exists(word[i])){
                temp->insert(word[i],new Node());
            }
            temp=temp->get(word[i]);
        }
        temp->setEnd();
    }
    
    bool search(string word) {
        int n=word.length();
        Node *temp=root;
        for(int i=0;i<n;i++){
            if(!temp->exists(word[i])) return 0;
            temp=temp->get(word[i]);
        }
        return temp->end==true;
    }
    
    bool startsWith(string prefix) {
        int n=prefix.length();
        auto temp=root;
        for(int i=0;i<n;i++){
            if(!temp->exists(prefix[i])) return 0;
            temp=temp->get(prefix[i]);
        }
        return 1;
    }
};
