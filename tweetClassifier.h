#ifndef RESEARCH_PROJECT_TWEETCLASSIFIER_H
#define RESEARCH_PROJECT_TWEETCLASSIFIER_H
#include "Tweets.h"
#include <vector>

class tweetClassifier {
private:
    vector<Tweets> allTweets;
public:
    tweetClassifier();
    void readFile(char**);
    void runTests(char**);
    /////////////////////////////////////////////////////////////
    //HELPER FUNCTIONS
    void readInputWords(char**, vector<string>& inputWords);
};

#endif //RESEARCH_PROJECT_TWEETCLASSIFIER_H
