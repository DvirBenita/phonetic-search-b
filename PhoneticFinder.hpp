#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <exception>

using namespace std;
namespace phonetic{
   string find(string text,string word);
   string lowCase(string toLowCase);
   void split(vector<string> &elements,const string &text);
   bool  checkProprietry(string s);
   bool match(string element, string word);
   size_t split(const string &txt, vector<string> &strs, char ch);
}