//
//  set.c
//  bst
//
//  Created by Hongsen Liu on 12/12/2013.
//  Copyright (c) 2013 Hongsen Liu. All rights reserved.
//

#include "set.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct setnode{
    int data;
    struct setnode *left;
    struct setnode *right;
};

static struct setnode *create_setnode(int data)
{
    struct setnode *new = (struct setnode*)malloc(sizeof(struct setnode));
    
    if(new)
    {
        new->data = data;
        new->left = NULL;
        new->right = NULL;
    }
    return new;
}

void add(struct setnode **set, int data)
{
    struct setnode *root = *set;
    if (!root) {
        *set = create_setnode(data);
        return;
    }else{
        if (root->data > data) {
            add(&(root->left), data);
        }else if (root->data < data) {
            add(&(root->right), data);
        }else
        {
            return;
        }
    }
    
}
//static void inorder(struct setnode **set)
//{
//    if (*set) {
//        inorder(&(*set)->left);
//        printf("%d ", (*set)->data);
//        inorder(&(*set)->right);
//    }
//    return;
//}
static void getsize(struct setnode *root, int *count)
{
    if (root) {
        getsize(root->left, count);
        (*count)++;
        getsize(root->right, count);
    }
    return;
}

int size(struct setnode **set)
{
    int *count = (int *)malloc(sizeof(int));
    *count = 0;
    getsize(*set, count);
    return *count;
}

bool member(struct setnode **set, int data)
{
    if (!*(set)) {
        return false;
    }
    if ((*set)->data > data) {
        return member(&(*set)->left, data);
    }else if ((*set)->data < data)
    {
        return member(&(*set)->right, data);
    }else{
        return true;
    }
}

void unionsets(struct setnode **set1, struct setnode **set2)
{
    if (*set2) {
        unionsets(set1, &(*set2)->left);
        add(set1, (*set2)->data);
        unionsets(set1, &(*set2)->right);
    }
    return;
}

static void getintersection(struct setnode **set1, struct setnode **set2, struct setnode **iset)
{
    if (*set1 && *set2) {
        getintersection(set1, &(*set2)->left, iset);
        if (member(set1, (*set2)->data)) {
            add(iset,(*set2)->data);
        }
        getintersection(set1, &(*set2)->right, iset);
    }
    return;
}

struct setnode *intersection(struct setnode **set1, struct setnode **set2)
{
    struct setnode *iset = NULL;
    getintersection(set1, set2, &iset);
    return iset;
}

static void getdifference(struct setnode **set1, struct setnode **set2, struct setnode **dset)
{
    if (*set1) {
        getdifference(&(*set1)->left, set2, dset);
        if (!member(set2, (*set1)->data)) {
            add(dset, (*set1)->data);
        }
        getdifference(&(*set1)->right, set2, dset);
    }
    return;
}

// In set theory, the difference means: set1 - set2 = {x is in set1 and x is not in set2};
struct setnode *difference(struct setnode **set1, struct setnode **set2)
{
    struct setnode *dset = NULL;
    getdifference(set1, set2, &dset);
    return dset;
}

// If set1 is a subset of set2 retun true, otherwise return false.
bool is_subset(struct setnode **set1, struct setnode **set2)
{
    if (!(*set1)) {
        return true;
    }else if(!(*set2))
    {
        return false;
    }else
    {
        if (member(set2, (*set1)->data)) {
            return is_subset(&(*set1)->left, set2);
            return is_subset(&(*set1)->right, set2);
        }
        return false;
    }
}
void freeset(struct setnode **set)
{
    if (*set) {
        freeset(&(*set)->left);
        freeset(&(*set)->right);
        free(*set);
    }
    return;
}  
