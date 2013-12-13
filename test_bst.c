//
//  main.c
//  bst
//
//  Created by Hongsen Liu on 12/11/2013.
//  Copyright (c) 2013 Hongsen Liu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main()
{
	struct bstnode *bst = NULL;
	bst_insert(6, &bst);
	//bst_insert(6, &bst);
    bst_insert(2, &bst);
    bst_insert(7, &bst);
    bst_insert(9, &bst);
    bst_insert(8, &bst);
    bst_insert(1, &bst);
    bst_insert(4, &bst);
    bst_insert(3, &bst);
    bst_insert(5, &bst);
    printf("preorder: ");
    preorder(bst);
    printf("\n");
    printf("inorder: ");
    inorder(bst);
    printf("\n");
    printf("postorder: ");
    postorder(bst);
    printf("\n");
    struct bstnode *result = search(&bst, 10);
    if (result) {
        printf("found\n");
        
    }else
    {
        printf("not found\n");
    }
    deletebstnode(&bst, 6);
    
    printf("inorder: ");
    inorder(bst);
    printf("\n");
    
    deletebstnode(&bst, 4);
    
    printf("inorder: ");
    inorder(bst);
    printf("\n");
    deletebstnode(&bst, 7);
    
    printf("inorder: ");
    inorder(bst);
    printf("\n");
    
	deletebstnode(&bst, 3);
    
    printf("inorder: ");
    inorder(bst);
    printf("\n");
    
    bst_delete(bst);
	return 0;
}

