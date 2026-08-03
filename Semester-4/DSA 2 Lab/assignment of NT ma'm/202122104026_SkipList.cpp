/*
Complexity Analysis:

1. Highest Possible Level:
   - The highest level in a skip list is log(n) due to the decreasing probability of higher levels as nodes are inserted.

2. Time Complexity:
   - Search: O(log n) on average, as multiple levels allow skipping nodes.
   - Insert: O(log n) on average, to find the correct position and update pointers.
   - Delete: O(log n) on average, similar to insert.

3. Space Complexity:
   - O(n log n) on average, due to multiple levels in each node, requiring more space than a regular linked list.

Comparison with Other Data Structures:
--------------------------------------

| Data Structure | Space Complexity | Comparison with Skip List |
|----------------|------------------|---------------------------|
| Skip List      | O(n log n)        | Efficient for fast operations, but uses more space. |
| Linked List    | O(n)              | Uses less space but slower for search, insert, and delete. |
| Balanced BST   | O(n)              | Uses less space but is more complex and slower in some cases. |
| Hash Table     | O(n)              | O(1) lookups, but no ordered data support. |
| Array          | O(n)              | Space-efficient but slow for dynamic operations. |
*/


#include <bits/stdc++.h>
using namespace std;

template <typename T>
class SkipList
{
private:
    struct Element
    {
        T value;
        vector<Element*> next;

        Element(T val, int level) : value(val), next(level + 1, nullptr) {}
    };

    const int MAX_DEPTH;
    const float PROBABILITY;
    int current_depth;
    Element* head;
    mt19937 rand_generator;
    uniform_real_distribution<float> rand_distribution;

public:
    SkipList(int max_depth = 16, float prob = 0.5)
        : MAX_DEPTH(max_depth), PROBABILITY(prob), current_depth(0),
          rand_generator(std::random_device{}()), rand_distribution(0.0, 1.0)
    {
        head = new Element(std::numeric_limits<T>::min(), MAX_DEPTH);
    }

    ~SkipList()
    {
        Element* current_node = head->next[0];
        while (current_node)
        {
            Element* temp = current_node;
            current_node = current_node->next[0];
            delete temp;
        }
        delete head;
    }

    int generate_random_level()
    {
        int level = 0;
        while (rand_distribution(rand_generator) < PROBABILITY && level < MAX_DEPTH)
            level++;
        return level;
    }

    void insert(T value)
    {
        vector<Element*> update(MAX_DEPTH + 1, nullptr);
        Element* current_node = head;

        for (int i = current_depth; i >= 0; i--)
        {
            while (current_node->next[i] && current_node->next[i]->value < value)
                current_node = current_node->next[i];
            update[i] = current_node;
        }

        current_node = current_node->next[0];

        if (!current_node || current_node->value != value)
        {
            int new_level = generate_random_level();
            if (new_level > current_depth)
            {
                for (int i = current_depth + 1; i <= new_level; i++)
                    update[i] = head;
                current_depth = new_level;
            }

            Element* new_element = new Element(value, new_level);
            for (int i = 0; i <= new_level; i++)
            {
                new_element->next[i] = update[i]->next[i];
                update[i]->next[i] = new_element;
            }
        }
    }

    bool search(T value) const
    {
        Element* current_node = head;
        for (int i = current_depth; i >= 0; i--)
        {
            while (current_node->next[i] && current_node->next[i]->value < value)
                current_node = current_node->next[i];
        }
        current_node = current_node->next[0];
        return current_node && current_node->value == value;
    }

    void remove(T value)
    {
        vector<Element*> update(MAX_DEPTH + 1, nullptr);
        Element* current_node = head;

        for (int i = current_depth; i >= 0; i--)
        {
            while (current_node->next[i] && current_node->next[i]->value < value)
                current_node = current_node->next[i];
            update[i] = current_node;
        }

        current_node = current_node->next[0];

        if (current_node && current_node->value == value)
        {
            for (int i = 0; i <= current_depth; i++)
            {
                if (update[i]->next[i] != current_node) break;
                update[i]->next[i] = current_node->next[i];
            }
            delete current_node;

            while (current_depth > 0 && !head->next[current_depth])
                current_depth--;
        }
    }

    void display() const
    {
        for (int i = 0; i <= current_depth; i++)
        {
            Element* current_node = head->next[i];
            cout << "Level " << i << ": ";
            while (current_node)
            {
                cout << current_node->value << " ";
                current_node = current_node->next[i];
            }
            cout << endl;
        }
    }
};

int main()
{
    SkipList<int> list;

    list.insert(12);
    list.insert(9);
    list.insert(7);
    list.insert(3);
    list.insert(19);
    list.insert(6);

    cout << "Skip List after insertions:\n";
    list.display();

    cout << "\nSearch for 7: " << (list.search(7) ? "Found" : "Not found") << endl;
    cout << "Search for 15: " << (list.search(15) ? "Found" : "Not found") << endl;

    list.remove(6);
    cout << "\nSkip List after deletion of 6 and the final tree:\n";
    list.display();

    return 0;
}
