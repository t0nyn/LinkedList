#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    node *next;
    node *prev;
};

void addStart(int n, node *head, node *tail);
void addEnd(int n, node *head, node *tail);
void menu(int n, node *head, node *tail);
void printNormal(node *head);
void printReverse(node *tail);

int main()
{
    node *h = (node *)malloc(sizeof(node));
    h->next = NULL;
    h->prev = NULL;
    node *t = (node *)malloc(sizeof(node));
    t->next = NULL;
    t->prev = NULL;

    int num;
    while (true)
    {
        printf("\nType an element(-1 to exit): ");
        scanf("%d", &num);
        if (num == -1)
            break;
        menu(num, h, t);
    }
    printNormal(h->next);
    printReverse(t);

    return 0;
}

void addStart(int n, node *head, node *tail)
{
    if (head->next == NULL)
    {
        head->next = tail;
        tail->data = n;
        tail->prev = head;
    }
    else
    {
        node *new_node = (node *)malloc(sizeof(node));
        new_node->next = head->next;
        new_node->data = n;
        new_node->prev = head;
        head->next->prev = new_node;
        head->next = new_node;
    }
}

void addEnd(int n, node *head, node *tail)
{
    if (head->next == NULL)
    {
        head->next = tail;
        tail->data = n;
        tail->prev = head;
    }
    else
    {
        node *new_node = (node *)malloc(sizeof(node));
        new_node->prev = tail->prev;
        new_node->next = tail;
        new_node->data = tail->data;
        tail->prev->next = new_node;
        tail->prev = new_node;
        tail->data = n;
    }
}

void menu(int n, node *head, node *tail)
{
    int choice, num;
    printf("Would you like to add an element at the start or end?\n");
    printf("0 - Start\n1 - End\n");
    scanf("%d", &choice);

    if (!choice)
    {
        addStart(n, head, tail);
    }
    else
    {
        addEnd(n, head, tail);
    }
}

void printNormal(node *head)
{
    if (head->next != NULL)
    {
        printf("%d ", head->data);
        printNormal(head->next);
    }
    else
    {
        printf("%d\n", head->data);
    }
}

void printReverse(node *tail)
{
    if (tail->prev != NULL)
    {
        printf("%d ", tail->data);
        printReverse(tail->prev);
    }
}