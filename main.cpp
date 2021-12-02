#include "tweetClassifier.h"

using namespace std;

// MAIN METHOD DEFINITION
int main(int cmdNumInput, char** cmdInput) {
    /* order of command input:
     * argv[0] - executable
     * argv[1] - .csv file
     * argv[2] - input words
     * argv[3] - output
     */

    //RUN TESTS
    tweetClassifier myTweetClassifier;
    myTweetClassifier.readFile(cmdInput);
    myTweetClassifier.runTests(cmdInput);

    return 0;
}