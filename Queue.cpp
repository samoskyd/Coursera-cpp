#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

void WORRY(vector<bool>& people, int i);
void QUIET(vector<bool>& people, int i);
void COME(vector<bool>& people, int k);
int WORRY_COUNT(const vector<bool>& people);

int main()
{
  vector<bool> people(0, false); //вектор нашої черги
  vector<int> amount; //вектор, в який будуть додаватись числа від наших команд
  amount.push_back(0); //заповнюємо перше місце сміттям, оскільки воно не буде задіяне
  vector<string> operations; //вектор, в який будуть додаватись наші команди
  string buffer = "";
  do
  {
    getline(cin, buffer);
    if (buffer.size() > 0)
    {
      operations.push_back(buffer);//всі команди йдуть в вектор
      int z;
      char temp_el;
      string temp1, temp2;
      if (buffer.size() >= 6)
      {
      for (int i = 1; buffer[buffer.size() - i] != ' ' && buffer[buffer.size() - i] != 'T'; i++)
      { //
        temp_el = buffer[buffer.size() - i];
        temp1.push_back(temp_el);
      }
      for(int j = 0; j < temp1.size(); j++)
      {
        temp2.push_back(temp1[temp1.size() - 1 - j]);
      }
      z = atoi(temp2.c_str()); //
      amount.push_back(z);
      }
    }
  }
  while (buffer != "");

  string p;
  for(int i = 1; i < operations.size(); i++)
  {
    p = operations[i];
    if (p[0] == 'C' && p[1] == 'O' && p[2] == 'M' && p[3] == 'E') COME(people, amount[i]);
    else if (p[0] == 'W' && p[1] == 'O' && p[2] == 'R' && p[3] == 'R' && p[4] == 'Y' && p[6] == 'C')
     {
      int count;
      count = WORRY_COUNT(people);
      cout << count << endl;
    }
    else if (p[0] == 'Q' && p[1] == 'U' && p[2] == 'I' && p[3] == 'E' && p[4] == 'T') QUIET(people, amount[i]);
    else if (p[0] == 'W' && p[1] == 'O' && p[2] == 'R' && p[3] == 'R' && p[4] == 'Y') WORRY(people, amount[i]);
  }
  return 0;
}

void WORRY(vector<bool>& people, int i)
{
  people[i] = true;
}

void QUIET(vector<bool>& people, int i)
{
  people[i] = false;
}

void COME(vector<bool>& people, int k)
{
  int w = people.size();
  if (k >= 0) people.resize(w + k);
  else
    for(int j = 0; j > k; j--) people.pop_back();
}

int WORRY_COUNT(const vector<bool>& people)
{
  int cunt = 0;
  for (auto q : people)
  {
    if (q == true) cunt++;
  }
  return cunt;
}
