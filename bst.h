//
//  bst.h
//  bst
//
//  Created by Hongsen Liu on 12/11/2013.
//  Copyright (c) 2013 Hongsen Liu. All rights reserved.
//

#ifndef bst_bst_h
#define bst_bst_h

extern struct bstnode **bst;

void bst_insert(int data, struct bstnode **bst);
void bst_delete(struct bstnode *root);
void preorder(struct bstnode *root);
void inorder(struct bstnode *root);
void postorder(struct bstnode *root);
struct bstnode *search(struct bstnode **bst, int data);
void deletebstnode(struct bstnode **bst, int data);
struct bstnode *findMax(struct bstnode **bst);
struct bstnode *findMin(struct bstnode **bst);

#endif
