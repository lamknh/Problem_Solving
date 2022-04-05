#include<iostream>
#include<stack>

using namespace std;

int tmp=1;
int result=0;
bool check=false;
stack<char> s;

int main(){
   string str;
   cin >> str;
   
   for(int i=0;i<str.length();i++){
      if(str[i]=='('){ //(일때 
         s.push(str[i]);
         tmp*=2;
      } else if(str[i]==')'&& !s.empty() && s.top()=='('){ //)이고 스택맨위가 (일때
         s.pop();
         if(str[i-1]=='('){ //바로전이 (이었을때 
            result+=tmp;
         }
         tmp/=2;
      } else if(str[i]=='['){ //[일때 
         s.push(str[i]);
         tmp*=3;
      } else if(str[i]==']'&& !s.empty() && s.top()=='['){ //]이고 스택맨위가 [일때 
         s.pop();
         if(str[i-1]=='['){ //바로전이 [이었을때 
            result+=tmp;
         }
         tmp/=3;
      } else{ //해당안되면 오류 
         check=true;
         break;
      }
   }

   if(s.empty()&&!check)
      cout << result;
   else
      cout << "0";
      
   return 0;
}