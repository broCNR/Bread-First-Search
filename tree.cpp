#include <iostream>
#include <queue>
using namespace std;

class Node {
    public:
        char data;
        Node* left;
        Node* right;

    Node(char value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
    private:
        Node* root;
    
    public:
        BinaryTree() {
            root = nullptr;
        }

        void setRoot(Node* e) {
            root = e;
        }

        Node* getRoot() {
            return root;
        }

        void bfs() {
            if (root == nullptr) {
                return;
            }

            queue<Node*> q;
            q.push(root);

            while (!q.empty()) {
                Node* current = q.front();
                q.pop();

                cout << current->data << " ";

                if (current->left != nullptr) {
                    q.push(current->left);
                }
                if (current->right != nullptr) {
                    q.push(current->right);
                }
            }
        }
};

int main() {
    Node* root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C');
    root->left->left = new Node('D');
    root->left->right = new Node('E');

    BinaryTree tree;
    tree.setRoot(root);

    cout << "BFS traversal: ";
    tree.bfs();
    cout << endl;

    return 0;

    // Tree:
    //         A
    //       /   \
    //      B     C
    //     / \
    //    D   E
}