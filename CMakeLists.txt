cmake_minimum_required(VERSION 3.16)
project(Research_Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Research_Project main.cpp tweetClassifier.cpp tweetClassifier.h Tweets.cpp Tweets.h porter2_stemmer/porter2_stemmer.h porter2_stemmer/porter2_stemmer.cpp)