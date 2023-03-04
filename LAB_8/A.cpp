#include <iostream>
#include <vector>

struct Node{
  int mama = -1;
  int lkid = -1;
  int rkid = -1;
  int data;
};
struct Node_char{
  int mama = -1;
  int lkid = -1;
  int rkid = -1;
  char data;
};

std::vector <char> result_c;
std::vector <int> result;


struct Tree_digits{
  std::vector<Node*> tree;

  Tree_digits(){
    tree.push_back(nullptr);
  }
  int root = 1;
  int size = 1;

  void add(int x){
    Node *new_node = new Node;
    new_node->data = x;
    if(size == 1){
      new_node->mama = -1;
    }
    else if(size % 2 == 0){
      tree[size / 2]->lkid = tree.size();
      new_node->mama=size/2;
    }
    else{
      tree[(size-1) / 2]->rkid = tree.size();
      new_node->mama = (size-1)/2;
    }
    tree.push_back(new_node);
    size++;
  }

  void change(int x){
    if(x == root){
      return;
    }

    int mama = tree[x] -> mama;
    int ded = tree[mama] -> mama;
    int left_kid = tree[x] ->lkid;
    int right_kid = tree[x] -> rkid;

    if(mama == root){
      root = x;
    }

    if(mama > 0) {
      if(ded <= 0){
        tree[x]->mama = -1;
      }
      else {
        if (tree[ded]->lkid == mama) {
          tree[ded]->lkid = x;
          tree[x]->mama = ded;
        } else {
          tree[ded]->rkid = x;
          tree[x]->mama = ded;
        }
      }
    }

    if(tree[mama] -> lkid == x){
      tree[x] -> lkid = mama;
      tree[mama] -> mama = x;
      tree[mama] -> lkid = left_kid;
      if(left_kid != -1){
        tree[left_kid]->mama = mama;
      }
    }
    else if(tree[mama] -> rkid == x) {
      tree[x]->rkid = mama;
      tree[mama]->mama = x;
      tree[mama]->rkid = right_kid;
      if (right_kid != -1) {
        tree[right_kid]->mama = mama;
      }
    }

  }
    void printPostorder(int x)
    {
      if (tree[x]->lkid!=-1) {
        printPostorder(tree[x]->lkid);
      }
      if (tree[x]->rkid!=-1) {
        printPostorder(tree[x]->rkid);
      }
      result.push_back(tree[x] -> data);
    }
};

struct Tree_symbols{
  std::vector <Node_char*> tree;

  Tree_symbols(){
    tree.push_back(nullptr);
  }
  int root = 1;
  int size = 1;

  void add(char x){
    Node_char *new_node = new Node_char;
    new_node->data = x;
    if(size == 1){
      new_node->mama = -1;
    }
    else if(size % 2 == 0){
      tree[size / 2]->lkid = tree.size();
      new_node->mama=size/2;
    }
    else{
      tree[(size-1) / 2]->rkid = tree.size();
      new_node->mama = (size-1)/2;
    }
    tree.push_back(new_node);
    size++;

  }
  void change(int x){
    if(x == root){
      return;
    }

    int mama = tree[x] -> mama;
    int ded = tree[mama] -> mama;
    int left_kid = tree[x] ->lkid;
    int right_kid = tree[x] -> rkid;

    if(mama == root){
      root = x;
    }

    if(mama > 0) {
      if(ded <= 0){
        tree[x]->mama = -1;
      }
      else {
        if (tree[ded]->lkid == mama) {
          tree[ded]->lkid = x;
          tree[x]->mama = ded;
        } else {
          tree[ded]->rkid = x;
          tree[x]->mama = ded;
        }
      }
    }

    if(tree[mama] -> lkid == x){
      tree[x] -> lkid = mama;
      tree[mama] -> mama = x;
      tree[mama] -> lkid = left_kid;
      if(left_kid != -1){
        tree[left_kid]->mama = mama;
      }
    }
    else if(tree[mama] -> rkid == x){
      tree[x] -> rkid = mama;
      tree[mama] -> mama = x;
      tree[mama] -> rkid = right_kid;
      if(right_kid != -1){
        tree[right_kid]->mama = mama;
      }
    }

  }
    void printPostorder(int x)
    {
      if (tree[x]->lkid!=-1) {
        printPostorder(tree[x]->lkid);
      }
      if (tree[x]->rkid!=-1) {
        printPostorder(tree[x]->rkid);
      }
      result_c.push_back(tree[x] -> data);
    }
};

int main(){
  Tree_digits Tdig;
  Tree_symbols Tsym;
  int N,Q1,Q2,k;
  char s;
  std::cin >> N >> Q1;
  for(int i = 0;i < N;i++){
    std::cin >> k;
    Tdig.add(k);
  }
  for(int i = 0;i < Q1;i++){
    std::cin >> k;
    Tdig.change(k);
  }
  std::cin >> N >> Q2;
  for(int i = 0;i < N;i++){
    std::cin >> s;
    Tsym.add(s);
  }
  for(int i = 0;i < Q2;i++){
    std::cin >> k;
    Tsym.change(k);
  }
  Tdig.printPostorder(Tdig.root);
  Tsym.printPostorder(Tsym.root);

  for(int i = 0;i < N;i++){
    for(int j = 0;j < result[i];j++){
      std::cout << result_c[i];
    }
  }
}
