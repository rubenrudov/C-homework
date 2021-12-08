/**
 * @Author: Ruben Rudov
 * @Purpose: Lists lesson - 24/11/2021
 */

#include "pch.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "assert.h"


// Array size
#define SIZE 3


// Print colors for easier debugging (According to ANSI escape codes)
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"


// List struct definition
typedef struct List_node {
    int data;
    struct List_node* next;
} List, * lptr;


// Function defs
lptr search(lptr, int);
lptr build_list();
void print_list(lptr);
lptr build_reversed_list();


// Main function for debugging 
int main() {
    lptr list = build_list();
    lptr list_rec = build_reversed_list();
    print_list(list);
    print_list(list_rec);
    return 0;
}

// Function for retrieving a list node with data = k
lptr search(lptr l, int k) {
    lptr p = l;

    while (p != NULL) {
        if (p->data == k) {
            return p;
        }

        p = p->next;
    }

    return NULL;
}

// Function for building a list by inputs
lptr build_list() {
    lptr list, tmp, last;
    int dat;

    // Resetting ptrs
    list = NULL;
    tmp = NULL;
    last = NULL;
    
    // For loop until SIZE const
    for (int i = 0; i < SIZE; i++) {
        printf("Enter number to list: \n");
        tmp = (lptr)calloc(1, sizeof(List));
        assert(tmp != NULL);
        scanf_s("%d", &dat);
        tmp->next = last;
        tmp->data = dat;

        // If not list -> create list
        if (!list) {
            list = tmp;
        }

        else {
            last->next = tmp;
        }

        last = tmp;
    }

    // Set last's next as NULL 
    last->next = NULL;

    return list;
}


// Print list function
void print_list(lptr l) {
    lptr tmp = l;

    // While the helper ptr isnt null print value - values marked in green
    while (tmp != NULL) {
        printf("%s%d%s -> ", GREEN, tmp->data , RESET);
        tmp = tmp->next;
    }

    printf("%s--||\n%s", GREEN, RESET);
}


// Build reversed list
lptr build_reversed_list() {
    lptr list, tmp;
    int dat;

    // Ptr resets
    list = NULL;
    tmp = NULL;

    for (int i = 0; i < SIZE; i++) {
        printf("Enter a number to the list:\n");
        scanf_s("%d", &dat);
        tmp = (lptr)calloc(1, sizeof(List));
        assert(tmp != NULL);
        tmp->next = list;
        tmp->data = dat;

        list = tmp;
    }

    return list;
}
