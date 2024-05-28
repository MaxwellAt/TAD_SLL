#include "SLL.h"
#include <stdlib.h>
#include <string.h>



SLList *sllCreate(void) {
    SLList* list = (SLList*)malloc(sizeof(SLList));
    if(list != NULL) {
        list->first = NULL;
        return list;
    }
    return NULL;
}


int sllInsertAsLast(SLList* list, void* data) {
    if(list != NULL) {
        SllNode* newNode = (SllNode*)malloc(sizeof(SllNode));
        SllNode* last;
        if(newNode != NULL) {
            newNode->data = data;
            newNode->next = NULL;
            if(list->first == NULL) {
                list->first = newNode;
            } else {
                last = list->first;
                while(last->next != NULL) {
                    last = last->next;
                }
                last->next = newNode;
            }
            return TRUE;
        }
    }
    return FALSE;
}
void *sllGetFirstCur(SLList *list) {
    if(list != NULL && list->first != NULL) {
        list->cur = list->first;
        return list->cur->data;
    }
    return NULL;
}

void *sllRemoveLast(SLList *list) {
    if(list != NULL) {
        SllNode* del;
        SllNode* beforeDel;
        void* data;
        if(list->first != NULL) {
            del = list->first;
            if(del->next == NULL) {
                data = del->data;
                list->first = NULL;
                free(del);
                return data;
            }
            while(del->next != NULL) {
                beforeDel = del;
                del = del->next;
            }
            beforeDel->next = NULL;
            data = del->data;
            free(del);
            return data;
        }
    }
    return NULL;
}


void* sllQuerySpec(SLList* list, void* key, int(*cmp)(void*, void*)) {
    if(list != NULL && key != NULL) {
        if(list->first != NULL) {
            SllNode* current = list->first;
            int stat = cmp(current->data, key);
            while(stat != TRUE && current->next != NULL) {
                current = current->next;
                stat = cmp(current->data, key);
            }
            if(stat == TRUE) {
                return current->data;
            }
        }
    }
    return NULL;
}

void* sllRemoveSpec(SLList* list, void* key, int(*cmp)(void*, void*)) {
    if(list != NULL && key != NULL) {
        if(list->first != NULL) {
            SllNode* del = list->first;
            SllNode* beforeDel = NULL;
            void* saved;
            int stat = cmp(key, del->data);
            while(stat != TRUE && del->next != NULL) {
                beforeDel = del;
                del = del->next;
                stat = cmp(key, del->data);
            }
            if(stat == TRUE) {
                saved = del->data;
                if(beforeDel == NULL) {
                    list->first = del->next;
                } else {
                    beforeDel->next = del->next;
                }
                free(del);
                return saved;
            }
        }
    }
    return NULL;
}

void* sllGetNext(SLList* list) {
    if(list != NULL) {
        void* returnVal;
        if(list->cur != NULL) {
            if(list->cur->next != NULL) {
                list->cur = list->cur->next;
                returnVal = list->cur->data;
                return returnVal;
            }
        }
    }
    return NULL;
}

int sllDestroy(SLList *list) {
    if(list != NULL) {
        if(list->first == NULL) {
            free(list);
            return TRUE;
        }
    }
    return FALSE;
}


int sllInsertAsFirst(SLList *list, void *data) {
    if(list != NULL) {
        SllNode* newNode = (SllNode*)malloc(sizeof(SllNode));
        if(newNode != NULL) {
            newNode->data = data;
            newNode->next = list->first;
            list->first = newNode;
            return TRUE;
        }
    }
    return FALSE;
}
void *sllGetFirst(SLList *list) {
    if(list != NULL) {
        SllNode* saved;
        void* data;
        if(list->first != NULL) {
            saved = list->first;
            data = saved->data;
            return data;
        }
    }
    return NULL;
}

void *sllRemoveFirst(SLList *list) {
    if(list != NULL) {
        SllNode* del;
        SllNode* afterDel;
        void* data;
        if(list->first != NULL) {
            del = list->first;
            data = del->data;
            afterDel = del->next;
            list->first = afterDel;
            free(del);
            return data;
        }
    }
    return NULL;
}
int sllNumNodes(SLList* list) {
    if(list != NULL) {
        SllNode* last;
        int num = 0;
        if(list->first != NULL) {
            last = list->first;
            num++;
            while(last->next != NULL) {
                num++;
                last = last->next;
            }
            return num;
        }
    }
    return -1;
}

void* sllGetLast(SLList* list) {
    if(list != NULL) {
        SllNode* last;
        void* data;
        if(list->first != NULL) {
            last = list->first;
            while(last->next != NULL) {
                last = last->next;
            }
            data = last->data;
            return data;
        }
    }
    return NULL;
}


int sllInsertAfterN(SLList* list, void* data, int n) {
    if(list != NULL && data != NULL) {
        SllNode* newNode = (SllNode*)malloc(sizeof(SllNode));
        if(newNode != NULL) {
            SllNode* aux = list->first;
            SllNode* afterAux;
            newNode->data = data;
            newNode->next = NULL;
            for(int i = 0; i<n ; i++) {
                aux = aux->next;
            }
            afterAux = aux->next;
            aux->next = newNode;
            newNode->next = afterAux;
            return TRUE;
        }
    }
    return FALSE;
}

int sllInsertAfterSpec(SLList* list, void* data, int(*cmp)(void*, void*)) {
    if(list != NULL && data != NULL) {
        SllNode* newNode = (SllNode*)malloc(sizeof(SllNode));
        if(newNode != NULL) {
            SllNode* aux = list->first;
            SllNode* afterAux;
            newNode->data = data;
            newNode->next = NULL;
            while(cmp(data, (void*)&aux->data) == FALSE) {
                aux = aux->next;
            }
            afterAux = aux->next;
            aux->next = newNode;
            newNode->next = afterAux;
            return TRUE;
        }
    }
    return FALSE;
}

int sllInsertBeforeSpec(SLList* list, void* data, int(*cmp)(void*, void*)) {
    SllNode *prev, *spec;
    if(list != NULL) {
        if(list->first != NULL) {
            prev = NULL; spec = list->first;
            int stat = cmp(spec->data, data);
            while(stat != TRUE && spec->next != NULL) {
                prev = spec; spec= spec->next;
                stat = cmp(spec->data, data);
            }
            if(stat == TRUE) {
                SllNode* newNode = (SllNode *) malloc(sizeof(SllNode));
                if(newNode != NULL) {
                    newNode->data = data;
                    newNode->next = spec;
                    if(prev != NULL) {
                        prev->next = newNode;
                    } else {
                        list->first = newNode;
                    }
                }
            }
        }
    }
    return TRUE;
}
