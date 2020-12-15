#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

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
    float randNum = random_float(1.01f, 1000.99f);
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
  string *res;
  string wholeNumberResult;

  int int_part = num;
  float fract_part = num - int_part;

  if (fract_part)
  {
    res = convertDecimalPoint(fract_part);
  }

  wholeNumberResult = convertWholeNumber(int_part);

  res[0] = wholeNumberResult;
  return res;
}

string convertWholeNumber(int wholeNum)
{
  string res;

  if (wholeNum == 0)
  {
    res = "0" + res;
  }

  while (wholeNum > 0)
  {
    int rem = wholeNum % 2;
    res = to_string(rem) + res;
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
  float temp_res = 0;

  while (temp_res != 1 && counter < 5)
  {
    temp_res = floatNum * 2;
    int int_part = temp_res;
    result += to_string(int_part);
    floatNum = temp_res - int_part;
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
