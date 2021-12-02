#include "Tweets.h"
#include <string>
#include <vector>
using namespace std;

Tweets::Tweets() = default;
Tweets::Tweets(int x, string& y){
    ID = x;
    content = y;
}

int Tweets::getID(){
    return ID;
}

string& Tweets::getContent(){return content;}