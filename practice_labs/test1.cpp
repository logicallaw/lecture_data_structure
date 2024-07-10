#include <iostream>
using namespace std;
class Node{
private:
    int n;
};
int main(void) {
    Node** array = new Node*[5];
    array[1] = new Node;
    if(array[1] == NULL){
        cout << "HI" << endl;
    } else {
        cout << "NOt" << endl;
    }
}
