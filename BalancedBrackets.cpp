#include <iostream>
#include <string>
#include <stack>


using namespace std;

bool MatchingPair(char left, char right){
  if(left == '(' && right ==')')
  {
    return true;
  }
  else if(left == '{' && right == '}')
  {
    return true;
  }
  else if(left == '[' && right == ']')
  {
    return true;
  }
  return false;
}

bool ArePairsBalanced(string input){
  stack<char> brackets;
  for(int i = 0; i <  input.length(); i++){
    //Has to pust the current element to the stack if it matches
    if(input[i] == '(' || input[i] == '[' || input[i] == '{'){
        brackets.push(input[i]);
    }
    else if(input[i] ==')' || input[i] == ']' || input[i] == '}'){
      if(brackets.empty() || !MatchingPair(brackets.top(), input[i])){
      return false;
      }
      else{
      brackets.pop();
      }
    }//else if
  }//for
  return brackets.empty() ? true:false;
}//func

int main(int argc, char const *argv[]) {

string s = "[";
bool match;



match = ArePairsBalanced(s);

if(match == false)
{
  cout << "Not Matching" << endl;
}
else{
  cout << "Matching" << endl;
}


  return 0;
}
