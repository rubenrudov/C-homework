/**
 * @Authors: Ruben Rudov & Amit Machluf
 * @Purpose: 23/11/2021 Class & Home work
 */

// Libs
#include "pch.h"
#include <stdio.h>
#include <string.h>

// Array size
#define SIZE 2

// Print colors for easier debugging (According to ANSI escape codes)
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"


// Struct of student
typedef struct Student {
    char name[6];
    int age;
} *ptr;

// Function titles
void productTostring(struct Product*);
void update(struct Product *, float);
void printProdArr(struct Product[]);
struct Product* findProd(struct Product[], int);
ptr input_class(int);
void print_class(ptr, int);

// Struct of player
struct Player 
{
    int code;
    const char* name;
    const char* team;
};

// Struct of product
struct Product 
{
    int code;
    const char* name;
    float price;
};


// Main function for checking exercises
int main()
{
    struct Player p1 = { 1, "Ruby Rudov", "Cali Condors" };
    struct Product p2 = { 2, "Biss lee", 12.5 };
    struct Product p3 = { 3, "Bamba", 13.5 };
    struct Product arr[SIZE] = {
        p2,
        p3
    };
    
    printProdArr(arr);
    // productTostring(&p2);
    update(&p2, 15.4);
    
    // Alert user that program running finished successfully
    printf("\n\n\n%sFINISHED%s\n\n\n", GREEN, RESET);
}

// Function implementatios
// To string function for Product struct
void productTostring(struct Product* p) 
{
    printf("%sProduct: %d, Name: %s, Price: %f%s\n",
        GREEN,
        p -> code,
        p -> name,
        p -> price,
        RESET
    );
}

// Update price of product
void update(struct Product* p, float nValue) 
{
    p -> price = nValue;
    printf("%sProduct: %s, Price: %f%s", BLUE, p -> name, p -> price, RESET);
}

// Print array of products
void printProdArr(struct Product arr[]) 
{
    int i;
    for(i = 0; i < SIZE; i++) 
    {
        productTostring(arr + i);
    }
}

// Return the product found in prods' index key
struct Product* findProd(struct Product prods[], int key)
{
    struct Product* p;
    for (p = prods; p->code != key; ++p) 
    {
        return p;
    }
}

// Get inputs of class students
ptr input_class(int num) {
    ptr p, q;
    int i;
    p = (ptr) calloc(num, sizeof(ptr));
    assert(p != NULL);
    for (i = 0, q=p; i < num; i++, q++) {
        printf("Enter name and age: \n");
        scanf_s("%s", &(q -> name));
        scanf_s("%d", &(q->age));
    }

    return p;
}

// Print class of students
void print_class(ptr c, int n) {
    int i;

    for (i = 0; i < n; i++, c++) {
        printf("Student: %s, age: %d", c -> name, c -> age);
    }
}

// Return average of class student ages
double age_avg(ptr c, int n) {
    double avg = 0;

    for (int i = 0; i < n; i++, c++) {
        avg += c->age;
    }

    return avg / n;
}

void swap(ptr a, ptr b)
{
    ptr temp;
    strcpy(temp->name, a->name);
    strcpy(a->name, b->name);
    strcpy(b->name, temp->name);

    temp->age = a->age;
    a->age = b->age;
    b->age = temp->age;
}

void sortarr(ptr a[], int size) {
    int i;
    for (i = 0; i < size - 1; i++) {
        swap(&a[i], min(&a[i + 1], size - i - 1));
    }
}
