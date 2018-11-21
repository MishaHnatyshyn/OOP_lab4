#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

template <typename Type>
struct TreeLetter {
    Type data;
    TreeLetter() {
        leftChild = nullptr;
        rightChild = nullptr;
        parent = nullptr;
    };
    TreeLetter* parent;
    TreeLetter* leftChild;
    TreeLetter* rightChild;
};

template <typename Type>
class BinaryTree {
private:
    TreeLetter<Type> * root = nullptr;
public:
    void addLetter(Type data) {
        TreeLetter<Type>* letter = new TreeLetter<Type>();
        letter->data = data;
        TreeLetter<Type>* temp = nullptr;
        TreeLetter<Type>* current = this->root;

        while (current != nullptr) {
            temp = current;
            if (letter->data <= current->data) current = current->leftChild;
            else current = current->rightChild;
        }

        letter->parent = temp;
        if (temp == nullptr) {
            this->root = letter;
        }
        else if (letter->data <= temp->data) {
            temp->leftChild = letter;
        }
        else temp->rightChild = letter;
    }

    TreeLetter<Type> * getRoot() {
        return this->root;
    }
};


template <typename Type>
class UserArray{
private:
    int length;
    vector<Type> array;
    void returnIndex(Type* val, TreeLetter<Type> * curr, int*index){
        if (curr != nullptr) {
            if (curr->data == *val) return;
            returnIndex(val, curr->leftChild , index);
            *index += 1;
            returnIndex(val, curr->rightChild , index);
        }
    }
public:
public:

    ~UserArray(){}

    UserArray(int size){
        length = size;
        for (int i = 0; i < size; ++i) {
            Type newEl = i;
            array.push_back(newEl);
        }
    }

    UserArray(int size, vector<Type> userArray){
        length = size;
        array = userArray;
    }

    void display(){
        for (int i = 0; i < length; ++i) {
            cout << array[i] << "  ";
        }
    }

    int findIndex(Type val){
        BinaryTree<Type> tree;
        for (int i = 0; i < array.size(); i++) {
            tree.addLetter(array[i]);
        }
        int index = 0;
        returnIndex(&val, tree.getRoot(), &index);
        if (index == length){
            return -1;
        }
        return index;
    }
};

int main() {
    UserArray<int> test(5);
    test.display();
    cout << endl << "Index of element is: "<< test.findIndex(3);
    return 0;
}