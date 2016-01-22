#ifndef HF_LIST_H
#define HF_LIST_H

struct hflist
{
    struct hflist *next;
    void *data;
};

typedef struct hflist hflist;

extern hflist *hf_head;

typedef enum{
    false,true } bool;

bool isEmpty(const hflist *lst);

hflist* hflist_init( void);
hflist* list_new(void);

hflist* gethflist_head(void);

void hflist_add_item( const hflist *item);
void hflist_del_item(const hflist *item);

hflist *find_item(void *data);



#endif // HF_LIST_H
