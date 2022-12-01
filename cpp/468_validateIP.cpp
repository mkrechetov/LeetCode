#include <iostream>
#include <vector>
#include <assert.h>
#include <string>

std::string validIPAddress(std::string queryIP) {

  std::size_t pos = 0;
  std::string token;
  std::vector<std::string> split;

  std::size_t find_dot = queryIP.find(".");
  std::size_t find_col = queryIP.find(":");
  std::string delimeter;
  if ((find_dot != std::string::npos) && (find_col != std::string::npos)) {
    return "Neither";
  } else if ((find_dot != std::string::npos) && (find_col == std::string::npos))  {
    delimeter = ".";
  } else if ((find_dot == std::string::npos) && (find_col != std::string::npos)) {
    delimeter = ":";
  } else {
    return "Neither";
  }


  while ((pos = queryIP.find(delimeter)) != std::string::npos) {
    if (pos == 0) {
      return "Neither";
    } else {
      token = queryIP.substr(0, pos);
      split.push_back(token);
      queryIP.erase(0, pos + 1);
    }
  }
  split.push_back(queryIP);

  if (split.size() == 4) {
    for (std::string el: split) {
      if ((el.size() > 3) || (el.size() == 0)) {
        return "Neither";
      } else {
        std::size_t non_digit = el.find_first_not_of("1234567890");
        if (non_digit != std::string::npos) {
          // std::cout << "Non-digits found!" << std::endl;
          return "Neither";
        } else {
          std::size_t first_non_zero = el.find_first_not_of("0");
          if (first_non_zero == std::string::npos) {
            if (el == "0") {
              // continue;
            } else {
              // std::cout << "Leading zeros found!" << std::endl;
              return "Neither";
            }
          } else if (first_non_zero == 0) {
            if (stoi(el) <= 255) {
              continue;
            } else {
              return "Neither";
            }
          } else {
            // std::cout << "Leading zeros found!" << std::endl;
            return "Neither";
          }
        }
      }
    }
    return "IPv4";

  } else if (split.size() == 8) {
    for (std::string el: split) {
      if ((el.size() > 4) || (el.size() == 0)) {
        return "Neither";
      } else {
        std::size_t non_hex = el.find_first_not_of("1234567890abcdefABCDEF");
        if (non_hex != std::string::npos) {
          return "Neither";
        } else {
          // continue;
        }
      }
      // continue
    }
    return "IPv6";
  } else {
    return "Neither";
  }
  return "Neither";
}

int main(int argc, char* argv[]) {

  assert (validIPAddress("172.16.254.1") == "IPv4");
  assert (validIPAddress("256.256.256.256") == "Neither");
  assert (validIPAddress("172.16.254.001") == "Neither");

  assert (validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334") == "IPv6");
  assert (validIPAddress("2001:0db8:85a3:0000:0000:8a2e:0370:7334") == "IPv6");
  assert (validIPAddress("2001:db8:85a3:0:0:8A2E:0370:7334") == "IPv6");
  assert (validIPAddress("2001:0db8:85a3::8A2E:037j:7334") == "Neither");
  assert (validIPAddress("02001:0db8:85a3:0000:0000:8a2e:0370:7334") == "Neither");

  assert (validIPAddress("2001:0db8:85a3:00000:0:8A2E:0370:7334") == "Neither");
  assert (validIPAddress("2001:db8:85a3:0::8a2E:0370:7334") == "Neither");

  return 1;
}
