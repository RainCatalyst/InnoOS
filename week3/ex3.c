#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node* next;
};

struct Node* create_node(int value)
{
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->value = value;
    return node;
}

int insert_next(struct Node* node, struct Node* next)
{
    if (node == NULL)
        return 0;
    next->next = node->next;
    node->next = next;
    return 1;
}

int delete_node(struct Node* list, struct Node* node)
{
    if (list == NULL || node == NULL)
        return 0;
    struct Node* current = list;
    while (current != NULL)
    {
        if (current->next == node){
            current->next = node->next;
            free(node);
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void print_list(struct Node* list)
{
    if (list == NULL)
        return;
    struct Node* current = list;
    while (current != NULL)
    {
        printf("%d\n", current->value);
        current = current->next;
    }
}

void main()
{
    struct Node* list = create_node(1);
    insert_next(list, create_node(2));
    struct Node* three = create_node(3);
    insert_next(list, three);
    print_list(list);
    delete_node(list, three);
    print_list(list);
    printf("next val %d", list->next->value);
}
