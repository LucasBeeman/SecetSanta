#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <algorithm>
#include <iterator>
#include <chrono>
#include "person.h"

using namespace std;

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
vector<Person> shufflePeople(vector<Person> );
void finalizeShuffle( vector<Person>, vector<Person> &);
void sendToFile(const char*, const char*);

//------------[EDIT HERE]-----------------------
//{[name], {[list of people to not match with]},}
vector<Person> people {
{"Lucas", {"Jennele"}},
{"Trent", {"Jenelle", "Maddie"}},
{"Joe", {"Trent"}},
{"Maddie", {"Joe", "Steven"}},
{"Jennele", {"Steven", "Trent"}},
{"Steven", {"Liam", "Maddie"}},
{"Liam", {"Lucas"}},
{"Brandon", {""}},
{"Dylan", {""}}
};
//----------------------------------------------


int main() {
  vector<Person> newVec = shufflePeople(people);

  finalizeShuffle(people, newVec);

  return 0;
}

vector<Person> shufflePeople(vector<Person> v) {
  shuffle(v.begin(), v.end(), default_random_engine(seed));
  return v;
}

void finalizeShuffle(vector<Person> original, vector<Person> &v) {
  random_device rd;
  uniform_int_distribution<int> dist(1, v.size() - 1);

  vector<Person>::iterator itOne = v.begin();
  vector<Person>::iterator itTwo = v.begin();
  Person temp("", {""});
  for (int i = 0; i <= original.size(); i++){
    while (!original[i].isMatch(v[i].getName())){
      advance(itOne, i);
      advance(itTwo, dist(rd));
      temp = *itOne;
      *itOne = *itTwo;
      *itTwo = temp;
      itOne = v.begin();
      itTwo = v.begin(); 
    }
    sendToFile(original[i].getName(), v[i].getName());
  }
}


void sendToFile(const char*s1, const char*s2) {
  string str2(s2);  
  ofstream f(str2 + ".txt");
  f << s2;
  f.close();
}