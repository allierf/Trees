#include <iostream>

#include "TreeNode.h"
#include "ExtraCreditHW5.h"

TreeNode<char>* makeTrieExample() {
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
            new TreeNode('$')})})})});
}

TreeNode<int>* makeQ1Example1() {
  return new TreeNode<int>(1);
}

TreeNode<int>* makeQ1Example2() {
  return new TreeNode<int>(1, {
    new TreeNode<int>(2, {
      new TreeNode<int>(3, {
        new TreeNode<int>(6)})}),
    new TreeNode<int>(4, {
      new TreeNode<int>(5)})});
}

TreeNode<int>* makeQ1Example3() {
  return new TreeNode<int>(1, {
      new TreeNode<int>(2, {
        new TreeNode<int>(4)}),
      new TreeNode<int>(3, {
        new TreeNode<int>(5, {
          new TreeNode<int>(7),
          new TreeNode<int>(8),}),
        new TreeNode<int>(6)})});
}

TreeNode<int>* makeQ1Example4() {
  return new TreeNode<int>(1, {
    new TreeNode<int>(2, {
      new TreeNode<int>(3, {
        new TreeNode<int>(5),
        new TreeNode<int>(6)}),
      new TreeNode<int>(4, {
        new TreeNode<int>(7)})})});
}


int main() {

  // Q4 examples
  std::cout << "Q4.A" << std::endl;
  TreeNode<char>* dict = makeTrieExample();
  std::cout << suggestWordV1(dict, "actors") << std::endl;  // "actor"
  std::cout << suggestWordV1(dict, "acting") << std::endl;  // ""

  // Q5 examples
  std::cout << "Q5" << std::endl;

  TreeNode<int>* q1Ex1 = makeQ1Example1();
  std::cout << findTreeDiameter(q1Ex1) << std::endl; // 0
  freeTree(q1Ex1);

  TreeNode<int>* q1Ex2 = makeQ1Example2();
  std::cout << findTreeDiameter(q1Ex2) << std::endl; // 5
  freeTree(q1Ex2);

  TreeNode<int>* q1Ex3 = makeQ1Example3();
  std::cout << findTreeDiameter(q1Ex3) << std::endl;  // 5
  freeTree(q1Ex3);

  TreeNode<int>* q1Ex4 = makeQ1Example4();
  std::cout << findTreeDiameter(q1Ex4) << std::endl;  // 4
  freeTree(q1Ex4);

}