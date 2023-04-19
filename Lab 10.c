#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Trie{
    int flag;
    struct Trie *next[26];
}Trie;

void insert(struct Trie **ppTrie, char *word){
    
    if(*ppTrie == NULL) return;
    
    int length = strlen(word);
    Trie *temp = *ppTrie;
    for( int i = 0; i < length; i++){
        int index = word[i] - 'a';
        
        if(temp -> next[index] == NULL){
            temp -> next[index] = (Trie *)calloc(1, sizeof(Trie));
        }// end if
        temp = temp -> next[index];
        
    }// end for
    temp -> flag++;
    
}// end insert
int numberOfOccurrences(Trie *pTrie, char *word) {
    if (pTrie == NULL) {
        return 0;
    }
    Trie *temp = pTrie;
    for (int i = 0; i < strlen(word); i++) {
        char c = word[i];
        int index = c - 'a';
        if (temp->next[index] == NULL) {
          printf("%c", index + 'a');
            return 0;
        }
        temp = temp->next[index];
    
        
    }
    return temp->flag;
}// end numberOfOccurrences
struct Trie *deallocateTrie(struct Trie *pTrie) {
    if (pTrie != NULL) {
        for (int i = 0; i < 26; i++) {
            pTrie->next[i] = deallocateTrie(pTrie->next[i]);
        }
        free(pTrie);
    }
    return NULL;
}// end deallocate


int main(void)
{
    // initialize trie
        struct Trie *trie = (Trie *)calloc(1, sizeof(Trie));
        
        
      char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};
      for(int i = 0; i < 5; i++) {
            insert(&trie, pWords[i]);
      }
        
      for(int i=0;i<5;i++)
      {
          printf("\t%s : %d\n",pWords[i], numberOfOccurrences(trie, pWords[i]));
     }
    trie = deallocateTrie(trie);
    if (trie != NULL)
       printf("There is an error in this program\n");
    return 0;
}// end main
