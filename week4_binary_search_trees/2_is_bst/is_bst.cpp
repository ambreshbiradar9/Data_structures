#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

 void in_(vector<int> &result,int i,const vector<Node>& tree)
  {
    if (tree[i].left!=-1)
    {
      in_(result,tree[i].left,tree);
    }
    result.push_back(tree[i].key);
    if(tree[i].right!=-1)
    {
      in_(result,tree[i].right,tree);
    }
  }

bool IsBinarySearchTree(const vector<Node>& tree) 
{
  // Implement correct algorithm here
vector<int> result;
in_(result,0,tree);

if(result.size()==1)
{
  return true;
}

for(int i=0;i<result.size()-1;i++)
{
  if(result[i]>result[i+1])
    {
      return false;
    }
}
  return true;
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
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
