#include<bits/stdc++.h>
#include<stack>
using namespace std;
int arr[6],n=6,top=-1;

void push(int y)
{
  if(top>=n-1)
    cout<<"overflow";
  else
   {
       top++;
       arr[top]=y;
       cout<<"value is pushed "<<arr[top]<<endl;
   }  
}

void pop()
{
  if(top<=-1)
    cout<<"undreflow";
  else
  {
      cout<<"poped element is "<<arr[top]<<endl;
      top--;
  }    
}

void display()
{
  if(top<=-1)
   cout<<"underflow";
  else
  {
      for (int i = top; i>=0;i--)
      {
          cout<<arr[top];
      }
      
  }   
}

int main()
{   
    int x,y;
    cout<<"choose below"<<endl;
    cout<<"1.push the element"<<endl;
    cout<<"2.pop the element"<<endl;
    cout<<"3.display the element"<<endl;

    while (x!=4)
    {
       cout<<"\n enter a choise"<<endl;
       cin>>x;
     switch (x)
     {
     case 1:
        { cout<<"enter value to be pushed"<<endl;
          cin>>y;
          push(y); 
         break;
        }
     case 2:
        pop();
        break;
     case 3:
        display();  
        break; 
     default:
        cout<<"enter valid expresion";
         break;
     }
    }
    return 0;

}

