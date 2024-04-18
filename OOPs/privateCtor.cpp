#include<iostream>
using namespace std;

class Box{
    int width;
    Box(int _w):width(_w){}

    public:
        
        int getWidth() const{
            return width;
        }

        void setWidth(int val){
            width=val;
        }

        friend class BoxFactory;
};

class BoxFactory{
    int count;
    public:
        Box getBoxWidth(int _w){
            count++;
            return Box(_w);
        }
};

int main(){
    BoxFactory bfact;
    Box b=bfact.getBoxWidth(10);
    cout<<b.getWidth()<<endl;
}
