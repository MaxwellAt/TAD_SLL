#ifndef SLL_h
#define SLL_h
#define TRUE 1
#define FALSE 0

typedef struct sllNode {
    void* data;
    struct sllNode *next;
} SllNode;

typedef struct sLList {
    SllNode* first;
    SllNode* cur;
} SLList;


SLList *sllCreate (void);

int sllInsertAsLast(SLList* list,void* data);
void *sllGetFirstCur( SLList *list);
void *sllRemoveLast( SLList *list);
void* sllQuerySpec(SLList* list, void*key,int(*cmp)(void*,void*));
void* sllRemoveSpec(SLList* list,void* key,int(*cmp)(void*,void*));
void* sllGetNext(SLList* list);
int sllDestroy (SLList *list);


int sllInsertAsFirst( SLList *list, void *data);
void *sllGetFirst( SLList *list);
void *sllRemoveFirst( SLList *list);
int sllNumNodes(SLList* list);
void* sllGetLast(SLList* list);
int sllInsertAfterN(SLList* list, void* data, int n);
int sllInsertAfterSpec(SLList* list,void* data,int(*cmp)(void*,void*));
int sllInsertBeforeSpec(SLList* list,void* data,int(*cmp)(void*,void*));
#endif