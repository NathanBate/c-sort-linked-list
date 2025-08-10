//
//  linked_list.h
//  sort-random-length-list
//
//  Created by Nathan on 7/28/25.
//

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100

typedef struct Node_t {
    char name[MAX_NAME_LEN];
    struct Node_t* next;
} Node_t;

// Function declarations
Node_t* create_node(const char* name, Node_t** head);
void append_node(Node_t** head, const char* name);
void print_list(const Node_t* head);
void free_list(Node_t* head);
void sort_list(Node_t* head);

#endif // LINKED_LIST_H
