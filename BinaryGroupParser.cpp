#include <vector>
#include <iostream>

using namespace std;

struct fragment{
  int beginIndex;
  int endIndex;
  int size;
};
int main(int argc, char const *argv[]) {
  /* code */


  int arr[32] = {0,1,1,1,1,0,0,0,
                 1,1,1,0,0,0,0,0,
                 1,1,0,1,0,0,0,1,
                 0,0,0,0,0,1,1,1};

  vector<fragment> fragList;

  int count = 0;
  int freeCount = 0;
  int memCount =0;
  int begin = 0;
  int end = 0;
  int size = 0;


  while(count < 32){
    while(count < 32 && arr[count] == 0) {count++;}
    if(count < 32)
    begin = count;
    while(count < 32 && arr[count] ==1){ count++;}
    end = count - 1;
    size = end - begin;
    fragment temp = {begin, end, size};
    fragList.push_back(temp);
  }
  int i = 0;
  while(i < fragList.size()){
  cout << "Beginning Index: "<<fragList[i].beginIndex << " ";
  cout << "End Index: " <<fragList[i++].endIndex << endl;
}
  return 0;
}
