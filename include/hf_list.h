#ifndef HF_LIST_H
#define HF_LIST_H

struct hflist
{
    struct hflist *next;
    void *data;
    char signature[128];
};

typedef struct hflist hflist;

extern hflist *hf_head;

bool isEmpty(const hflist *lst);

hflist* hflist_init( void);
hflist* list_new(void);

hflist* gethflist_head(void);

void hflist_add_item( const hflist *item);
void hflist_del_item(const hflist *item);

hflist *find_item(void *data);

void   create_signature(char *res, const char *name,const char *pwd);

void   hflist_free(void);



#endif // HF_LIST_H
