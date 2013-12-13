//
//  set.h
//  set
//
//  Created by Hongsen Liu on 12/12/2013.
//  Copyright (c) 2013 Hongsen Liu. All rights reserved.
//

#ifndef bst_set_h
#define bst_set_h
#include <stdbool.h>
extern struct setnode **set;
bool member(struct setnode **set, int data);
void add(struct setnode **set, int data);
void unionsets(struct setnode **set1, struct setnode **set2);
struct setnode *intersection(struct setnode **set1, struct setnode **set2);
struct setnode *difference(struct setnode **set1, struct setnode **set2);
bool is_subset(struct setnode **set1, struct setnode **set2);
int size(struct setnode **set);
void freeset(struct setnode **set);
#endif
