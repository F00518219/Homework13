#include "BinaryTree.hpp"
#include <stdlib.h>
#include <iostream>

using namespace std;

BinaryTree::BinaryTree()
{
    this->isEmpty = true;
    this->leftChild = NULL;
    this->rightChild = NULL;
    this->count = 0;
}

BinaryTree::BinaryTree(int payload)
{
    BinaryTree(); //initially create an empty tree

    //make it not empty
    this->isEmpty = false;
    this->payload = payload;
    this->count = 1;
}

void BinaryTree::visitInOrder()
{
    if(!this->isEmpty)
    {
        if(this->leftChild) //visit left
        {
            this->leftChild->visitInOrder();
        }
        cout << this->payload << " "; //visit self
        if(this->rightChild)
        {
            this->rightChild->visitInOrder(); //visit right
        }
    }
    
}

void BinaryTree::visitPreOrder()
{
    cout << this->payload << " "; //visits self
    if(!this->isEmpty) //visits left
    {
      if(this->leftChild)
      {
        this->leftChild->visitInOrder();

      }
      if(this->rightChild)
      {
        this->rightChild->visitInOrder(); //visits right

      }
    }
}

void BinaryTree::visitPostOrder()
{
    if(!this->isEmpty) //visits left
    {
      if(this->leftChild)
      {
        this->leftChild->visitInOrder();

      }
      if(this->rightChild)
      {
        this->rightChild->visitInOrder(); //visits right

      }
    }
    cout << this->payload << " "; //visits self
}

int BinaryTree::getCount()
{
    return this->count;
}
int BinaryTree::getPayload()
{
  return this->payload;
}


void BinaryTree::add(int payload)
{
    // if(!this->root)
    if(this->isEmpty)
    {
        this->payload = payload;
        this->isEmpty = false; //no longer empty
    }
    else if(payload <= this->payload)// we need to add to the left
    {
        if(this->leftChild && payload <=  this->leftChild->payload)
        {
          //ask the leftChild to add this value
          this->leftChild->add(payload);
        }
        else
        {
            //create a left child with this payload
            this->leftChild = new BinaryTree(payload);
            this->count++;
        }
    }
    else //we need to add to the right
    {
      if(this->rightChild)
      {
        //ask the rightChild to add this value
        this->rightChild->add(payload);
      }
      else
      {
        //create a right child with this payload
        this->leftChild = new BinaryTree(payload);
        this->count++;
      }
    }
}
