#include "HW5.h"

/* I started this problem by identifying the base case as if the counter has
 * reached the end of the word. If the counter has reached the end of the word,
 * it checks if the childs value is $ to indicate that the word is valid. Then
 * for the recursive case, I check whether the current variable is equal to the
 * current child. If it is not, all the children will all be checked because the
 * if statement is encompassed by a for loop that iterates through all of the
 * children of the current root. If the child equals the variable then the
 * counter is increased and the function returns the child as the new root. The
 * function recursively calls until all the letters in the word are checked or
 * there are no more children in the dictionary that correlate to the current
 * letter. The worst-case time complexity would be O(n) where n is the number of
 * letters in the dictionary. This would happen if the word is the far right so
 * every child would have to be checked at each level. I think the best case
 * would be O(1) because if the word is the first word in the dictionary then
 * the function would only recursively call m number of times where m is the
 * size of the word. The average case would be log(n) with a space complexity of
 * o(m) because the recursive call stack would be the size of the word.
 *
 */

bool isValidWord(TreeNode<char> *dict, std::string word) {
  static int i = 0;

  for (auto child : dict->getChildren()) {
    if (i == word.length()) {
      if (child->getValue() == '$') {
        i = 0;
        return true;
      } else {
        i = 0;
        return false;
      }
    } else if (child->getValue() == word[i]) {
      i++;
      return isValidWord(child, word);
    }
  }
  i = 0;
  return false;
}

/* With a little help from Nick and Gozie I began this problem with identifying
 * the base case. The base case calls the isValidWord function to see if the
 * word already exists or not. The second base case checks if the word length is
 * equal to the counter variable i. If this case is true then a $ sign is pushed
 * back onto the tree and returns true. If the base cases are not true then the
 * for loop is entered that iterates through all of the children of the current
 * root node. If the current child equals to the letter in the word than the
 * child is returned and the iterator is increased by one.  If that cas is not
 * true then the missing letter is pushed onto the tree and the back value of
 * the vector which contains the missing letter is returned.
 *
 */
bool addWord(TreeNode<char> *dict, std::string word) {

  static int i = 0;
  if (isValidWord(dict, word)) {
    return false;
  }
  if (word.length() == i) {
    i = 0;
    dict->getChildren().push_back(new TreeNode<char>('$'));
    return true;
  }

  for (auto child : dict->getChildren()) {
    if (child->getValue() == word[i]) {
      i++;
      return addWord(child, word);
    }
    }

    dict->getChildren().push_back(new TreeNode<char>(word[i]));
    i++;
    return addWord(dict->getChildren().back(), word);
  
}
