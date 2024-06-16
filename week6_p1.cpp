#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct node{
    int data;
    node* parent;
    vector<node*> childList;
    node(int data, node* parent){
        this->data = data;
        this->parent = parent;
    }
};
class Tree{
private:
    node* root;
    vector<node*> nodeList;
    int find(int data, vector<node*>& List){
        for(int i = 0; i < List.size(); i++){
            if(List[i]->data == data){
                return i;
            }
        }
        return -1;
    }
public:
    Tree(int data){
        root = new node(data, NULL);
        nodeList.push_back(root);
    }
    void insert(int data, int parData){
        if(find(data, nodeList) != -1){
            cout << -1 << endl;
            return;
        }
        int idx = find(parData, nodeList);
        if(idx == -1){
            cout << -1 << endl;
            return;
        }
        node* parNode = nodeList[idx];
        node* newNode = new node(data, parNode);
        parNode->childList.push_back(newNode);
        nodeList.push_back(newNode);
    }
    void deleteNode(int data){
        int idx = find(data, nodeList);
        if(idx <= 0){
            cout << -1 << endl;
            return;
        }
        node* delNode = nodeList[idx];
        node* parNode = delNode->parent;
        for(int i = 0; i < delNode->childList.size(); i++){
            parNode->childList.push_back(delNode->childList[i]);
            delNode->childList[i]->parent = parNode;
        }
        vector<node*>& child = parNode->childList;
        child.erase(child.begin() + find(data, child));
        nodeList.erase(nodeList.begin() + find(data, nodeList));
        delete delNode;
    }
    int min_maxChild(int data){
        int idx = find(data, nodeList);
        if(idx == -1){
            return -1;
        }
        node* curNode = nodeList[idx];
        vector<node*>& child = curNode->childList;
        if(child.size() == 0){
            return 0;
        }
        else if (child.size() == 1){
            return child[0]->data;
        }
        else{
            int max = child[0]->data;
            int min = child[0]->data;
            for(int i{ 0 }; i < child.size(); i++){
                max = (max < child[i]->data) ? child[i]->data : max;
                min = (min > child[i]->data) ? child[i]->data : min;
            }
            return max + min;
        }
    }
    void printParent(int data){
        int idx = find(data, nodeList);
        if(idx <= 0){
            cout << "-1" << endl;
            return;
        }
        else {
            cout << nodeList[idx]->parent->data << endl;
            return;
        }
    }
    void printChild(int data){
        int idx = find(data, nodeList);
        if(idx == -1){
            return;
        }
        vector<node*>& child = nodeList[idx]->childList;
        if(child.size() == 0){
            return;
        }
        else {
            for(int i = 0; i < child.size(); i++){
                cout << child[i]->data << " ";
            }
            cout << endl;
        }
    }
};

int main(void){
    Tree tree{ 1 };
    int size;
    cin >> size;
    while(size > 1){
        size--;
        string userInput;
        if(userInput == "insert"){
            int x, y;
            cin >> x >> y;
            tree.insert(x,y);
        }
        else if (userInput == "delete"){
            int x;
            cin >> x;
            tree.deleteNode(x);
        }
        else if (userInput == "parent"){
            int x;
            cin >> x;
            tree.printParent(x);
        }
        else if (userInput == "child"){
            int x;
            cin >> x;
            tree.printChild(x);
        }
        else if (userInput == "min_maxChild"){
            int x;
            cin >> x;
            tree.min_maxChild(x);
        }
    }
}