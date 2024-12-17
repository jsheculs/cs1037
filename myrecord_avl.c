#include <stdio.h>
#include "myrecord_avl.h"
#include <math.h>
#include "avl.h"

void merge_avl(AVLNODE **rootp_dest, AVLNODE *rootp_source) {
    if (!rootp_source){return;}//if source is empty return 0
    avl_insert(rootp_dest,rootp_source->data);//insert data from source into destination
    //recursively merge subtrees
    merge_avl(rootp_dest, rootp_source->left);
    merge_avl(rootp_dest,rootp_source->right);

}
void merge_avlds(AVLDS *dest, AVLDS *source) {
    if(!source || !source->root){return;}//do nothing is empty or null root
    merge_avl(&(dest->root), source->root);//merge source avl tree and destination avl tree
    calculate_stats(dest);//recalculate statistics
    avlds_clean(source);
}

void avlds_clean(AVLDS *ds) {
    if (ds == NULL){return;}//null ds do nothing
    avl_clean(&(ds->root));//recursively delete all nodes
    //reset statistics to 0
    ds->count =0;
    ds->mean=0;
    ds->stddev=0;
}
int add_record(AVLDS *ds, RECORD data) {
    if(avl_search(ds->root,data.name)!=NULL){return 0;}//return 0 if record already exists
    avl_insert(&(ds->root), data);//insert record into tree
    ds->count++;//increment count
    calculate_stats(ds);//recalculate statistics
    return 1;

}
int remove_record(AVLDS *ds, char *name) {
    if(avl_search(ds->root,name)==NULL){return 0;}//return 0 if record does not exist
    avl_delete(&(ds->root), name);//delete record from tree
    ds->count--;//decrement count
    calculate_stats(ds);//recalculate statistics
    return 1;
}
void calculation_helper(AVLNODE *node, float *sum, float *sum_squared, int *count){
    if (node == NULL) return;//return if node is null
    calculation_helper(node->left,sum,sum_squared,count);//recursivly traverse left

    //current node data calculations
    float score = node->data.score;
    *sum += score;
    *sum_squared += score * score;
    (*count)++;

    calculation_helper(node->right,sum,sum_squared,count);//recursively traverse right
}
void calculate_stats(AVLDS *ds) {
    float sum=0,sum_squared=0;//initiating variables
    int count=0;

    //if null reset stats to 0
    if(ds == NULL || ds->root == NULL) {
        ds->mean=0;
        ds->stddev=0;
        return;
    }
    calculation_helper(ds->root, &sum, &sum_squared, &count);//helper to calculate sum and sum_squared

    if (count > 0) {
        ds->mean = sum / count;//mean calculation
        ds->stddev = sqrt((sum_squared / count) - (ds->mean * ds->mean));//standard deviation calculation
    } else {//no records, set stats to zero
        ds->mean = 0;
        ds->stddev = 0;
    }

    ds->count = count;//update count
}


int avl_count_nodes(AVLNODE *rootpt) {
    if (rootpt == NULL){return 0;}//null case
    return 1 + avl_count_nodes(rootpt->left) + avl_count_nodes(rootpt->right);//calculates number of nodes
}
