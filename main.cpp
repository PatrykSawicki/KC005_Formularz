#include <iostream>
#include <string>
#include <cctype>

using namespace std;
bool checkName(string N);
bool checkLastName(string LN);
bool checkDate (string date);

int main()
{
  //string form1{"Imie: "}, name{"Roman; "}, form2{"Nazwisko: "}, lastname{"Kowalski6; "}, form3{"Data "}, form4{"ur.: "}, date{"1900-01-30"};

   string form1{}, name{}, form2{}, lastname{}, form3{}, form4{}, date{};
   while(std::cin >> form1 >> name >> form2 >> lastname >> form3 >> form4 >> date)
   {
       //cout  << form1 << name << form2 << lastname << form3 << form4 << date << endl;
      // cout << "CheckName = " << checkName(name) << endl;
       //cout << "CheckLastName = " << checkLastName(lastname) << endl;
       //cout << "CheckDate = " << checkDate(date) << endl;

    if(checkName(name) == false) cout << 0 << endl;
    else if (checkLastName(lastname) == false) cout << 1 << endl;
    else if (checkDate(date) == false) cout << 2 << endl;
    else cout << 3 << endl;
    }

    return 0 ;
}

bool checkName(string name)
{
    if(isupper(name[0]) && name.size()<= 11)
    {
        for(int i = 1; i < name.size()-1; i++)
        {
           if (islower(name[i])) continue;
           return false;
        }
        return true;
    }
    return false;
}
bool checkLastName(string lastname)
{
    if(isupper(lastname[0]) && lastname.size()<= 21)
    {
        for(int i = 1; i < lastname.size()-1; i++)
        {
           if (islower(lastname[i])) continue;
           return false;
        }
        return true;
    }
    return false;

}
bool checkDate (string date)
{
    string RRRR {date.begin(), date.begin()+4};
    string MM   {date.begin()+5, date.begin()+7};
    string DD   {date.begin()+8, date.begin()+10};

   // cout << RRRR << "-" << MM << "-" << DD << endl;

    for(auto r : RRRR) if(!isdigit(r))  return false;
    for(auto m : MM)   if(!isdigit(m))  return false;
    for(auto d : DD)   if(!isdigit(d))  return false;

    if((stoi(RRRR)< 1900) || (stoi(RRRR) > 2000) ) return false;
    if((stoi(MM)< 1) || (stoi(MM) > 12) ) return false;
    if((stoi(DD)< 1) || (stoi(DD) > 31) ) return false;

    return true;

}
