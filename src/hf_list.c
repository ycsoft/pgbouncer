#include "bouncer.h"

#include "hf_list.h"
#include <stdlib.h>
#include <string.h>

hflist *hf_head = NULL;

hflist *hflist_init(void)
{
    hflist *lst = (hflist*)malloc(sizeof(hflist));

    hf_head = lst;
    lst->next = NULL;
    lst->data = NULL;
    return lst;
}
hflist *list_new(void)
{
    hflist *item = (hflist*)malloc(sizeof(hflist));
    memset(item,0,sizeof(hflist));
    return item;
}

hflist *gethflist_head(void)
{
    return hf_head;
}

bool isEmpty(const hflist *lst)
{
    return lst->next == NULL;
}

void hflist_add_item( const hflist *item)
{
    hflist *tail = gethflist_head();
    while ( tail ->next != NULL )
    {
        tail = tail->next;
    }
    if ( tail != NULL )
    {
        tail->next = item;
    }
}

void hflist_del_item(const hflist *item)
{
    hflist *ptr = gethflist_head();

    if( item == NULL )
        return;

    while(ptr != NULL && ptr->next != item )
    {
        ptr = ptr ->next;
    }
    //found
    if ( NULL != ptr)
    {
        ptr->next = item->next;
    }
    free(item);
}

hflist * find_item(void *data)
{
    hflist *head = gethflist_head();
    while ( head != NULL && strcmp(head->signature,(const char*)data) )
    {
        head = head->next;
    }
    return head;
}

void create_signature(char *res, const char *name, const char *pwd)
{
    sprintf(res,"%s:%s",name,pwd);
}

void hflist_free(void)
{
    hflist *head = gethflist_head();
    while( head != NULL )
    {
        hflist *pre = head;
        head = head->next;
        free(pre);
    }
}
