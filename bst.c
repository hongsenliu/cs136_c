//
//  bst.c
//  bst
//
//  Created by Hongsen Liu on 12/11/2013.
//  Copyright (c) 2013 Hongsen Liu. All rights reserved.
//

#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

struct bstnode{
	int data;
	struct bstnode *left;
	struct bstnode *right;
};

static struct bstnode *create_bstnode(int data)
{
	struct bstnode *new_bstnode = (struct bstnode*)malloc(sizeof(struct bstnode));
	if(new_bstnode)
	{
		new_bstnode->data = data;
		new_bstnode->left = NULL;
		new_bstnode->right = NULL;
	}
	return new_bstnode;
}

struct bstnode *create_bst()
{
    struct bstnode *bst = (struct bstnode*)malloc(sizeof(struct bstnode));
    return bst;
}
void bst_insert(int data, struct bstnode **bst)
{
	struct bstnode *root = *bst;
	if(root == NULL)
	{
		*bst = create_bstnode(data);
        return;
	}else if(root->data > data)
	{
		bst_insert(data, &(root->left));
	}else if(root->data < data)
	{
		bst_insert(data, &(root->right));
	}
	return;
}

void bst_delete(struct bstnode *bst_root)
{
	if(bst_root)
	{
		bst_delete(bst_root->left);
		bst_delete(bst_root->right);
		free(bst_root);
	}
	return;
}

void preorder(struct bstnode *root)
{
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct bstnode *root)
{
    if (!root) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct bstnode *root)
{
    if (!root) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

struct bstnode *search(struct bstnode **bst, int data)
{
    struct bstnode *root = *bst;
    if (!root) {
        return NULL;
    }else{
        if (root->data == data) {
            return root;
        }else if (root->data > data)
        {
            return search(&root->left, data);
        }else
        {
            return search(&root->right, data);
        }
    }
}
struct bstnode *findMax(struct bstnode **bst)
{
    if (!(*bst)) {
        return NULL;
    }
    if ((*bst)->right) {
        return findMax(&(*bst)->right);
    }else
    {
        return *bst;
    }
}
struct bstnode *findMin(struct bstnode **bst)
{
    if (!(*bst)) {
        return NULL;
    }
    if ((*bst)->left) {
        return findMin(&(*bst)->left);
    }else{
        return *bst;
    }
}
void deletebstnode(struct bstnode **bst, int data)
{
    struct bstnode *pnode = *bst;
    if (!*bst) {
        return;
    }else if(pnode->data > data)
    {
        deletebstnode(&(*bst)->left, data);
    }else if(pnode->data < data)
    {
        deletebstnode(&(*bst)->right, data);
    }else
    {
        if (pnode->left && pnode ->right) {
            pnode = findMin(&(*bst)->right);
            (*bst)->data = pnode->data;
            deletebstnode(&(*bst)->right, pnode->data);
        }
        else
        {
            if ((*bst)->left == NULL) {
                *bst = (*bst)->right;
            }else if ((*bst)->right == NULL)
            {
                *bst = (*bst)->left;
            }
            free(pnode);
        }
    }
    return;
}
