#ifndef PERSON_H
#define PERSON_H

#include <vector>
#include <algorithm>
#include <iterator>
class Person {
    private:
        std::vector<const char *> noMatches;
        const char *name;
    public:
        Person();
        Person(const char *_name, std::vector<const char *> _noMatches);
        //matches getter and setter
        void setNoMatches(std::vector<const char *>);
        std::vector<const char *> getNoMatches();
        //name getter
        const char *getName();
        //checks if a person can match with another person
        bool isMatch(const char *);

};

#include "person.cpp"
#endif