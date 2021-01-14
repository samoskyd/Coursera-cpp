#include <iostream>
#include <exception>
#include <cmath>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <stdlib.h>

using namespace std;

class Date 
{
  public:

    Date()
    {
      year = 0;
      month = 0;
      day = 0;
    }

    Date(int a, int b, int c)
    {
      year = a;
      month = b;
      day = c;
    }

    int GetYear() const
    {
      int value = year;
      return value;
    }

    int GetMonth() const
    {
      int value = month;
      return value;
    }

    int GetDay() const
    {
      int value = day;
      return value;
    }

  private:

    int year;
    int month;
    int day;
};

bool operator<(const Date& lhs, const Date& rhs)
{
  if(lhs.GetYear() < rhs.GetYear()) return true;
  else if(lhs.GetYear() == rhs.GetYear())
  {
    if (lhs.GetMonth() < rhs.GetMonth()) return true;
  }
  else if(lhs.GetMonth() == rhs.GetMonth())
  {
    if (lhs.GetDay() < rhs.GetDay()) return true;
  }
  return  false;
}

bool operator>(const Date& lhs, const Date& rhs)
{
  if(lhs.GetYear() > rhs.GetYear()) return true;
  else if(lhs.GetYear() == rhs.GetYear())
  {
    if (lhs.GetMonth() > rhs.GetMonth()) return true;
  }
  else if(lhs.GetMonth() == rhs.GetMonth())
  {
    if (lhs.GetDay() > rhs.GetDay()) return true;
  }
  return  false;
}

bool operator==(const Date& lhs, const Date& rhs)
{
  if(lhs.GetYear() == rhs.GetYear())
  {
    if(lhs.GetMonth() == rhs.GetMonth())
    {
      if (lhs.GetDay() == rhs.GetDay()) return true;
    }
  }
  return  false;
}

ostream& operator<<(ostream& stream, const Date& date)
{
  stream << setfill('0');
  stream << setprecision(4) << date.GetYear() << "-" << setprecision(2) << date.GetMonth() << "-" << setprecision(2) << date.GetDay();
  return stream;
}

istream& operator>>(istream& stream, Date& obj)
{
  int a = -1, b = -1, c = -1;
  string aa, bb, cc;
  string err_text = "";
  try
  {
    getline(stream, cc, '-');
    getline(stream, bb, '-');
    getline(stream, aa);

    err_text = "Wrong date formate: " + aa + "-" + bb + "-" + cc;

    a = stoi(aa.c_str());
    b = stoi(bb.c_str());
    c = stoi(cc.c_str());
  }
  catch (exception& ex)
  {
    throw runtime_error(err_text);
  }
  
  string error_m = "Month value is invalid: " + bb;
  string error_d = "Day value is invalid: " + aa;

  if (b < 1 || b > 12) throw runtime_error(error_m);
  if (a < 1 || a > 31) throw runtime_error(error_d);

  Date result(c, b, a);
  obj = result;
  return stream;
}

class Database 
{
public:
  void AddEvent(const Date& date, const string& event)
  {
    bool flag = true;
    pair temp(date, event);
    for (auto i : base)
    {
      if (i.first == temp.first && i.second == temp.second) flag = false;
    }
    if (flag) base.insert(temp);
    flag = true;
  }

  void DeleteEvent(const Date& date, const string& event)
  {
    bool flag = true;
    for (auto i : base)
    {
      if (i.first == date && i.second == event)
      {
        base.erase(date);
        cout << "Deleted successfully" << endl;
        flag = false;
        break;
      }
    }
    if(flag) cout << "Event not found" << endl;
  }

  void DeleteDate(const Date& date)
  {
    int del_ev_count = 0;
    for (auto i : base)
    {
      if (i.first == date)
      {
        base.erase(date);
        del_ev_count++;
      }
    }
    cout << "Deleted " << del_ev_count << " events" << endl;
  }

  void Find(const Date& date) const
  {
    vector<string> events;
    for (auto i : base)
    {
      if (i.first == date)
      {
        events.push_back(i.second);
      }
    }
    sort(begin(events), end(events));
    for (auto i : events) cout << i << endl;
  }
  
  void Print() const
  {
    for (auto i : base)
    {
      cout << i.first << " " << i.second << endl;
    }
  }

private:
  multimap<Date, string> base;
};

int main()
{
  Database db;
  string command;
  while (getline(cin, command)) 
  {
    if (command == "") continue;
    try
    {
      stringstream stream(command);
      string com;
      stream >> com;
      if (com == "Find") 
      {
        Date date;
        stream >> date;        
        db.Find(date);
        continue;
      }
      else if (com == "Del") 
      {
        Date date;
        stream >> date;
        string event;
        stream >> event;
        if (event != "") db.DeleteEvent(date, event);
        else db.DeleteDate(date);
        continue;
      }
      else if (com == "Print")
      {
        db.Print();
        continue;
      }
      else if (com == "Add") 
      {
        Date date;
        stream >> date;
        string event;
        stream >> event;
        db.AddEvent(date, event);
        continue;
      }
      else throw runtime_error("");
    }
    catch(runtime_error& err)
    {
      cout << "Unknown command: " << command << endl;
    }
  }
  return 0;
}