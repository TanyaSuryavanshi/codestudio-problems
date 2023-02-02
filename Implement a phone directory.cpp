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
            int index=word[0]-'a';                
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
        void insert(string word) { insertutil(root, word); 
        }

        void printsuggestion(trienode* curr,vector<string> &temp,string prefix){
            if(curr->isterminal){
                temp.push_back(prefix);
                
            }
            for(char ch='a';ch<='z';ch++){
                trienode* next=curr->children[ch-'a'];
                
                if(next!=NULL){
                    prefix.push_back(ch);
                    printsuggestion(next, temp,prefix);
                    prefix.pop_back();
                }
                
            }
        }
        vector<vector<string>> getsuggestion(string str){
            trienode* prev=root;
            vector<vector<string>> output;
            string prefix="";

            for(int i=0;i<str.length();i++){
                char lastch=str[i];
                prefix.push_back(lastch);
                //check for lastch
                trienode* curr=prev->children[lastch-'a'];
                //if not found
                if(curr==NULL){
                    break;
                }
                //if found
                vector<string> temp;
                printsuggestion(curr,temp,prefix);

                output.push_back(temp);
                temp.clear();
                prev=curr;

            }
            return output;
        }
};

vector<vector<string>>
phoneDirectory(vector<string> &contactList, string &queryStr) {
    Trie *t=new Trie();
    //inserting contactlist in trie
    for(int i=0;i<contactList.size();i++){
        string str=contactList[i];
        t->insert(str);
    }
    return t->getsuggestion(queryStr);
}
