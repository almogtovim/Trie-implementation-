#define NUM_LETTERS ((int)26)
#define ASCII 97
#define ENTER (char) '\n'   // change 
#define TAB (char) '\t'     // change 
#define SPACE (char) ' '      // change 
#define END (char) '\0'     // change 

//#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0]) 
  
// Alphabet size (# of symbols) 
#define ALPHABET_SIZE (26) 
  
// Converts wordToInsert current character into index 
// use only 'a' through 'z' and lower case 
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

#define NOCHILD -1

// trie node 
typedef struct TrieNode 
{ 
    struct TrieNode *children[ALPHABET_SIZE]; 

    char letter;
    long unsigned int count;
  
   
    // end of a word 
    //bool isEndOfWord; 
}TrieNode; 

TrieNode *newNode(void);


//void insert(TrieNode *root, const char *wordToInsert);

bool search(TrieNode *root, const char *wordToSearch);

void getWord();

bool isStop(char c);

bool needNewWord(char c);

bool skipIllegalChar(char c);
bool isCharLeagal(char c);

void Start(TrieNode * pRootTrieNode); 

void  Clean(TrieNode * pRootTrieNode);

int hasChild(TrieNode * pRootTrieNode);

TrieNode * HandleCharacter(TrieNode * pRootTrieNode, TrieNode * pCurNode, char ch);

void print(TrieNode * root, char * str, int level);

void printReverse(TrieNode* root,char word[], int level);

int longestWord(TrieNode * node, int count);
// typedef enum {FALSE=0, TRUE=1} boolean;

// typedef struct node {
//     char letter;
//     long unsigned int count;
//     struct node* children[NUM_LETTERS];
// } node;

// void toLowerCase(char* s);

// int get_word(char w[]);

// int getIndex(node n, char c);

// void newNode(node *p, char c);

// void insertt(node **root);
