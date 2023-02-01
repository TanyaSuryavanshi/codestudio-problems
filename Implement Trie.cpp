/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

class trienode{
    public:
        char data;
        trienode* children[26];
        bool isterminal;

        trienode(char ch){
            data=ch;
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
            isterminal=false;
        }
};
class Trie {
    trienode* root;
public:

    /** Initialize your data structure here. */
    Trie() {
        root=new trienode('\0');
    }
    void insertutil(trienode* root,string word){
            if(word.length()==0){              //base case
                root->isterminal=true;
                return;
            }
            int index=word[0]-'a';                //assuming word is in capital 
            trienode* child;

            //present
            if(root->children[index]!=NULL){
                child=root->children[index];
            }
            else{       //absent
                child=new trienode(word[0]);
                root->children[index]=child;
            }

            //recursion
            insertutil(child,word.substr(1));

        }
    /** Inserts a word into the trie. */
    void insert(string word) {
        insertutil(root,word);
    }
    bool searchutil(trienode* root,string word){
            if(word.length()==0){              //base case
                return root->isterminal;
                
            }
            int index=word[0]-'a';                //assuming word is in capital 
            trienode* child;

            //present
            if(root->children[index]!=NULL){
                child=root->children[index];
            }
            else{       //absent
                return false;
            }

            //recursion
            return searchutil(child,word.substr(1));
        }
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return searchutil(root,word);
    }
    bool prefixutil(trienode* root,string word){
            if(word.length()==0){              //base case
                return true;
                
            }
            int index=word[0]-'a';                //assuming word is in capital 
            trienode* child;

            //present
            if(root->children[index]!=NULL){
                child=root->children[index];
            }
            else{       //absent
                return false;
            }

            //recursion
            return prefixutil(child,word.substr(1));
        }
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return prefixutil(root,prefix);
    }
};
