#include<bits/stdc++.h>
#include<stack>
using namespace std;

int main()
{
    stack<int> s;  // stack declaration in stl

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    cout<<"size of stack "<<s.size()<<endl;
    cout<<"top element "<<s.top()<<endl;

    while (s.empty()==false)
    {
       cout<<s.top()<<endl;
       s.pop();
    }
    
    return 0;
}