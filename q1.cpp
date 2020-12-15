#include <iostream>
#include <string>

using namespace std;

const float HEXRADIX = 16.0;
const float OCTRADIX = 8.0;

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
    int rem = decNum % 2;
    res = to_string(rem) + res;
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
    int int_part = temp_res;
    float fract_part = temp_res - int_part;
    int remainder = radix * fract_part;
    string hexVal = digitToCorrespondingHexVal(remainder);

    res = hexVal + res;
    decNum = int_part;
  }

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
