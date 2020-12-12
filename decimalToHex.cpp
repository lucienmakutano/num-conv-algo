#include <iostream>
#include <string>

using namespace std;

const float HEXRADIX = 16.0;

string decimalToHex(int, float);
string *split_(string str);
string digitToCorrespondingHexVal(int num);

int main()
{

  cout << decimalToHex(10, HEXRADIX) << endl;

  return 0;
}

string decimalToHex(int decNum, float radix)
{
  string res;

  while (decNum > 0)
  {
    float temp_res = decNum / radix;
    string str_temp_res = to_string(temp_res);
    string *whole_and_dec_num = split_(str_temp_res);
    int remainder = radix * stof(whole_and_dec_num[1]);
    string hexVal = digitToCorrespondingHexVal(remainder);

    res = hexVal + res;
    decNum = int(temp_res);
  }

  return res;
}

string *split_(string str)
{
  string *res = new string[2];
  string dec = "0";
  string wholen;

  for (int i = 0; i < str.length(); i++)
  {
    if (str[0] == '.')
      break;

    wholen.push_back(str[0]);
    str = str.substr(1);
  }

  for (int i = 0; i < str.length(); i++)
  {
    dec += str[i];
  }

  res[0] = wholen;
  res[1] = dec;

  return res;
}

string digitToCorrespondingHexVal(int num)
{
  switch (num)
  {
  case 10:
    return "A";
  case 11:
    return "B";
  case 12:
    return "C";
  case 13:
    return "D";
  case 14:
    return "E";
  case 15:
    return "F";
  default:
    return to_string(num);
  }
}
