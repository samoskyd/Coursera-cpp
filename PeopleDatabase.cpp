#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

/*
for(auto item : history)
{
  if(item.second.second == temp_surname &&)
}
*/

using namespace std;

//map<string, int> counter;
int counter = 0;

bool TwoInRow(string previous_name, string name)
{
  if (previous_name == name) 
  {
    return false;
  }
  return true;
}

int count(const vector<string>& v, string el)
{
  int count = 0;
  for(auto i : v)
  {
    if(i == el) count++;
  }
  return count;
}

string FindNameByYear(const map<int, string>& names, int year) 
{
  string name;
  for (const auto& item : names) 
  {
    if (item.first <= year) name = item.second;
    else break;
  }
  return name;
}

class Person 
{
public:
  void ChangeFirstName(int year, const string& first_name) 
  {
    first_names[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) 
  {
    last_names[year] = last_name;
  }
  string GetFullName(int year) 
  {
    const string first_name = FindNameByYear(first_names, year);
    const string last_name = FindNameByYear(last_names, year);
  
    if (first_name.empty() && last_name.empty()) return "Incognito";
    else if (first_name.empty()) return last_name + " with unknown first name";
    else if (last_name.empty()) return first_name + " with unknown last name";
    else return first_name + " " + last_name;
  }
  string GetFullNameWithHistory(int year) 
  {
    string previous_name = "";

    const string first_name = FindNameByYear(first_names, year); int countf = 0;
    const string last_name = FindNameByYear(last_names, year); int countl = 0;

    vector<string> history_first, history_last;
    for(auto i : first_names)
    {
      if (count(history_first, i.second) == 0 && i.first < year)
      {
        history_first.push_back(i.second);
      }
    }
    for(auto i : last_names)
    {
      if (count(history_last, i.second) == 0 && i.first < year)
      {
        history_last.push_back(i.second);
      }
    }

    if (!history_first.empty())
    {
      if (history_first[history_first.size() - 1] == first_name) history_first.pop_back();
    }
    
    if (!history_last.empty())
    {
      if (history_last[history_last.size() - 1] == last_name) history_last.pop_back();
    }
    
    string history_f = "", history_l = "";

    if (!history_first.empty())
    {
      history_f = " (";
      for(int i = 0; i < history_first.size(); i++)
      {
        string p = history_first[history_first.size() - i - 1];
        history_f += p;
        history_f += ", ";
      }
      history_f.pop_back();
      history_f.pop_back();
      history_f += ")";
    }
    if (!history_last.empty())
    {
      history_l = " (";
      for(int i = 0; i < history_last.size(); i++)
      {
        string p = history_last[history_last.size() - i - 1];
        history_l += p;
        history_l += ", ";
      }
      history_l.pop_back();
      history_l.pop_back();
      history_l += ")";
    }
  
    if (first_name.empty() && last_name.empty()) return "Incognito";
    else if (first_name.empty()) return last_name + history_l + " with unknown first name";
    else if (last_name.empty()) return first_name + history_f + " with unknown last name";
    else return first_name + history_f + " " + last_name + history_l;
  }

private:
  map<int, string> first_names;
  map<int, string> last_names;
};

int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;
  
  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;
  
  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;
  
  return 0;
}