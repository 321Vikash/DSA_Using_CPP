/* Programmer :vikash Kumar Thakur
   Topic      :1.Insert in begining
               2.Insert at last 
               3.Insert at any random location
               4.Delete from begining
               5.Delete from last
               6.Delete node after specified location
               7.Search for an element
               8.Show
   IDE        :VS Code
   */
#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *node;
void beginsert();
void lastinsert();
void randominsert();
void begin_delete();
void last_delete();
void random_delete();
void display();
void search();

int main()
{
    int choice = 0;
    while (choice != 9)
    {
        cout << "\n*******Main Menu*********" << endl;
        cout << "\nChoose one option from the following list.....!" << endl;
        cout << "\n===========================================" << endl;
        cout << "\n1. Insert in begining " << endl;
        cout << "\n2. Insert at last " << endl;
        cout << "\n3. Insert at any random location \n";
        cout << "\n4. Delete from begining \n";
        cout << "\n5. Delete from last \n";
        cout << "\n6. Delete node after specified location \n";
        cout << "\n7. Search for an element \n";
        cout << "\n8. Show \n";
        cout << "\n9. Exit \n";
        cout << "Enter your choice... \n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            beginsert();
            break;
        case 2:
            lastinsert();
            break;
        case 3:
            randominsert();
            break;
        case 4:
            begin_delete();
            break;
        case 5:
            last_delete();
            break;
        case 6:
            random_delete();
            break;
        case 7:
            search();
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
            break;
        default:
            cout << "Please enter valid choice.....\n";
        }
    }
}
void beginsert()
{
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node *));
    if (ptr == NULL)
    {
        cout << "\n OVERFLOW\n";
    }
    else
    {
        cout << "\n Enter value\n";
        cin >> item;
        ptr->data = item;
        ptr->next = node;
        node = ptr;
        cout << "\nNode Inserted\n";
    }
}
void lastinsert()
{
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node *));
    if (ptr == NULL)
    {
        cout << "\nOVERFLOW\n";
    }
    else
    {
        cout << "Enter value\n";
        cin >> item;
        ptr->data = item;
        if (node == NULL)
        {
            ptr->next = NULL;
            node = ptr;
            cout << "\n Node Inserted\n";
        }
        else
        {
            temp = node;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = NULL;
            cout << "\n Node Inserted\n";
        }
    }
}
void randominsert()
{
    int i, loc, item;
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        cout << "\nOVERFLOW\n";
    }
    else
    {
        cout << "Enter element value\n";
        cin >> item;
        ptr->data = item;
        cout << "\n Enter the loction after which you want to insert\n";
        cin >> loc;
        temp = node;
        for (i = 0; i < loc; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                cout << "\n Can't Insert\n";
                return;
            }
        }
        ptr->next = temp->next;
        temp->next = ptr;
        cout << "\n Node Inserted\n";
    }
}
void begin_delete()
{
    struct node *ptr;
    if (node == NULL)
    {
        cout << "\n List is empty\n";
    }
    else
    {
        ptr = node;
        node = ptr->next;
        delete ptr;
        cout << "\n Delete node from the begining...\n";
    }
}
void last_delete()
{
    struct node *ptr, *ptr1;
    if (node == NULL)
    {
        cout << "\n List is Empty\n";
    }
    else if (node->next == NULL)
    {
        node = NULL;
        delete ptr;
        cout << "\nOnly node of the list deleted\n";
    }
    else
    {
        ptr = node;
        while (ptr->next != NULL)
            ;
        {
            ptr1 = ptr;
            ptr = ptr->next;
        }
        ptr1->next = NULL;
        delete ptr1;
        cout << "\n Delete Node from the last\n";
    }
}
void random_delete()
{
    struct node *ptr, *ptr1;
    int loc, i;
    cout << "\n Enter the loction of the node sfter which you want to perform...\n";
    cin >> loc;
    ptr = node;
    for (i = 0; i < loc; i++)
    {
        ptr1 = ptr;
        ptr = ptr->next;
        if (ptr == NULL)
        {
            cout << "\n Can't delete\n";
            return;
        }
    }
    ptr1->next = ptr->next;
    delete ptr;
    cout << "\n Delete node\n"<< loc + 1;
}
void search()
{
    struct node *ptr;
    int item, i = 0, flag;
    ptr = node;
    if (ptr == NULL)
    {
        cout << "\n Empty List\n";
    }
    else
    {
        cout << "\n Enter item which you want to search?\n";
        cin >> item;
        while (ptr != NULL)
        {
            if (ptr->data == item)
            {
                cout << "\nItem found at location\n " << i + 1;
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
            }
            i++;
            ptr = ptr->next;
        }
        if (flag == 1)
        {
            cout << "\n Item not Found\n";
        }
    }
}
void display()
{
    struct node *ptr;
    ptr = node;
    if (ptr == NULL)
    {
        cout << "Nothing to print\n";
    }
    else
    {
        cout << "\n Printing value......\n";
        while (ptr != NULL)
        {
            cout << "\t" << ptr->data;
            ptr = ptr->next;
        }
    }
}