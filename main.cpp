#include <iostream>

#include "TreeNode.h"
#include "HW5.h"

TreeNode<char>* makeTrieExample1() {
    return new TreeNode<char>(
      '*', {
        new TreeNode<char>('a', {
          new TreeNode<char>('c', {
            new TreeNode<char>('e', {
              new TreeNode<char>('$')}),
            new TreeNode<char>('i', {
              new TreeNode<char>('d', {
                new TreeNode<char>('$')})}),
            new TreeNode<char>('t', {
              new TreeNode<char>('$'),
              new TreeNode<char>('o', {
                new TreeNode<char>('r', {
                  new TreeNode<char>('$')})})})})}),
        new TreeNode<char>('b', {
          new TreeNode<char>('e', {
            new TreeNode<char>('$'),
            new TreeNode<char>('a', {
              new TreeNode<char>('r', {
                new TreeNode<char>('$')}),
              new TreeNode<char>('t', {
                new TreeNode<char>('$')})})})}),
        new TreeNode<char>('c', {
          new TreeNode<char>('a', {
            new TreeNode<char>('b', {
              new TreeNode<char>('$')})}),
          new TreeNode<char>('o', {
            new TreeNode<char>('b', {
              new TreeNode<char>('$')})})})});
}

int main() {
  {  // Q1
    std::cout << "Q1" << std::endl;
    TreeNode<char>* dict1 = makeTrieExample1();
    std::cout << isValidWord(dict1, "ace") << std::endl;  // 1
    std::cout << isValidWord(dict1, "ac") << std::endl;  // 0
    std::cout << isValidWord(dict1, "actor") << std::endl;  // 1
    std::cout << isValidWord(dict1, "actors") << std::endl;  // 0
    freeTree(dict1);  
  }
  {  // Q2
    std::cout << "Q2" << std::endl;
    TreeNode<char>* dict1 = makeTrieExample1();
    std::cout << isValidWord(dict1, "aces") << std::endl;  // 0
    std::cout << addWord(dict1, "aces") << std::endl;  // 1
    std::cout << isValidWord(dict1, "aces") << std::endl;  // 1
    std::cout << addWord(dict1, "aces") << std::endl;  // 0, already added
    freeTree(dict1);
  }
}