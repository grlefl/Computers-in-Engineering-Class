//
// Created by Grace Flores on 9/21/22.
//


#ifndef COMPOSITIONEXAMPLE_WORDLE_H
#define COMPOSITIONEXAMPLE_WORDLE_H


// extra stuff
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;


// create Wordle class
class Wordle {
public:

    /*********************************************************************
     * Wordle(): Wordle class constructor that calls on the setter method to
     *           set m_wordListFilename to "" unless otherwise specified
     * Input: file name, initially set to ""
     * Outputs: none
    *********************************************************************/
    // Milestone#1 - step#3 - constructor
    explicit Wordle(string wordListFilename = "");


    /*********************************************************************
     * GETTERS AND SETTERS
    *********************************************************************/
    void setWordListFileName(const string newValue); // Milestone#1 - step#2 - setter - wordListFilename
    string getWordListFilename() const; // Milestone#1 - step#2 - getter - wordListFilename
    string getSecretWord() const; // Milestone#2 - step#2 - getter - secretWord
    void setSecretWord(const string newValue); // Milestone#2 - step#3 - setter - secretWord
    int getGuessNum() const; // Milestone#3 - step#2 - getter - guessNum


    /*********************************************************************
     * loadWordList(): Wordle method that opens a text file to read and
     *                 store words into empty vector wordList
     * Inputs: none
     * Outputs: none
    *********************************************************************/
    // Milestone#1 - step#5 - loadWordList() method /COMMENT BLOCK/
    // there should be no input or output
    void loadWordList();


    /*********************************************************************
     * printWordList(): Wordle method that prints out all the words from
     *                  vector wordList
     * Inputs: none
     * Outputs: none
    *********************************************************************/
    // Milestone#1 - step#6 - printWordList() method
    // should have no inputs or outputs
    void printWordList();


    /*********************************************************************
     * setRandomSecretWord(): Wordle method that uses rand() function to
     *                        set secretWord to random word from wordList
     * Inputs: none
     * Outputs: none
    *********************************************************************/
    // Milestone#2 - step#4 - setRandomSecretWord()
    void setRandomSecretWord();


    /*********************************************************************
     * makeGuess(): User inputs 5 letter word. Returns true if the word
     *              matches the secretWord; returns false otherwise.
     * Input: 5 letter string
     * Outputs: true and false
    *********************************************************************/
    // Milestone#3 - step#3 - makeGuess()
    bool makeGuess(const string newGuess);


    /*********************************************************************
     * print(): prints to the screen each guess in guess vector and its
     *          associated feedback in feedback vector
     * Inputs: none
     * Outputs: none
    *********************************************************************/
    // Milestone#3 - step#4 - print()
    void print();


    /*********************************************************************
     * print(): prints letters that might still be in the secret word
     * Inputs: none
     * Outputs: none
    *********************************************************************/
    // Milestone#6 - step#4 - printAvailableLetters()
    void printAvailableLetters();

private:

    // Milestone#1 - step#1 - private string wordListFilename
    string wordListFilename; // holds the name of the file with all Wordle words


    // Milestone#1 - step#4 - private empty vector wordList
    vector<string> wordList; // stores all words from wordList.txt


    // Milestone#2 - step#1 - private string secretWord
    string secretWord; // holds secret word to guess


    // Milestone#3 - step#1 - more private variables
    int guessNum = 0;  // number of guesses
    const int MAX_GUESS_NUM = 6; // maximum number of guesses
    vector<string> guess;  // list of previous guesses
    vector<string> feedback; // list of feedback strings

    // Milestone#6 - step#1
    bool availableLetter[26];   // This array to holds all “available letters” that still might be in the secret word.
                                // Index 0 corresponds to 'a', 1 to 'b', etc. and at each index, a value of true means
                                // the character is available.
    // I think alphabet array is necessary as well, but homework did not specify.
    const char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x', 'y', 'z'};

};

#endif //COMPOSITIONEXAMPLE_WORDLE_H
