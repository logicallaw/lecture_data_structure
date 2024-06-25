#include <iostream>
#include <vector>
using namespace std;
struct Node{
    int data;
    Node* parent;
    vector<Node*> childList;
    Node(int data, Node* parent){
        this->data = data;
        this->parent = parent;
    }
};

class Tree{
private:
    Node* root;
    vector<Node*> nodeList;
    int find(int data, vector<Node*>& List);
public:
    Tree(int data);
    void insertNode(int parData, int data);
    void deleteNode(int data);
    void printParent(int data);
    void printChild(int data);
};

Tree::Tree(int data){
    root = new Node(data, NULL);
    nodeList.push_back(root);
}

int Tree::find(int data, vector<Node*>& List){
    for(int i = 0; i < List.size(); i++){
        if(List[i]->data == data){
            return i;
        }
    }
    return -1;
}

void Tree::insertNode(int parData, int data){
    if(find(data, nodeList) != -1){
        return;
    }
    int idx = find(parData, nodeList);
    if(idx == -1){
        return;
    }
    Node* parNode = nodeList[idx];
    Node* newNode = new Node(data, parNode);
    parNode->childList.push_back(newNode);
    nodeList.push_back(newNode);
}

void Tree::deleteNode(int data){
    int idx = find(data, nodeList);
    if(idx == -1){
        return;
    }
    Node* delNode = nodeList[idx];
    if(delNode == root){
        return;
    }
    Node* parNode = delNode->parent;
    for(int i = 0; i < delNode->childList.size(); i++){
        parNode->childList.push_back(delNode->childList[i]);
        delNode->childList[i]->parent = parNode;
    }

    vector<Node*>& child = parNode->childList;
    child.erase(child.begin() + find(data, child));
    nodeList.erase(nodeList.begin() + idx);
    delete delNode;
}

void Tree::printParent(int data){
    int idx = find(data, nodeList);
    if(idx <= 0){
        return;
    }
    Node* curNode = nodeList[idx];
    cout << curNode->parent->data << endl;
}

void Tree::printChild(int data) {
    int idx = find(data, nodeList);
    if(idx == -1){
        return;
    }
    vector<Node*>& child = nodeList[idx]->childList;
    if(child.empty()){
        return;
    }
    for(int i = 0; i < child.size(); i++){
        cout << child[i]->data << " ";
    }
    cout << endl;
}