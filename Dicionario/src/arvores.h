#define STR_MAX 50

//Arvore Binaria de Pesquisa
typedef struct Abp {
    char input[STR_MAX];
    char output[STR_MAX];
    struct Abp *left;
    struct Abp *right;
} Abp;


//Arvore AVL (Balanceada)
typedef struct Avl {
    char input[STR_MAX];
    char output[STR_MAX];
    int bf; //Balance factor
    struct Avl *left;
    struct Avl *right;
} Avl;


//Arvore Splay (Cache)
typedef struct Splay {
    char input[STR_MAX];
    char output[STR_MAX];
    struct Splay *left;
    struct Splay *right;
} Splay;


extern int count_comp; //Contador de comparacoes totais
extern int n_nodes; //Contador de nos
extern int altura; //Altura da arvore
extern int n_rotacoes; //Contador de rotacoes
extern int count_search; //Contador de busca. Indica o numero de comparacoes feitas para encontrar um elemento


//=====================Funcoes Arvore ABP=================================


void ABP_ShowLevels(Abp *node, int n);

Abp* ABP_Init(Abp *node);

Abp* ABP_Insert(Abp *node, char input[], char output[]);

int ABP_GetLevel (Abp *node);


int ABP_Search(Abp **root, char **input);

//========================================================================



//=====================Funcoes Arvore AVL=================================

void A_ShowLevels(Avl *node, int n);

Avl* A_Init(Avl *node);

Avl* A_Insert(Avl *node, char input[], char output[]);

Avl* A_RotateLeft(Avl *node);

Avl* A_RotateRight(Avl *node);

int GetLevel (Avl *node);

void CalculateBF (Avl *node);

int A_Search(Avl **root, char **input);

Avl* AutoBalance(Avl *node); //Balance after insert

Avl* Balance(Avl *node);


//========================================================================

//===================== Funcoes Arvore Splay =============================

Splay* S_Init(Splay *node);

Splay* S_Insert(Splay *node, char input[], char output[]);

Splay* S_Splay (Splay *root, char input[]);

Splay* RotateLeft(Splay *node);

Splay* RotateRight(Splay *node);

int Splay_GetLevel(Splay *node);

void S_ShowLevels(Splay *node, int n);

int S_Search(Splay **root, char **input);

//========================================================================