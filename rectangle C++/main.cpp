#include <iostream>

using namespace std;

class rectangle
{
public:
    void printS();
    void printC();
    void printW();
    void printL();
//    void setAB(int a,int b);
    rectangle(int width,int length);
    rectangle();
private:
    int width;
    int length;

};

void rectangle::printW()
{
    cout<<"Width:"<<width<<endl;
}

void rectangle::printL()
{
    cout<<"Length:"<<length<<endl;
}

rectangle::rectangle()
{

}

rectangle::rectangle(int a,int b)
{
    width=a;
    length=b;
}

void rectangle::printS()
{
    int s=width*length;
    cout<<"Area:"<<s<<endl;
}

void rectangle::printC()
{
    int c=2*(width+length);
    cout<<"Perimeter:"<<c<<endl;
}

int main()
{

    int a,b;
    cin>>a>>b;
    rectangle test(a,b);
//    test.setAB(a,b);
    test.printW();
    test.printL();
    test.printS();
    test.printC();
    return 0;
}
