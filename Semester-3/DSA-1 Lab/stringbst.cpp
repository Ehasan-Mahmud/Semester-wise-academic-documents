#include<bits/stdc++.h>
using namespace std;
struct Node{
    char key;
    Node *left,*right,*parent;
    Node (char x){
        key=x;
        left=right=parent=NULL;

    }
};
struct BST{
    //private:
        int length;
    //public:
        Node*root;
        BST(){
            root = nullptr;
            length = 0;
        }
        void insert(char x){
            Node *temp = new Node(x);

            if(root == nullptr){
                root = temp;
                return;
            }

            Node *fast = root, *slow = nullptr;
            while(fast){
                slow = fast;
                if(x < fast->key) fast = fast->left;
                else fast = fast->right;
            }

            if(x < slow->key) slow->left = temp;
            else slow->right = temp;
            temp->parent = slow;
            length++;
        }

        void inOrder(Node* temp){
            if(temp == nullptr) return;
            inOrder(temp->left);
            cout << temp->key << " ";
            inOrder(temp->right);
        }

};

int main()
{
    struct BST st;
    char c;
    vector<char> name;
    name.push_back(c);
    st.insert(c);


}
