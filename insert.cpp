/* Programmer :Vikash Kumar Thakur
   Topic      :1.Create
               2.Display
               3.Begin Insert
               4.Last Insert
               5.Random insert
    IDE       :VS Code
   Date       :05/07/2023
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
void disp();
void beginsert();
void endinsert();
void randominsert();
void create()
{
    head = NULL;
    int choice;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        cout << "Enter a number:" << endl;
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
        cout << "Do you want to continue(0,1)....!";
        cin >> choice;
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
void beginsert()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    cout << "Enter data you want :" << endl;
    cin >> newnode->data;
    newnode->next = head;
    head = newnode;
    cout << "\nnode inserted\n";
}
void endinsert()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    cout << "\nEnter data you want" << endl;
    cin >> newnode->data;
    newnode->next = NULL;
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    cout << "Node Inserted" << endl;
}
void randominsert()
{
    int i, loc, item;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        cout << "\nOVERFLOW\n";
    }
    else
    {
        cout << "Enter element value\n";
        cin >> item;
        newnode->data = item;
        cout << "\n Enter the loction after which you want to insert\n";
        cin >> loc;
        temp = head;
        for (i = 0; i < loc; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                cout << "\n Can't Insert\n";
                return;
            }
        }
        newnode->next = temp->next;
        temp->next = newnode;
        cout << "\n Node Inserted\n";
    }
}
int main()
{ 
    cout << "*******Create Data*********" << endl;
    create();
    cout << "Display data" << endl;
    disp();
    cout << endl;
    cout << "********Insert begin*******" << endl;
    beginsert();
    cout << "Display data" << endl;
    disp();
    cout << endl;
    cout << "*******Insert End*********" << endl;
    endinsert();
    cout << "Display data" << endl;
    disp();
    cout << endl;
    cout << "*******Insert After*******" << endl;
    randominsert();
    cout << "Display Data" << endl;
    disp();
    return 0;
}