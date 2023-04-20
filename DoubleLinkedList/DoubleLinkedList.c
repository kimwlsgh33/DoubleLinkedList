//
//  DoubleLinkedList.c
//  DoubleLinkedList
//
//  Created by 김진호 on 2023/03/01.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct NODE {
    char szData[64];
    
    struct NODE *prev;
    struct NODE *next;
} NODE;

NODE* g_pHead;
NODE* g_pTail;
int g_nSize;

void InitList(void)
{
    g_pHead = (NODE*)malloc(sizeof(NODE));
    g_pTail = (NODE*)malloc(sizeof(NODE));
    g_nSize = 0;
    
    memset(g_pHead, 0, sizeof(NODE));
    memset(g_pTail, 0, sizeof(NODE));
    
    strlcpy(g_pHead->szData, "DUMMY HEAD", sizeof(g_pHead->szData));
    strlcpy(g_pTail->szData, "DUMMY TAIL", sizeof(g_pTail->szData));
    
    g_pHead->next = g_pTail;
    g_pTail->prev = g_pHead;
}

void ReleaseList(void)
{
    NODE* pTmp = g_pHead;
    while (pTmp != NULL)
    {
        NODE* pDelete = pTmp;
        pTmp = pTmp->next;
        printf("free(%p)\n", pDelete);
        free(pDelete);
    }
    
    g_pHead = NULL;
    g_pTail = NULL;
    g_nSize = 0;
    
    puts("ReleaseList()");
}


void PrintList(void)
{
    printf("PrintList(): g_nSize: %d g_pHead [%p], g_pTail [%p]\n", g_nSize, g_pHead, g_pTail);
    NODE* pTmp = g_pHead;
    while (pTmp != NULL)
    {
        // puts(pTmp->pszData);
        printf("[%p] %s, %p, [%p]\n", pTmp->prev, pTmp->szData, pTmp, pTmp->next);
        pTmp = pTmp->next;
    }
}

// int를 반환하면, index를 반환 할 수 있어서 좋다.
int InsertAtHead(const char* pszData) // read only
{
    NODE* pNewNode = malloc(sizeof(NODE));
    memset(pNewNode, 0, sizeof(NODE));
    
    // memcpy(pNewNode->szData, pszData, sizeof(pNewNode->szData));
    strlcpy(pNewNode->szData, pszData, sizeof(pNewNode->szData));
    pNewNode->next = g_pHead->next;
    pNewNode->prev = g_pHead;
    
    g_pHead->next = pNewNode;
    pNewNode->next->prev = pNewNode;
    
    g_nSize++;
    
    return g_nSize;
}

int InsertAtTail(const char* pszData)
{
    NODE* pNewNode = malloc(sizeof(NODE));
    memset(pNewNode, 0, sizeof(NODE));
    strlcpy(pNewNode->szData, pszData, sizeof(pNewNode->szData));
    
    pNewNode->next = g_pTail;
    pNewNode->prev = g_pTail->prev;
    
    g_pTail->prev = pNewNode;
    pNewNode->prev->next = pNewNode;
    
    g_nSize++;
    
    return g_nSize;

    return 0;
}

NODE* FindNode(const char* pszData)
{
    return 0;
}

int DeleteNode(const char* pszData)
{
    NODE* pNode = FindNode(pszData);
    
    return 0;
}

int GetSize(void)
{
    return g_nSize;
}

int GetLength(void)
{
    return GetSize();
}

int main(void){
    /* const int a = 0; */
    /* const int a = a + 1; */

    InitList();
    
    InsertAtHead("Test01");
    InsertAtHead("Test02");
    InsertAtHead("Test03");
    
    PrintList();
    
    //InsertAtTail("Test04");
    //InsertAtTail("Test05");
    //InsertAtTail("Test06");
    
    //PrintList();
    
    ReleaseList();
    
    return 0;
}
