//
//  linked_list.c
//  sort-random-length-list
//
//  Created by Nathan on 7/28/25.
//

#include "../include/linked_list.h"

Node_t* create_node(const char* name) {
    Node_t* new_node = (Node_t*)malloc(sizeof(Node_t));
    if (!new_node) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    strncpy(new_node->name, name, MAX_NAME_LEN - 1);
    new_node->name[MAX_NAME_LEN - 1] = '\0';
    new_node->next = NULL;
    return new_node;
}

void append_node(Node_t** head, const char* name) {
    Node_t* new_node = create_node(name);
    if (*head == NULL) {
        *head = new_node;
    } else {
        Node_t* temp = *head;
        while (temp->next)
            temp = temp->next;
        temp->next = new_node;
    }
}

void print_list(const Node_t* head) {
    while (head) {
        printf("%s\n", head->name);
        head = head->next;
    }
}

void free_list(Node_t* head) {
    while (head) {
        Node_t* temp = head;
        head = head->next;
        free(temp);
    }
}

void sort_list(Node_t* head) {
    if (!head) return;

    int swapped;
    Node_t* ptr;
    Node_t* lptr = NULL;

    do {
        swapped = 0;
        ptr = head;

        while (ptr->next != lptr) {
            if (strcmp(ptr->name, ptr->next->name) > 0) {
                // Swap names
                char temp[MAX_NAME_LEN];
                strncpy(temp, ptr->name, MAX_NAME_LEN);
                strncpy(ptr->name, ptr->next->name, MAX_NAME_LEN);
                strncpy(ptr->next->name, temp, MAX_NAME_LEN);
                swapped = 1;
            }
            ptr = ptr->next;
        }
        lptr = ptr;
    } while (swapped);
}
