#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Trie_Node
{
    struct Trie_Node *alphabets[26];
    bool end;
    //endwith ,count word
} Trie_Node;

typedef struct Tries
{
    Trie_Node *root;
} Tries;

Trie_Node *newTrie_Node()
{
    Trie_Node *temp = (Trie_Node *)malloc(sizeof(Trie_Node));
    temp->end = false;
    for (int i = 0; i < 26; ++i)
    {
        temp->alphabets[i] = NULL;
    }
    return temp;
}
void Initialize_trie(Tries *tr)
{
    tr->root = newTrie_Node();
}

void Insert_trie(Tries *tr, char *string, int len)
{
    Trie_Node *root = tr->root;
    for (int i = 0; i < len; ++i)
    {
        char ch = string[i];
        if (root->alphabets[ch - 'a'] == NULL)
            root->alphabets[ch - 'a'] = newTrie_Node();
        root = root->alphabets[ch - 'a'];
    }
    root->end = true;
}
void SearchWord(Tries *tr,char * string, int len){
    Trie_Node* root= tr->root;
    for(int i=0; i < len; ++i){
        char ch= string[i];
        if(root->alphabets[ch -'a'] == NULL){
            printf("Word not found !!\n");
            return;
        }
        root= root->alphabets[ch - 'a'];
    }
    if(root->end){
        printf("Exact word found! \n");
    }
    else{
        printf("Part of word found ..\n");
    }
    return;
}

void StartsWith(Tries *tr,char * string, int len){
    Trie_Node* root= tr->root;
    for(int i=0; i < len; ++i){
        char ch= string[i];
        if(root->alphabets[ch -'a'] == NULL){
            printf("No such word found !!\n");
            return;
        }
        root= root->alphabets[ch - 'a'];
    }
    printf("There exist word !! ");
}


int main()
{
    Tries tr;
    Initialize_trie(&tr);
    char string[] = "abc";
    int len = sizeof(string) / sizeof(char);
    Insert_trie(&tr, string, len - 1);
    char string1[] = "def";
    Insert_trie(&tr, string1, len - 1);
    Insert_trie(&tr, "abd", 3);
    SearchWord(&tr,"abc",3);
    StartsWith(&tr,"b",1);

    return 0;
}