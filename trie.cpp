//Trie to store words

#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct node{
    node* chld[26];
    bool isVal;
    node(){
        for(int i=0;i<26;i++){
            chld[i]=NULL;
        }
        isVal=false;
    }
};

void insert(string word,node* root) {
    node* curr=root;
    for(char ch:word){
        if(curr->chld[ch-'a']==NULL){
            curr->chld[ch-'a']=new node();
        }
        curr=curr->chld[ch-'a'];
    }
    curr->isVal=true;
}

bool search(string &word,node* root) {
    node* curr=root;
    for(char ch:word){
        if(curr->chld[ch-'a']==NULL){
            return false;
        }
        curr=curr->chld[ch-'a'];
    }
    return curr->isVal;
}

int main(){
    return 0;
}