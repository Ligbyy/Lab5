#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    char letter;
    struct node* next;
} node;
// Returns number of nodes in the linkedList.
int length(node* head)
{
    int length = 0;
    node* current = head;
    if(current == NULL){
        return -1;
    } else {

        while (current != NULL) {
            length++;
            current = current->next;
        }
        return length;
    }
}
// parses the string in the linkedList
// if the linked list is head -> |a|->|b|->|c|
// then toCString function wil return "abc"
char* toCString(node* head)
{
    char ch;
    char* str = (char*) malloc((length(head) +1) * sizeof(char ) );
    int index = 0;

    if(head == NULL){

    } else{
        while(head != NULL){
            ch = head->letter;
            str[index++] = ch;

            head = head->next;
        }
        str[index] = '\0';


        return str;
    }
}
// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
    node* newNode = (node*) malloc(sizeof (node));

    newNode->letter = c;
    newNode->next = NULL;
    if(*pHead == NULL){
        *pHead = newNode;
        return;
    } else{
        node* current = *pHead;
        while (current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }



}
// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
    node* current = *pHead;
    node* next;
    while(current){
        next = current->next;
        free(current);
        current = next;
    }
    *pHead = NULL;
}
int main(void)
{
    int i, strLen, numInputs;
    node* head = NULL;
    char* str;
    char c;
    FILE* inFile = fopen("C:\\Users\\blueg\\CLionProjects\\lab4\\input.txt","r");
    fscanf(inFile, " %d\n", &numInputs);
    while (numInputs-- > 0)
    {
        fscanf(inFile, " %d\n", &strLen);
        for (i = 0; i < strLen; i++)
        {
            fscanf(inFile," %c", &c);
            insertChar(&head, c);
        }
        str = toCString(head);
        printf("String is : %s\n", str);
        free(str);
        deleteList(&head);
        if (head != NULL)
        {
            printf("deleteList is not correct!");
            break;
        }
    }
    fclose(inFile);

}