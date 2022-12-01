#include <iostream>
#include <vector>
#include <assert.h>
#include <string>

int scoreOfParentheses(std::string s) {
  if (s == "") {
    return 0;
  } else if (s == "()") {
    return 1;
  } else {
    int curr_open = 1;
    size_t curr_pos = 0;
    while ((curr_open >= 1) && (curr_pos < s.size()-1)) {
      curr_pos += 1;
      if (s[curr_pos] == '(') {
        curr_open += 1;
      } else {
        curr_open -= 1;
      }
    }
    int result = 0;
    if (curr_pos >= 2) {
      result += 2*scoreOfParentheses(s.substr(1, curr_pos-1));
    } else {
      result += 1;
    }
    if (curr_pos <= s.size()-2) {
      result += scoreOfParentheses(s.substr(curr_pos+1));
    }
    // std::cout << "For " << s << " results is " << result << std::endl;
    return result;
  }
}

int main(int argc, char* argv[]) {

  assert (scoreOfParentheses("()") == 1);
  assert (scoreOfParentheses("(())") == 2);
  assert (scoreOfParentheses("()()") == 2);
  assert (scoreOfParentheses("(()())") == 4);
  assert (scoreOfParentheses("(()())()") == 5);

  return 1;
}
