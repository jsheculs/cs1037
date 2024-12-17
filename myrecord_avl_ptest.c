#include <stdio.h>
#include <string.h>

#include "avl.h"
#include "myrecord_avl.h"

int get_height(AVLNODE *root) {
    if (root == NULL) return 0;
    return root->height;
}
int is_balanced(AVLNODE *root) {
    if (root == NULL){return 1;}

    int balance_factor = get_height(root->left)-get_height(root->right);
    if(balance_factor < -1 || balance_factor > 1){return 0;}
    return is_balanced(root->left) && is_balanced(root->right);

}

int is_avl(AVLNODE *root) {
    if (is_balanced(root)) {
        return 1;
    } else {
        return 0;
    }
}

RECORD create_record(const char* name,float score) {
    RECORD record;
    strncpy(record.name, name, sizeof(record.name)-1);
    record.name [sizeof(record.name)-1] = '\0';
    record.score = score;
    return record;
}

void display_stats(AVLDS *ds) {
    printf("count %d mean %.1f stddev %.1f",ds->count,ds->mean,ds->stddev);
}

void main() {
    AVLDS avldsA = {NULL, 0, 0, 0};
    AVLDS avldsB = {NULL, 0, 0, 0};
    AVLDS avldsC = {NULL, 0, 0, 0};

    // Add records to both AVL datasets (A and B)
    add_record(&avldsA, create_record("A", 50.0));
    add_record(&avldsA, create_record("B", 66.0));
    add_record(&avldsA, create_record("C", 55.0));
    add_record(&avldsA, create_record("D", 40.0));
    add_record(&avldsA, create_record("E", 70.0));
    add_record(&avldsA, create_record("F", 50.0));
    add_record(&avldsA, create_record("G", 60.0));
    add_record(&avldsA, create_record("H", 55.0));
    add_record(&avldsA, create_record("I", 40.0));
    add_record(&avldsA, create_record("J", 70.0));

    add_record(&avldsB, create_record("AB", 50.0));
    add_record(&avldsB, create_record("BB", 60.0));
    add_record(&avldsB, create_record("CB", 25.0));
    add_record(&avldsB, create_record("DB", 40.0));
    add_record(&avldsB, create_record("EB", 70.0));
    add_record(&avldsB, create_record("FB", 50.0));
    add_record(&avldsB, create_record("GB", 60.0));
    add_record(&avldsB, create_record("HB", 55.0));
    add_record(&avldsB, create_record("IB", 40.0));
    add_record(&avldsB, create_record("JB", 70.0));

    printf("Test: merge_avl\n");
    printf("is_avl (avlA): %d\n", is_avl(avldsA.root));
    printf("is_avl (avlB): %d\n", is_avl(avldsB.root));

    if (merge_avl(&(avldsA.root), avldsB.root)) {
        printf("merge_avl(avlA avlB): 1\n");
    }

    printf("Test: merge_avlds\n");

    // Display stats before merge
    printf("display_stats (avldsA): ");
    display_stats(&avldsA);

    printf("\ndisplay_stats (avldsB): ");
    display_stats(&avldsB);

    // Perform the merge
    merge_avlds(&avldsC, &avldsA);
    merge_avlds(&avldsC, &avldsB);

    // Display stats after merge
    printf("\ndisplay_stats (avldsC): ");
    display_stats(&avldsC);

    printf("\nmerge_avlds (avldsA avldsB) - display_stats (avldsA): ");
    merge_avlds(&avldsA, &avldsB);  // Merge B into A
    display_stats(&avldsA);

    printf("\navldsB.count: %d\n", avldsB.count);
    printf("avldsB.mean: %.1f\n", avldsB.mean);

    // Check if avldsA and avldsC match after merging
    printf("avldsA.count == avldsC.count: %d\n", avldsA.count == avldsC.count);
    printf("avldsA.mean == avldsC.mean: %d\n", avldsA.mean == avldsC.mean);
    printf("avldsA.stddev == avldsC.stddev: %d\n", avldsA.stddev == avldsC.stddev);
}