#include "chain.h"
#include "chain_given.cpp"
#include <cmath>
#include <iostream>

// PA1 functions

/**
 * Destroys the current Chain. This function should ensure that
 * memory does not leak on destruction of a chain.
 */
Chain::~Chain()
{
    // Your code here -- hint: this one is a single line!
    clear();
}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
void Chain::insertBack(const Block &ndata)
{   
    // Your code here
    Node * n = new Node(ndata);
    Node * last = tail_->prev;
    last->next = n;
    n->prev = last;
    n->next = tail_;
    tail_->prev = n;
    length_++;
   
}


/**
 * Swaps the two nodes at the indexes "node1" and "node2".
 * The indexes of the nodes are 1 based.
 * assumes i and j are valid (in {1,length_} inclusive)
 * 
 */
void Chain::swap(int i, int j)
{
    // Your code here
    // Your code here
    if (i == j) {
        return;
    }

    Node *node1 = walk(head_, i);
    Node *node2 = walk(head_, j);

    Node *node1next = node1->next;
    Node *node2next = node2->next;
    Node *node1prev = node1->prev;
    Node *node2prev = node2->prev;

    if (abs(i - j) == 1) { 
        // if node1 and node2 are next to each other
        node1next->prev = node1prev;
        node1prev->next = node2;
        node2next->prev = node1;
        node2prev->next = node2next;

        node1->prev = node2;
        node2->next = node1;
    } else {  
        node1next->prev = node2;
        node1prev->next = node2;
        node2next->prev = node1;
        node2prev->next = node1;

        node1->next = node2next;
        node1->prev = node2prev;
        node2->next = node1next;
        node2->prev = node1prev;
    }
}


/**
 * Reverses the chain
 */
void Chain::reverse()
{
    // Node *temp = NULL;
    // Node *current = head_;
     
    // while (current != NULL)
    // {
    //     temp = current->prev;
    //     current->prev = current->next;
    //     current->next = temp;            
    //     current = current->prev;
    // }
   
    // if(temp != NULL )
    //     head_ = temp->prev;
    int index1 = 1;
    int index2 = length_;
    while (index2 >= index1) {
        swap(index1, index2);
        index1++;
        index2--;
    }
}

/*
* Modifies the current chain by "rotating" every k nodes by one position.
* In every k node sub-chain, remove the first node, and place it in the last 
* position of the sub-chain. If the last sub-chain has length less than k,
* then don't change it at all. 
* Some examples with the chain a b c d e:
*   k = 1: a b c d e
*   k = 2: b a d c e
*   k = 3: b c a d e
*   k = 4: b c d a e
*/
void Chain::rotate(int k)
{
    // Your code here!
    int tracker = k - 1;
    int index = 1;
    if (k == 1 || k > length_) {
        return;
    }
    while (true) {
        if ((length_ - index) < k and tracker == 0) {
            return;
        }
        else if (tracker != 0) {
            swap(index, index + 1);
            index = index + 1;
            tracker--;
        } else {
            tracker = k - 1;
            index += 1;
        }
    }
}

/**
 * Destroys all dynamically allocated memory associated with the
 * current Chain class.
 */
void Chain::clear()
{
    // Your code here!
     while (head_ != NULL) {
         Node * temp = head_;
         head_ = head_->next;
         delete temp;
         temp = NULL; 
     }
}
    

/* makes the current object into a copy of the parameter:
 * All member variables should have the same value as
 * those of other, but the memory should be completely
 * independent. This function is used in both the copy
 * constructor and the assignment operator for Chains.
 */
void Chain::copy(Chain const &other)
{
    // Your code here!
    height_ = other.height_;
    width_ = other.width_;
    length_ = 0;
    head_ = new Node();
    tail_ = new Node();
    head_->next = tail_;
    tail_->prev = head_;
    Node * curr = other.head_->next;
    for(int i = 0; i< other.length_;i++){
        insertBack(curr->data);
        curr = curr->next;
    } 
}

/***********************************
 * swapColumns
 * parameters: 1 <= i <= numCols_
 *              1 <= j <= numCols_
 *
 * Swaps the positions of columns i and j
 * in the original grid of blocks by
 * moving nodes in the chain.
 *
 ***********************************/

void Chain::swapColumns(int i, int j) {
    // Your code here
    int col1;
    int col2;
    if (i > j) {
        col1 = j;
        col2 = i;
    } else {
        col1 = i;
        col2 = j;
    }
    while (col2 <= length_) {
        swap(col1, col2);
        col1 += numCols_;
        col2 += numCols_;
    }

}

/***********************************
 * swapRows
 * parameters: 1 <= i <= numRows_
 *              1 <= j <= numRows_
 *
 * Swaps the positions of rows i and j
 * in the original grid of blocks by
 * moving nodes in the chain.
 *
 ***********************************/
void Chain::swapRows(int i, int j) {
    // Your code here
    int row1;
    int row2;
    if (i > j) {
        row1 = j;
        row2 = i;
    } else {
        row1 = i;
        row2 = j;
    }
    for (int k = (row1-1)*numCols_ + 1; k < (row1-1)*numCols_ + numCols_ + 1; k++) {
        if ((k + (row2-row1)*numCols_) > length_) {
            return;
        }
        swap(k, k + (row2-row1)*numCols_);
    }
    // int row1;
    // int row2;
    // if (i > j) {
    //     row1 = ((j*numCols_) - (numCols_-1));
    //     row2 = ((i*numCols_) - (numCols_-1));
    // } else {
    //     row1 = ((i*numCols_) - (numCols_-1));
    //     row2 = ((j*numCols_) - (numCols_-1));
    // }
    // int k = 0;
    // while (k < numCols_) {
    //     swap(row1, row2);
    //     row1 += 1;
    //     row2 += 1;
    //     k += 1;
    // }
}

