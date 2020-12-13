#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

string *split_(string);
string *decimalToBinary(float);
float random_float(float, float);
string convertWholeNumber(int);
string *convertDecimalPoint(float);

int main()
{
  srand(time(NULL));
  int count = 0;

  cout << endl
       << "Lucien Tatyana Quincy Eric"
       << endl
       << endl;

  cout << "S/No."
       << "\t\t"
       << "Decimal Number"
       << "\t"
       << "Binary Number"
       << "\t\t"
       << "Remarks"
       << endl;

  while (count < 30)
  {
    float randNum = random_float(1.001f, 1000.999f);
    string *res = decimalToBinary(randNum);
    string binRepresentation = res[0] + "." + res[1];
    cout << count
         << "\t\t"
         << randNum
         << "\t\t"
         << binRepresentation
         << "\t\t"
         << res[2]
         << endl;

    count++;
  }

  return 0;
}

float random_float(float min, float max)
{

  return ((float)rand() / RAND_MAX) * (max - min) + min;
}

string *decimalToBinary(float num)
{
  string *decimalPointResult;
  string wholeNumberResult;

  string *numbers = split_(to_string(num));

  if (stoi(numbers[2]) == 2)
  {
    decimalPointResult = convertDecimalPoint(stof(numbers[1]));
  }

  wholeNumberResult = convertWholeNumber(stoi(numbers[0]));

  decimalPointResult[0] = wholeNumberResult;
  return decimalPointResult;
}

string convertWholeNumber(int wholeNum)
{
  string res;

  while (wholeNum > 0)
  {
    if (wholeNum % 2 == 0)
    {
      res = "0" + res;
    }
    else
    {
      res = "1" + res;
    }

    wholeNum = wholeNum / 2;
  }

  return res;
}

string *convertDecimalPoint(float floatNum)
{
  string *res = new string[3];
  string result;
  string flag;
  int counter = 0;
  string *p = split_(to_string(floatNum));
  int length = stoi(p[2]);

  while (length == 2 && counter < 5)
  {
    float temp_res = floatNum * 2;
    string *arr = split_(to_string(temp_res));
    result += arr[0];
    floatNum = temp_res - stoi(arr[0]);
    length = stoi(arr[2]);
    counter++;
  }

  if (counter < 5)
  {
    flag = "Exactly";
  }
  else
  {
    flag = "Approximate";
  }

  res[1] = result;
  res[2] = flag;

  return res;
}

string *split_(string str)
{
  string *res = new string[3];
  string dec = "0";
  string wholen;
  int length = 1;

  for (int i = 0; i < str.length(); i++)
  {
    if (str[0] == '.')
    {
      length++;
      break;
    }

    wholen.push_back(str[0]);
    str = str.substr(1);
  }

  for (int i = 0; i < str.length(); i++)
  {
    dec += str[i];
  }

  res[0] = wholen;
  res[1] = dec;
  res[2] = to_string(length);

  return res;
}
