/*
Complexity Analysis:
 1. Highest Possible Level: The highest possible level in a skip list is log(n) where n is the number of elements.
    This is because the levels are determined by a coin flip, and the probability decreases exponentially.
 2. Time Complexity:
    - Search: O(log n) on average, as it traverses levels and skips nodes.
    - Insert: O(log n) on average, as it needs to find the correct position and update pointers.
    - Delete: O(log n) on average, similar to insert.
 3. Space Complexity: O(n log n) on average, as each node can have multiple levels.

Data Structure  Space Complexity    Comparison with Skip List
Skip List       O(n log n)          Efficient for dynamic operations but uses more space due to multiple levels.
Linked List     O(n)                Uses less space than a Skip List but lacks efficient search, insert, and delete operations.
Balanced BST    O(n)                Uses less space than a Skip List but requires complex balancing mechanisms.
Hash Table      O(n)                Uses less space and provides O(1) average-time operations but lacks ordered traversal.
Array           O(n)                Uses less space but is inefficient for dynamic operations like insertions and deletions.

*/


#include <bits/stdc++.h>
using namespace std;

template <typename T>
class SkipList
{
private:
    struct Node
    {
        T value;
        vector<Node*> forward;

        Node(T val, int level) : value(val), forward(level + 1, nullptr) {}
    };

    const int MAX_LEVEL;
    const float PROBABILITY;
    int current_level;
    Node* head;
    mt19937 generator;
    uniform_real_distribution<float> distribution;

public:
    SkipList(int max_level = 16, float prob = 0.5)
        : MAX_LEVEL(max_level), PROBABILITY(prob), current_level(0),
          generator(std::random_device{}()), distribution(0.0, 1.0)
    {
        head = new Node(std::numeric_limits<T>::min(), MAX_LEVEL);
    }

    ~SkipList()
    {
        Node* node = head->forward[0];
        while (node)
        {
            Node* temp = node;
            node = node->forward[0];
            delete temp;
        }
        delete head;
    }

    int random_level()
    {
        int level = 0;
        while (distribution(generator) < PROBABILITY && level < MAX_LEVEL)
            level++;
        return level;
    }

    void insert(const T& value)
    {
        std::vector<Node*> update(MAX_LEVEL + 1, nullptr);
        Node* current = head;

        for (int i = current_level; i >= 0; i--)
        {
            while (current->forward[i] && current->forward[i]->value < value)
                current = current->forward[i];
            update[i] = current;
        }

        current = current->forward[0];

        if (!current || current->value != value)
        {
            int new_level = random_level();
            if (new_level > current_level)
            {
                for (int i = current_level + 1; i <= new_level; i++)
                    update[i] = head;
                current_level = new_level;
            }

            Node* new_node = new Node(value, new_level);
            for (int i = 0; i <= new_level; i++)
            {
                new_node->forward[i] = update[i]->forward[i];
                update[i]->forward[i] = new_node;
            }
        }
    }

    bool search(const T& value) const
    {
        Node* current = head;
        for (int i = current_level; i >= 0; i--)
        {
            while (current->forward[i] && current->forward[i]->value < value)
                current = current->forward[i];
        }
        current = current->forward[0];
        return current && current->value == value;
    }

    void remove(const T& value)
    {
        std::vector<Node*> update(MAX_LEVEL + 1, nullptr);
        Node* current = head;

        for (int i = current_level; i >= 0; i--)
        {
            while (current->forward[i] && current->forward[i]->value < value)
                current = current->forward[i];
            update[i] = current;
        }

        current = current->forward[0];

        if (current && current->value == value)
        {
            for (int i = 0; i <= current_level; i++)
            {
                if (update[i]->forward[i] != current) break;
                update[i]->forward[i] = current->forward[i];
            }
            delete current;

            while (current_level > 0 && !head->forward[current_level])
                current_level--;
        }
    }

    void print()const
    {
        for (int i = 0; i <= current_level; i++)
        {
            Node* node = head->forward[i];
            cout << "Level " << i << ": ";
            while (node)
            {
                cout << node->value << " ";
                node = node->forward[i];
            }
            cout << "\n";
        }
    }
};

int main()
{
    SkipList<int> skipList;

    skipList.insert(3);
    skipList.insert(6);
    skipList.insert(7);
    skipList.insert(9);
    skipList.insert(12);
    skipList.insert(19);

    cout << "Skip List after insertions:\n";
    skipList.print();

    cout << "\nSearch for 7: " << (skipList.search(7) ? "Found" : "Not found");
    cout << "\nSearch for 15: " << (skipList.search(15) ? "Found" : "Not found");

    skipList.remove(6);
    cout << "\n\nSkip List after deletion of 6:\n";
    skipList.print();
    cout<<"\nFinally the list will be: \n";
    skipList.print();

    return 0;
}
