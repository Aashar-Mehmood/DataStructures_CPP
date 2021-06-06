// reversing a string using stack data structure
#include <cstdlib>
#include <iostream>
#include <string>
#include <stack> //stack from standard template library STL
using namespace std;

void reversePrint(string str, int length);
int main(){
 string myStr = "Hello World";
 reversePrint(myStr, myStr.length());
}
void reversePrint(string str, int length){
  stack<char> s;
  for(int i=0; i<length; i++){
    s.push(str[i]);
  }
  for(int i=0; i<length; i++){
    str[i] = s.top();
    s.pop();
  }
  cout<<str;
}
