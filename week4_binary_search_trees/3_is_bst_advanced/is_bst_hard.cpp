#include <algorithm>
#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

bool temp=true;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

 void in_(vector<int> &result,int i,const vector<Node>& tree,long long int min,long long int max)
  {
    if((!(min<=tree[i].key))||(!(max>tree[i].key)))
    {
      temp=false;
    }
    
    
    if (tree[i].left!=-1)
    {
      in_(result,tree[i].left,tree,min,tree[i].key);
    }
    result.push_back(tree[i].key);
    if(tree[i].right!=-1)
    {
      in_(result,tree[i].right,tree,tree[i].key,max);
    }
  }

bool IsBinarySearchTree(const vector<Node>& tree) 
{
  // Implement correct algorithm here
  long long int max=pow(2,31)+1,min=-pow(2,31)+1-1;
  vector<int> result;
  in_(result,0,tree,min,max);
  return temp;
}

int main() {
  int nodes;
  cin >> nodes;
  if(nodes==0)
  {
    cout << "CORRECT" << endl;
    return 0;
  }
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if(nodes==1)
  {
    cout << "CORRECT" << endl;
    return 0;
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
