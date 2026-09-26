/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// AC but suboptimal, O(1) space possible with interleaving
class Solution {
public:
  // this so trivial with a map...
  // is this a real medium question?
  // old -> new
  unordered_map<Node *, Node *> mm;
  Node *getNode(Node *curr) {
    if (curr == nullptr)
      return nullptr;
    if (mm.find(curr) != mm.end()) {
      return mm[curr];
    } else {
      mm[curr] = new Node(curr->val);
      return mm[curr];
    }
  }

  Node *copyRandomList(Node *head) {
    Node *curr = head;
    Node *newHead = new Node(-1);
    Node *newCurr = newHead;
    while (curr != nullptr) {
      newCurr->next = getNode(curr);
      newCurr = newCurr->next;
      newCurr->next = getNode(curr->next);
      newCurr->random = getNode(curr->random);
      curr = curr->next;
    }

    return newHead->next;
  }
};
