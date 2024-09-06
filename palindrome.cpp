/*
Palindrome checker created in C++
Author: Ayan Masud
Date: 9/4/2024
 */

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
  //char a = 'a';
  //char z = 'z';
  //char A = 'A';
  //char Z = 'Z';

  //cout << int(a) << " " << int(z) << " " << int(A) << " " << int(Z) << endl;
  
  char str[80];
  cin.get(str, 80);

  int charLength = strlen(str);
  char str2[charLength]; // set it to the length of str without any nulls

  int newCharLength = 0;
  for(int i = 0; i < charLength; i++) // removes anything but letters and puts it in str2
  {
    if(str[i] >= 97 && str[i] <= 122 // lowercase letters
       || str[i] >= 65 && str[i] <= 90) // uppercase letters
    {
      str2[newCharLength] = str[i]; // removes all the empty space/null characters in str
      newCharLength++; // this is increased to determine what the final character array amount will be (without nulls, spaces, and punctuation)
    }
  }
  
  char str3[newCharLength]; // set to the length of str2 without any nulls
  for(int i = 0; i < newCharLength; i++)
  {
    str3[i] = str2[i]; // removes the null characters made from removing everything but letters
  }

  bool isPalindrome = true;
  int compareEnd = newCharLength - 1;
  for(int i = 0; i < newCharLength; i++)
  {
    if(str3[i] == str3[compareEnd]) // compares the first char with the last char and checks inward
    {
      compareEnd -= 1;
    }
    else
    {
      isPalindrome = false; // if it wasn't the same, this is not a palindrome
      break;
    }
  }

  if(isPalindrome == true)
  {
    cout << "Palindrome." << endl;
  }
  else
  {
    cout << "Not a palindrome." << endl;
  }
  
  return 0;
}
