// program for inserting node in a sorted doubly linked lists only implementation of SortedInsert() is important and the rest are I/0 handling of files.
// @author sourav kumar , 20-03-2019

#include <bits/stdc++.h>

using namespace std;

class DoublyLinkedListNode {
    public:
        int data;
        DoublyLinkedListNode *next;
        DoublyLinkedListNode *prev;

        DoublyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class DoublyLinkedList {
    public:
        DoublyLinkedListNode *head;
        DoublyLinkedListNode *tail;

        DoublyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
                node->prev = this->tail;
            }

            this->tail = node;
        }
};

void print_doubly_linked_list(DoublyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_doubly_linked_list(DoublyLinkedListNode* node) {
    while (node) {
        DoublyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the sortedInsert function below.

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    DoublyLinkedListNode *new_node = new DoublyLinkedListNode(data);
    DoublyLinkedListNode *ptr = head;
	// if the list doesnt contain any nodes.
    if(head == NULL){
        return head;
    }
	// if the incoming data is lesser than the first node , that means it is now the new head of the modified list 
    if(head->data > data){
        new_node->next = ptr;
        ptr->prev = new_node;
        head = new_node;
        return head;
    }
	// now we need to check the correct position which can be either somewhere in between or at the last
    while(ptr->next != NULL){
        if(ptr->next->data >= data){
            break;
        }
        ptr = ptr->next;
    }
	// if it is at the last then we just need to set the next of preceding node and prev of current incoming node.
    if(ptr->next == NULL){
        ptr->next = new_node;
        new_node->prev = ptr;
    }
	// otherwise we have first set up next and prev of new node and then next of preceding node and prev of succeding node 
    else{
    DoublyLinkedListNode *temp = ptr->next;
    ptr->next = new_node;
    new_node->next = temp;
    new_node->prev = ptr;
    temp->prev = new_node;
    }
    return head;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        DoublyLinkedList* llist = new DoublyLinkedList();

        int llist_count;
        cin >> llist_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist_count; i++) {
            int llist_item;
            cin >> llist_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist->insert_node(llist_item);
        }

        int data;
        cin >> data;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        DoublyLinkedListNode* llist1 = sortedInsert(llist->head, data);

        print_doubly_linked_list(llist1, " ", fout);
        fout << "\n";

        free_doubly_linked_list(llist1);
    }

    fout.close();

    return 0;
}
