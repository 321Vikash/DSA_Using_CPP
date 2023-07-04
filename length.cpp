/* Programmer :Vikash Kumar Thakur
   Topic      :Find the length of linklist
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
void length();
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
void length()
{
    int count = 0;
    temp = head;
    if (head == NULL)
    {
        cout << "Empty Node";
    }
    else
    {
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        cout << "\nLength of the list is :\t" << count;
    }
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
    cout<<"\nDisplay Data\n";
    disp();
    cout << "\n*******length*******************\n";
    length();
    return 0;
}