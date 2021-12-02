#ifndef INC_21S_PA01_TWEETS_H
#define INC_21S_PA01_TWEETS_H
#include <string>
#include <vector>

using namespace std;

class Tweets {
private:
    string content;
    int ID;

public:
    Tweets();
    Tweets(int x, string& y);

    int getID();
    string& getContent();
};


#endif //INC_21S_PA01_TWEETS_H
