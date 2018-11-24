#include <iostream>
#include "Headers/Exercise1.h"
#include "Headers/pair.h"
#include <string>

int main(){
    City city;
    using std::string;
    city.insert(makePair(string("Beijing"), makePair(116,50)));
    city.insert(makePair(string("London"), makePair(0,70)));
    city.insert(makePair(string("New York"), makePair(80,60)));
    city.insert(makePair(string("Shanghai"), makePair(120,40)));
    for (City::iterator it = city.begin(); it != city.end(); ++it){
        std :: cout << it->first << " " << it->second.first << " " << it->second.second << "\n";
    }
    std :: cout << "\n\n";
    City::iterator it;
    if ((it = city.find(string("Beijing"))) != city.end())
        std :: cout << it->first << " " << it->second.first << " " << it->second.second << "\n";
    if ((it = city.find(makePair(120,40))) != city.end())
        std :: cout << it->first << " " << it->second.first << " " << it->second.second << "\n";
    city.erase(string("London"));
    city.erase(makePair(80,60));
    std :: cout << "\n\n";
    for (City::iterator it = city.begin(); it != city.end(); ++it){
        std :: cout << it->first << " " << it->second.first << " " << it->second.second << "\n";
    }
}
