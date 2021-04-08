#include <iostream>
#include "BinaryTree.hpp"

using namespace std;

int main(int argc, char** argv)
{
  BinaryTree* bt = new BinaryTree();
  bt->add(5);
  bt->add(3);
  bt->add(4);
  bt->add(7);
  bt->add(13);
  cout << bt->getCount() << endl;
  bt->visitInOrder();
  return 0;
}
