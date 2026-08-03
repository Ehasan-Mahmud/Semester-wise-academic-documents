void insert(int x){
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
