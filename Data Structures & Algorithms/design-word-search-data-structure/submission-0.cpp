class WordDictionary {
public:
    struct Node{
        Node *links[26];
        bool end;
        Node(){
            end=false;
            for(int i=0;i<26;i++) links[i]=NULL;
        }
        void insert(char c,Node *n){
            links[c-'a']=n;
        }
        void setEnd(){
            end=true;
        }
        bool present(char c){
            return links[c-'a']!=NULL;
        }
        Node *get(char c){
            return links[c-'a'];
        }
        bool isEnd(){
            return end;
        }
    };
    Node *root;
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        int n=word.length();
        auto t=root;
        for(int i=0;i<n;i++){
            if(!t->present(word[i])){
                t->insert(word[i],new Node());
            }
            t=t->get(word[i]);
        }
        t->setEnd();
    }
    
    bool search(string word) {
        int n=word.length();
        auto temp=root;
        return f(word,0,temp);
    }

    bool f(string word,int i,Node *root){
        if(i==word.length()){
            if(root->isEnd()) return 1;
            return 0;
        }
        if(word[i]!='.'){
            if(root->present(word[i])){
                return f(word,i+1,root->get(word[i]));
            }
            else return 0;
        }
        else{
            int p=0;
            for(int j=0;j<26;j++){
                if(root->links[j]!=NULL)
                p=p ||  f(word,i+1,root->links[j]);
            }
            return p;
        }
    }
};
