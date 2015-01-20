#include<stdlib.h>
#include<stdio.h>

typedef struct ptr{
    int value;
    struct ptr* next;
}list;


int isEmpty(list *first) {
    if(first->next)
        return 0;
    return 1;
}

/* puts x at the end of the list */
void append(list *head, int x) {
    list *first = head;
    while(first->next) 
         first = first->next;
    list *newnode;
    newnode = (list*) malloc(sizeof(list));
    if(!newnode) {
        printf("malloc failed");
        exit(1);
    }
    newnode -> value = x;
    newnode -> next = NULL;
    first -> next = newnode;
}
/* puts x at the beginning of the list */
void prepend(list *first, int x) {
    list *newnode;
    newnode = (list*) malloc(sizeof(list));
    if(!newnode) {
        printf("malloc failed");
        exit(1);
    }
    newnode -> value = x;
    newnode -> next = first -> next;
    first -> next = newnode;
}

/* prints all elements in the list */
void print(list *head) {
    if (isEmpty(head)) {
        printf("Empty list\n");
        return;
    }
    list *first = head;
    while(first->next) {
        first = first->next;
        printf("%d ", first->value);
    }
    printf("\n");
}
/* input_sorted: find the first element in the list larger than x
   and input x right before that element */
void input_sorted(list *head, int x) {
    list *first = head;
    int inserted = 0;
    while(first->next) {
        if (first->next->value > x) {
            inserted = 1;
            list *newnode;
            newnode = (list*) malloc(sizeof(list));
            if(!newnode) {
                printf("malloc failed");
                exit(1);
            }
            newnode -> value = x;
            newnode -> next = first -> next;
            first -> next = newnode;
            return;
        }
        first = first -> next;
    }
    if (!inserted) {
        list *newnode;
        newnode = (list*) malloc(sizeof(list));
        if(!newnode) {
            printf("malloc failed");
            exit(1);
        }
        newnode -> value = x;
        newnode -> next = NULL;
        first -> next = newnode;
    }
}

/* free everything dynamically allocated */ 
void destroy(list *first) {
    list *aux = first -> next;
    while (aux) {
        first -> next = aux -> next;
        free (aux);
        aux = first -> next;
    }
}

int main( int argc, char ** argv)
{
    list root;
    root.value = -1; /* This value is always ignored */
    root.next = NULL;
    prepend(&root, 0);
    append(&root, 1);
    append(&root, 3);
    append(&root, 1);
    printf("0 1 3 1:\n");
    print(&root);
    printf("\n");
    append(&root, 1);
    prepend(&root, 2);
    prepend(&root, 3);
    append(&root, 5);
    printf("3 2 0 1 3 1 1 5:\n");
    print(&root);
    printf("\n");

    input_sorted(&root, 4);
    printf("3 2 0 1 3 1 1 4 5:\n");
    print(&root);
    printf("\n");

    destroy(&root);
    printf("Empty:\n");
    print(&root);
    printf("\n");


    append(&root, 3);
    printf("3:\n");
    print(&root);
    printf("\n");
}
