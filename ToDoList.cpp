#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;
void Add(vector<string>& todo, string s, int i);
void Dump(const vector<string>& todo, int i);
void Next(vector<string>& todo);

int count = 1;

int main()
{
  int q;
  cin >> q;
  vector<string> tasks(31);

  for (int i = 0; i < q; ++i) 
  {
    string operation_code;
    cin >> operation_code;

    if (operation_code == "NEXT") 
    {
      Next(tasks);
    } 
    else 
    {
      if (operation_code == "DUMP") 
      {
        int temp;
        cin >> temp;
        Dump(tasks, temp);
      } 
      else if (operation_code == "ADD") {
        int tt;
        cin >> tt;
        string t;
        cin >> t;
        Add(tasks, t, tt);
      }
    }
  }
  return 0;
}

void Add(vector<string>& todo, string s, int i)
{
  todo[i] += " ";
  todo[i] += s;
}

void Dump(const vector<string>& todo, int i)
{
  cout << todo[i] << endl;
}

void Next(vector<string>& todo)
{
  switch(count)
  {
  case 0: 
  {
    vector<string> n_tasks(31);
    if (todo <= n_tasks)
    {
      todo.resize(n_tasks.size());
    }
    if (todo > n_tasks)
    { 
      for (int j = 0; j < todo.size() - n_tasks.size(); j++)
      {
        todo[n_tasks.size() - 1] += " ";
        todo[n_tasks.size() - 1] += todo[todo.size() - j - 1];
      }
    }
  }
  case 1: 
  {
    vector<string> n_tasks(28);
    if (todo <= n_tasks)
    {
      todo.resize(n_tasks.size());
    }
    if (todo > n_tasks)
    { 
      for (int j = 0; j < todo.size() - n_tasks.size(); j++)
      {
        todo[n_tasks.size() - 1] += " ";
        todo[n_tasks.size() - 1] += todo[todo.size() - j - 1];
      }
    }
  }
  case 2: 
  {
    vector<string> n_tasks(31);
    if (todo <= n_tasks)
    {
      todo.resize(n_tasks.size());
    }
    if (todo > n_tasks)
    { 
      for (int j = 0; j < todo.size() - n_tasks.size(); j++)
      {
        todo[n_tasks.size() - 1] += " ";
        todo[n_tasks.size() - 1] += todo[todo.size() - j - 1];
      }
    }
  }
  case 3: 
  {
    vector<string> n_tasks(30);
    if (todo <= n_tasks)
    {
      todo.resize(n_tasks.size());
    }
    if (todo > n_tasks)
    { 
      for (int j = 0; j < todo.size() - n_tasks.size(); j++)
      {
        todo[n_tasks.size() - 1] += " ";
        todo[n_tasks.size() - 1] += todo[todo.size() - j - 1];
      }
    }
  }
  case 4:
  { 
    vector<string> n_tasks(31);
    if (todo <= n_tasks)
    {
      todo.resize(n_tasks.size());
    }
    if (todo > n_tasks)
    { 
      for (int j = 0; j < todo.size() - n_tasks.size(); j++)
      {
        todo[n_tasks.size() - 1] += " ";
        todo[n_tasks.size() - 1] += todo[todo.size() - j - 1];
      }
    }
  }
  case 5:
  {
    vector<string> n_tasks(30);
    if (todo <= n_tasks)
    {
      todo.resize(n_tasks.size());
    }
    if (todo > n_tasks)
    { 
      for (int j = 0; j < todo.size() - n_tasks.size(); j++)
      {
        todo[n_tasks.size() - 1] += " ";
        todo[n_tasks.size() - 1] += todo[todo.size() - j - 1];
      }
    }
  } 
  case 6:
  {
    vector<string> n_tasks(31);
    if (todo <= n_tasks)
    {
      todo.resize(n_tasks.size());
    }
    if (todo > n_tasks)
    { 
      for (int j = 0; j < todo.size() - n_tasks.size(); j++)
      {
        todo[n_tasks.size() - 1] += " ";
        todo[n_tasks.size() - 1] += todo[todo.size() - j - 1];
      }
    }
  } 
  case 7:
  {
    vector<string> n_tasks(31);
    if (todo <= n_tasks)
    {
      todo.resize(n_tasks.size());
    }
    if (todo > n_tasks)
    { 
      for (int j = 0; j < todo.size() - n_tasks.size(); j++)
      {
        todo[n_tasks.size() - 1] += " ";
        todo[n_tasks.size() - 1] += todo[todo.size() - j - 1];
      }
    }
  } 
  case 8:
  {
    vector<string> n_tasks(30);
    if (todo <= n_tasks)
    {
      todo.resize(n_tasks.size());
    }
    if (todo > n_tasks)
    { 
      for (int j = 0; j < todo.size() - n_tasks.size(); j++)
      {
        todo[n_tasks.size() - 1] += " ";
        todo[n_tasks.size() - 1] += todo[todo.size() - j - 1];
      }
    }
  } 
  case 9:
  {
    vector<string> n_tasks(31);
    if (todo <= n_tasks)
    {
      todo.resize(n_tasks.size());
    }
    if (todo > n_tasks)
    { 
      for (int j = 0; j < todo.size() - n_tasks.size(); j++)
      {
        todo[n_tasks.size() - 1] += " ";
        todo[n_tasks.size() - 1] += todo[todo.size() - j - 1];
      }
    }
  } 
  case 10: 
  {
    vector<string> n_tasks(30);
    if (todo <= n_tasks)
    {
      todo.resize(n_tasks.size());
    }
    if (todo > n_tasks)
    { 
      for (int j = 0; j < todo.size() - n_tasks.size(); j++)
      {
        todo[n_tasks.size() - 1] += " ";
        todo[n_tasks.size() - 1] += todo[todo.size() - j - 1];
      }
    }
  }
  case 11:
  {
    vector<string> n_tasks(31);
    if (todo <= n_tasks)
    {
      todo.resize(n_tasks.size());
    }
    if (todo > n_tasks)
    { 
      for (int j = 0; j < todo.size() - n_tasks.size(); j++)
      {
        todo[n_tasks.size() - 1] += " ";
        todo[n_tasks.size() - 1] += todo[todo.size() - j - 1];
      }
    }
    count = -1;
  }
  }
  count++;
}