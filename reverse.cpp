/* Programmer :Vikash Kumar Thakur
   Topic      :Print the reverse order of linklist
   IDE        :VS Code
   Date       :04/07/2023
*/
#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *newnode, *temp, *head;
void create();
void reverse();
void beginsert();
void disp();
void create()
{
    int choice;
    head = NULL;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        cout << "Enter a number:";
        cin >> newnode->data;
        newnode->next = NULL;
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        cout << "Do you want to continue (0,1)";
        cin >> choice;
    }
}
void reverse()
{
    struct node *prevnode, *currentnode, *nextnode;
    prevnode = NULL;
    currentnode = nextnode = head;
    while (nextnode != NULL)
    {
        nextnode = nextnode->next;
        currentnode->next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }
    head = prevnode;
}

void beginsert()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    cout << "Enter data you want to insert :";
    cin >> newnode->data;
    newnode->next = head;
    head = newnode;
    cout << "Data Inserted\n";
}

void disp()
{
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
}

int main()
{
    create();
    cout << "**********Now you begning insert data**************\n";
    beginsert();
    disp();
    cout << "\n*******Reverse*******************\n";
    reverse();
    disp();
    return 0;
}