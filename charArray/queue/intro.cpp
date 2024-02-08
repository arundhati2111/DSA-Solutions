#include<iostream>
#include<queue>
using namespace std;

int main(){
    // creation
    queue<int> q;

    // insertion
    q.push(5);
    q.push(15);
    q.push(25);
    q.push(55);

    cout<<"Size is: "<<q.size()<<endl;

    // deletion
    q.pop();

    cout<<"Front: "<<q.front()<<endl;

}
