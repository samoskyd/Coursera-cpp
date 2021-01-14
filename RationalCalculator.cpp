#include <iostream>
#include <exception>
#include <cmath>

using namespace std;

class Rational 
{
  public:
    Rational() 
    {
      num = 0;
      den = 1;
    }

    Rational(int numerator, int denominator) 
    {
      if (denominator == 0) throw invalid_argument("Invalid argument");
      if ((numerator > 0 && denominator < 0) || (numerator < 0 && denominator < 0))
      {
        numerator *= -1;
        denominator *= -1;
      }
      if (numerator == 0) denominator = 1;
      else if (GCD(numerator, denominator) != 1)
      {
        int gcd = GCD(fabs(numerator), denominator);
        numerator /= gcd;
        denominator /= gcd;
      }
      num = numerator;
      den = denominator;
    }

    int Numerator() const 
    {
      return num;
    }

    int Denominator() const 
    {
      return den;
    }

  private:
    long num;
    long den;
    long GCD(long a, long b) 
    {
      while (a > 0 && b > 0) 
      {
        if (a > b) a %= b;
        else b %= a;
      }
      return a + b;
    }
};

bool operator==(const Rational& fobj, const Rational& sobj)
{
  if (fobj.Denominator() == sobj.Denominator() && fobj.Numerator() == sobj.Numerator()) return true;
  else return false;
}

Rational operator+(const Rational& fobj, const Rational& sobj)
{
  if (fobj.Denominator() != sobj.Denominator())
  {
    int temp1 = fobj.Denominator(), temp2 = sobj.Denominator();
    Rational result(fobj.Numerator()*temp2 + sobj.Numerator()*temp1, temp2*temp1);
    return result;
  }
  else 
  {
    Rational result(fobj.Numerator() + sobj.Numerator(), fobj.Denominator());
    return result;
  }
}

Rational operator-(const Rational& fobj, const Rational& sobj)
{
  if (fobj.Denominator() != sobj.Denominator())
  {
    int temp1 = fobj.Denominator(), temp2 = sobj.Denominator();
    Rational result(fobj.Numerator()*temp2 - sobj.Numerator()*temp1, temp2*temp1);
    return result;
  }
  else 
  {
    Rational result(fobj.Numerator() - sobj.Numerator(), fobj.Denominator());
    return result;
  }
}

Rational operator*(const Rational& fobj, const Rational& sobj)
{
  //int a = fobj.Numerator()*sobj.Numerator();
  //int b = fobj.Denominator()*sobj.Denominator();
  Rational result(fobj.Numerator()*sobj.Numerator(), fobj.Denominator()*sobj.Denominator());
  return result;
}

Rational operator/(const Rational& fobj, const Rational& sobj)
{
  if(sobj.Numerator() == 0) throw domain_error("Division by zero");
  int a = fobj.Numerator()*sobj.Denominator();
  int b = fobj.Denominator()*sobj.Numerator();
  Rational result(a, b);
  return result;
}

ostream& operator<<(ostream& stream, const Rational& obj)
{
  stream << obj.Numerator() << "/" << obj.Denominator();
  return stream;
}

istream& operator>>(istream& stream, Rational& obj)
{
  int a = obj.Numerator(), b = obj.Denominator();
  stream >> a;
  stream.ignore(1);
  stream >> b;
  Rational result(a, b);
  obj = result;
  return stream;
}

bool operator<(const Rational& fobj, const Rational& sobj)
{
  if (fobj.Denominator() != sobj.Denominator())
  {
    int temp1 = fobj.Denominator(), temp2 = sobj.Denominator();
    if (fobj.Numerator()*temp2 < sobj.Numerator()*temp1) return true;
    else return false;
  }
  else
  {
    if (fobj.Numerator() < sobj.Numerator()) return true;
    else return false;
  }
}

bool operator>(const Rational& fobj, const Rational& sobj)
{
  if (fobj.Denominator() != sobj.Denominator())
  {
    int temp1 = fobj.Denominator(), temp2 = sobj.Denominator();
    if (fobj.Numerator()*temp2 > sobj.Numerator()*temp1) return true;
    else return false;
  }
  else
  {
    if (fobj.Numerator() > sobj.Numerator()) return true;
    else return false;
  }
}

int main() 
{
  try
  {
    Rational a, b;
    char operation;
    Rational result;
    cin >> a >> operation >> b;
    if (operation == '+') cout << a + b;
    if (operation == '-') cout << a - b;
    if (operation == '*') cout << a * b;
    if (operation == '/') cout << a / b;
  }
  catch (exception& ex)
  {
    cout << ex.what();
  }
  return 0;
}
