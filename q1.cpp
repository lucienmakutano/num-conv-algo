#include <iostream>
#include <string>

using namespace std;

const float HEXRADIX = 16.0;
const float OCTRADIX = 8.0;

string *split_(string);
string decimalToBinary(int);
string decimalToHexOROct(int, float);
string digitToCorrespondingHexVal(int);

int main()
{
  int decNums[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 31, 100, 255, 256};
  int arrSize = sizeof(decNums) / sizeof(decNums[0]);

  cout << endl
       << "Lucien Tatyana Quincy Eric"
       << endl
       << endl;

  cout << "Decimal"
       << "\t\t"
       << "Binary"
       << "\t\t"
       << "Hexadecimal"
       << "\t"
       << "Octal(bonus)"
       << endl;

  for (int i = 0; i < arrSize; i++)
  {

    cout << decNums[i]
         << "\t\t"
         << decimalToBinary(decNums[i])
         << "\t\t"
         << decimalToHexOROct(decNums[i], HEXRADIX)
         << "\t\t"
         << decimalToHexOROct(decNums[i], OCTRADIX)
         << endl;
  }

  return 0;
}

string decimalToBinary(int decNum)
{
  string res;

  if (decNum == 0)
  {
    res = "0" + res;
  }

  while (decNum > 0)
  {
    if (decNum % 2 == 0)
    {
      res = "0" + res;
    }
    else
    {
      res = "1" + res;
    }

    decNum = decNum / 2;
  }

  return res;
}

string decimalToHexOROct(int decNum, float radix)
{
  string res;

  if (decNum == 0)
  {
    res = "0" + res;
  }

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
