#include "person.h"

Person::Person(){
    name = "";
    noMatches = {""};
}

Person::Person(const char *_name, std::vector<const char*> _noMatches) {
    name = _name;
    noMatches = _noMatches;
    noMatches.push_back(name);
}

void Person::setNoMatches(std::vector<const char *> n) {noMatches = n;}
std::vector<const char *> Person::getNoMatches() {return noMatches;}

const char *Person::getName() {return name;}

bool Person::isMatch(const char *match) {
    for ( const char *m: noMatches){
        if (*m == *match){
            return false;
        }
    }
    return true;
}

