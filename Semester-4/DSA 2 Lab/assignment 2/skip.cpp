#include <bits/stdc++.h>
using namespace std;
template <typename T>
class FastLane{
private:
    struct Element{
        T data;
        vector<Element*> next;
        Element(T val,int level):data(val),next(level+1,NULL){}
    };
    const int MAX_HEIGHT;
    const float CHANCE;
    int current_height;
    Element* head;
    mt19937 rng;
    uniform_real_distribution<float> random_gen;
public:
    FastLane(int max_height=16,float chance=0.5):MAX_HEIGHT(max_height),CHANCE(chance),current_height(0),rng(std::random_device{}()),random_gen(0.0,1.0){
        head=new Element(std::numeric_limits<T>::min(),MAX_HEIGHT);
    }
    ~FastLane(){
        Element* node=head->next[0];
        while(node){
            Element* tmp=node;
            node=node->next[0];
            delete tmp;
        }
        delete head;
    }
    int generate_random_height(){
        int level=0;
        while(random_gen(rng)<CHANCE&&level<MAX_HEIGHT)
            level++;
        return level;
    }
    void add(const T& value){
        vector<Element*> update(MAX_HEIGHT+1,NULL);
        Element* current=head;
        for(int i=current_height;i>=0;i--){
            while(current->next[i]&&current->next[i]->data<value)
                current=current->next[i];
            update[i]=current;
        }
        current=current->next[0];
        if(!current||current->data!=value){
            int new_height=generate_random_height();
            if(new_height>current_height){
                for(int i=current_height+1;i<=new_height;i++)
                    update[i]=head;
                current_height=new_height;
            }
            Element* new_element=new Element(value,new_height);
            for(int i=0;i<=new_height;i++){
                new_element->next[i]=update[i]->next[i];
                update[i]->next[i]=new_element;
            }
        }
    }
    bool find(const T& value)const{
        Element* current=head;
        for(int i=current_height;i>=0;i--){
            while(current->next[i]&&current->next[i]->data<value)
                current=current->next[i];
        }
        current=current->next[0];
        return current&&current->data==value;
    }
    void erase(const T& value){
        vector<Element*> update(MAX_HEIGHT+1,NULL);
        Element* current=head;
        for(int i=current_height;i>=0;i--){
            while(current->next[i]&&current->next[i]->data<value)
                current=current->next[i];
            update[i]=current;
        }
        current=current->next[0];
        if(current&&current->data==value){
            for(int i=0;i<=current_height;i++){
                if(update[i]->next[i]!=current)break;
                update[i]->next[i]=current->next[i];
            }
            delete current;
            while(current_height>0&&!head->next[current_height])
                current_height--;
        }
    }
    void show()const{
        for(int i=0;i<=current_height;i++){
            Element* node=head->next[i];
            cout<<"Level "<<i<<": ";
            while(node){
                cout<<node->data<<" ";
                node=node->next[i];
            }
            cout<<"\n";
        }
    }
};
int main(){
    FastLane<int> fastLane;
    fastLane.add(4);
    fastLane.add(8);
    fastLane.add(15);
    fastLane.add(16);
    fastLane.add(23);
    fastLane.add(42);
    cout<<"After adding elements:\n";
    fastLane.show();
    cout<<endl;
    cout<<"Searching 15: "<<(fastLane.find(15)?"Found":"Not Found");
    cout<<endl;
    cout<<"Searching 25: "<<(fastLane.find(25)?"Found":"Not Found");
    fastLane.erase(8);
    cout<<endl<<endl;
    cout<<"After removing 8:\n";
    fastLane.show();
    return 0;
}
