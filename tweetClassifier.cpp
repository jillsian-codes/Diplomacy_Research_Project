#include "tweetClassifier.h"
#include "porter2_stemmer/porter2_stemmer.h"

#include <fstream>
#include <iostream>
#include <istream>
#include <vector>
#include <cstring>
#include <string>
#include <iomanip>

using namespace std;

tweetClassifier::tweetClassifier() = default;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void tweetClassifier::readFile(char** cmdInput) {
    // OPEN INPUT FILE
    ifstream inputFile;
    cout << endl << "Opening input file..." << endl;
    inputFile.open(cmdInput[1]);

    if (!inputFile.is_open()) {
        cout << "Input file did not open.";
        return;
    }

    //READ INPUT FILE
    cout << "Reading input file..." << endl;

    //ignore first line
    inputFile.ignore(100000, '\n');

    //read rest of file
    char *buff = new char[100000];
    int index = 2;
    inputFile.getline(buff, 100000, '~');
    string loweredString;
    //vector<string> tokens;

    while (!inputFile.eof()) {
        //makes everything lowercase
        char c;
        loweredString = "";
        for(int x = 0; x < strlen(buff); x++){
            c = tolower(buff[x]);
            loweredString += c;
        }

        //tokenize the line
        //tokens.clear();
        //customTokenizer(loweredString, tokens);

        //add as a new tweet
        Tweets newTweet(index, loweredString);
        allTweets.push_back(newTweet);
        index++;

        //read next line
        inputFile.getline(buff, 100000, '~');
    }

    cout << "Stored " << (index - 1) << " tweets." << endl;
    //delete buff, close file
    delete[] buff;
    inputFile.close();
}

void tweetClassifier::runTests(char** cmdInput){
    cout << "Searching for words..." << endl;

    //READ INPUT WORDS FROM FILE
    vector<string> inputWords;
    readInputWords(cmdInput, inputWords);

    //SEARCH EACH TWEET FOR KEYWORDS
    ofstream fout;
    fout.open(cmdInput[3]);

    for(int i = 0; i < allTweets.size(); i++){
        //establish variables
        string haystack = allTweets[i].getContent();
        int size2 = inputWords.size();
        bool found = false;

        //search for each word in each tweet. if found, turn "found" to true
        for(int y = 0; y < size2; y++){
            string needle = inputWords[y];
            size_t foundIndex = haystack.find(needle);
            if(foundIndex != string::npos) //this means it was found
                found = true;
            else
                continue;
        }
        //output results
        fout << allTweets[i].getID() << ", ";
        if(found == true)
            fout << "1" << endl;
        else
            fout << "0" << endl;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////
//HELPER FUNCTIONS
void tweetClassifier::readInputWords(char** cmdInput, vector<string>& inputWords){
    char* buff = new char[100];
    ifstream inputFile;
    inputFile.open(cmdInput[2]);
    if (!inputFile.is_open()) {
        cout << "Input file did not open.";
        return;
    }

    string line;
    //get first word
    inputFile.getline(buff, 100, ',');
    while(true){
        //if at end, break
        if(inputFile.eof())
            break;

        //store the word
        line = buff;
        Porter2Stemmer::stem(line);
        inputWords.push_back(line);

        //get the next word
        inputFile.getline(buff, 100, ',');
    }
    inputFile.close();
    delete[] buff;
}