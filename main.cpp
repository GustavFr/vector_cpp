#include <iostream>

using namespace std;


template<typename T>
class vector{
public:
    struct node{
        T data;
        node *next = nullptr;
    };

    node *root = nullptr;
    node *current = nullptr;
    unsigned size = 0;

    void push(T data){
        if(root == nullptr){
            root = new node;
            root->data = data;
            current = root;
        }else{
            current->next = new node;
            current->next->data = data;
            current = current->next;
        }
        size++;
    }

    T& operator [](const unsigned index){
        node* c0 = root;
        for(unsigned i = 0; i < index; ++i) c0 = c0->next;
        return c0->data;
    }
};

int main()
{
    vector<int> mas;
    for(int i = 0; i < 1000; ++i){
        mas.push(i*i);
    }

    for(int i = 0; i < mas.size; ++i){
        cout << "Элемент № " << i  << " = " << mas[i] << endl;
    }
    cout << "Размер вектора: " << mas.size << endl;
    return 0;
}
