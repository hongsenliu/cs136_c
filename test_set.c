//
//  main.c
//  set
//
//  Created by Hongsen Liu on 12/12/2013.
//  Copyright (c) 2013 Hongsen Liu. All rights reserved.
//

#include "set.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    struct setnode *set = NULL;
    add(&set, 6);
    add(&set, 2);
    add(&set, 7);
    add(&set, 1);
    add(&set, 4);
    add(&set, 3);
    add(&set, 5);
    add(&set, 9);
    add(&set, 8);
    add(&set, 5);
    struct setnode *set2 = NULL;
    add(&set2, 5);
    add(&set2, -1);
    add(&set2, 3);
    add(&set2, -14);
    add(&set2, 8);
    add(&set2, 10);
    add(&set2, 9);
    add(&set2, 6);
    add(&set2, -10);
    add(&set2, 0);
    int setsize = size(&set);
    printf("%d\n", setsize);
    printf("%d\n", member(&set, 0));
    
    //unionsets(&set, &set2);
    //printf("%d\n", member(&set, 0));
    setsize = size(&set);
    printf("%d\n", setsize);
    
    struct setnode *iset = intersection(&set, &set2);
    setsize = size(&iset);
    printf("%d\n", setsize);
    
    printf("%d\n", member(&iset, 5));
    
    struct setnode *dset = difference(&set, &set2);
    setsize = size(&dset);
    printf("%d\n", setsize);
    
    printf("%d\n", member(&dset, 5));
    
    printf("subset: %d\n", is_subset(&set, &set2));
    freeset(&set);
    freeset(&set2);
    freeset(&iset);
    freeset(&dset);

    
    return 0;
}

