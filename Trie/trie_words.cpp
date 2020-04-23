struct TrieNode{
    TrieNode* chld[26];
    bool isVal;
    TrieNode(){
        for(int i=0;i<26;i++){
            chld[i]=NULL;
        }
        isVal=false;
    }
};

void insert(string word,TrieNode* root) {
    TrieNode* curr=root;
    for(char ch:word){
        if(curr->chld[ch-'a']==NULL){
            curr->chld[ch-'a']=new TrieNode();
        }
        curr=curr->chld[ch-'a'];
    }
    curr->isVal=true;
}

bool search(string &word,TrieNode* root) {
    TrieNode* curr=root;
    for(char ch:word){
        if(curr->chld[ch-'a']==NULL){
            return false;
        }
        curr=curr->chld[ch-'a'];
    }
    return curr->isVal;
}