// C++ program to detect loop in a linked list
// using hashset
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        this->data = x;
        this->next = nullptr;
    }
};

// Function that returns true if there is a loop in linked
// list else returns false.
bool detectLoop(Node* head) {
    unordered_set<Node*>st;

    // loop that runs till the head is nullptr
    while (head != nullptr) {

        // If this node is already present
        // in hashmap it means there is a cycle
        // (Because you will be encountering the
        // node for the second time).
        if (st.find(head) != st.end())
            return true;

        // If we are seeing the node for
        // the first time, insert it in hash
        st.insert(head);

        head = head->next;
    }
    return false;
}

int main() {

    // Create a hard-coded linked list:
    // 10 -> 20 -> 30 -> 40 -> 50 -> 60
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);
    
    head->next->next->next->next = head;

    if (detectLoop(head))
        cout << "true";
    else
        cout << "false";

    return 0;
}
