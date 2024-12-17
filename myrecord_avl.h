#ifndef MYRECORD_AVL_H
#define MYRECORD_AVL_H
#include "avl.h"

typedef struct {
    AVLNODE *root;
    int count;
    float mean;
    float stddev;
} AVLDS;

//function definitions
void merge_avl(AVLNODE **rootp_dest, AVLNODE *rootp_source);
void merge_avlds(AVLDS *dest, AVLDS *source);
void avlds_clean(AVLDS *ds);
int add_record(AVLDS *ds, RECORD data);
int remove_record(AVLDS *ds, char *name);
void calculate_stats(AVLDS *ds);
int avl_count_nodes(AVLNODE *rootpt);

#endif

