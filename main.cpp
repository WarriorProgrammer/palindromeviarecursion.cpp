#include <iostream>
using namespace std;

bool isPalindrome(string str);
bool isStringPalindrome(string str, int first, int last);
bool recIsStringPalindrome(string str, int first, int last);

bool isPalindrome(string str) {
	return recIsStringPalindrome(str, 0, str.length() - 1);
}

bool recIsStringPalindrome(string str, int first, int last) {
	// checks if the string only has one letter, if it does it returns true. if not it moves on to the else function
	if (str.length() == 1)
		return true;

	if (first >= last)
		return true;
	// a) Check if first and last character are the same or not
	if (str[first] != str[last])
		return false;
	// c) call the parent function recursively to
	//   continue tracking first and last string chars.
	return recIsStringPalindrome(str, first + 1, last - 1);
}

bool isStringPalindrome(string str, int first, int last) {
  //setting up a comparison between the first and last
	int i;
	int j;
	bool isPalindrome = true;
	for (i = first, j = last; i <= last / 2; i++, j--) { // going through
		if (i == j) {
			isPalindrome = true;
			break;
			//Check if first and last character are the same 
		} else if (str[i] != str[j]) {
			isPalindrome = false;
			break;
		}
	}
	//call the parent function recursively to
	//   continue tracking first and last string chars.
	return isPalindrome;
}

int main() {
	string str;
	cout << "Enter a string: ";
	getline(cin, str);
	cout << endl;

	if (isPalindrome(str))
		cout << str << " IS a palindrome(via recursion)" << endl;
	else
		cout << str << " IS NOT a palindrome(via recursion)" << endl;
	return 0;
}
