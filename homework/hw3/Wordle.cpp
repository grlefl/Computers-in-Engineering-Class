//
// Created by Grace Flores on 9/21/22.
//


#include "Wordle.h"


///////////////////////////////////////////////////////////////////////////


// Milestone#1 - step#3 - constructor
Wordle::Wordle(string wordListFilename) {
    setWordListFileName(wordListFilename);
    // random number generator
    srand (time(nullptr));
    for (int i = 0; i < 26; i++) {
        availableLetter[i] = true;
    }
}


///////////////////////////////////////////////////////////////////////////


// GETTERS AND SETTERS
// Milestone#1 - step#2 - getter and setter - wordListFilename
void Wordle::setWordListFileName(const string newValue) {
    wordListFilename = newValue;
}
string Wordle::getWordListFilename() const {
    return wordListFilename;
}
// Milestone#2 - step#2 - getter - secretWord
string Wordle::getSecretWord() const {
    return secretWord;
}
// Milestone#2 - step#3 - setter - secretWord
void Wordle::setSecretWord(const string newValue) {
    // Check if word is in word list
    if (find(wordList.begin(), wordList.end(),newValue) == wordList.end()){
        cout << "Error: word is not in wordList vector" << endl;
    } else {
        secretWord = newValue;
    }
}
// Milestone#3 - step#2 - getter - guessNum
int Wordle::getGuessNum() const {
    return guessNum;
}


///////////////////////////////////////////////////////////////////////////


// Milestone#1 - step#5 - loadWordList() method
// there should be no input or output
void Wordle::loadWordList() {
    // step(0) - open/close file
    ifstream fin(wordListFilename); // NEEDS FIXING
    if (fin.fail()) {
        cout << "Error: could not open data.txt" << endl;
    }
    // step(1) - read list of words to count number of words
    // I think he specified how to do this efficiently in class?
    int numberOfWords = 0;
    while(!fin.eof()) {
        string line;
        getline(fin, line);
        if (line == "") { // accounting for empty line at the end of the file
        }
        else {
            numberOfWords += 1;
        }
    }
    // cout << numberOfWords << endl; // TEST
    // step(2) - use vector's resize method to allocate required number of strings in
    //           wordList to save words
    wordList.resize(numberOfWords);
    // step(3) use fin.clear(); to clear the end of the file flag
    fin.clear();
    // step(4) - use fin.seekg(0, fin.beg); to return the file reading to the start of the file
    fin.seekg(0, fin.beg);
    // step(5) - read in and store each word in wordList
    for(int i = 0; i<wordList.size(); i++) {
        string line;
        getline(fin, line);
        wordList[i] = line; // replace each vector element with a word
    }
    /* TEST
    for (int i = 0; i<Wordle::wordList.vector::size(); i++) {
        cout << Wordle::wordList[i] << endl;
    }
    */
}


///////////////////////////////////////////////////////////////////////////


// Milestone#1 - step#6 - printWordList() method
// should have no inputs or outputs
void Wordle::printWordList() {
    if (wordList.size()==0) {
        cout << "Error: no words in wordList vector" << endl;
    }
    else {
        for (int i = 0; i<wordList.size(); i++) {
            cout << wordList[i] << endl;
        }
    }
}


///////////////////////////////////////////////////////////////////////////


// Milestone#2 - step#4 - setRandomSecretWord()
void Wordle::setRandomSecretWord() {
    int i = rand() % wordList.size();
    secretWord = wordList[i];
}


///////////////////////////////////////////////////////////////////////////


// Milestone#3 - step#3 - makeGuess()
// returns true if input matches secret word, false otherwise
// must check if input is 5 letter word and in the wordList
bool Wordle::makeGuess(const string newGuess) {
    // PSEUDOCODE
    // if the user's guess is less than max guess limit
        // if word is not 5 letters
            // print error message
        // if 5 letter word is not in wordList
            // print error message
        // else
            // word is added to guess vector
            // string "?????" is added to feedback vector
            // guessNum is incremented
            // if word matches secret word
                // print message: you got it!
            // else (if the word doesn't match the secret word)
                // if this is the last guess
                    // game over message, reveal secret word
                // else
                    // try again
    // else
        // you have no more guesses left :(
    if (guessNum < MAX_GUESS_NUM) {
        if (newGuess.length() != 5) {
            cout << "Error: word is not 5 letters" << endl;
            return false;
        } else if (find(wordList.begin(), wordList.end(), newGuess) == wordList.end()) {
            cout << "Error: word is not in wordList vector" << endl;
            return false;
        } else {
            guess.push_back(newGuess);

            // feedback.push_back("?????"); // feedback vector, previous code
            // Milestone 5 - step#1 - modify makeGuess to give feedback of correct letters in correct positions
            string newFeedback = "....."; // part#1 - assume that all characters in the feedback string are initially "."
            string copySecretWord = secretWord; // part#2 - make another variable copy of secret word
            // part#3 - compare guess character-by-character with copy of secret word
            // if the characters match, replace "." with "!" in the feedback and replace character in copy with "-"
            for (int i = 0; i < 5; i++) {
                if (newGuess[i] == copySecretWord[i]) {
                    newFeedback[i] = '!';
                    copySecretWord[i] = '-';
                }
            }
            // part#4 - for each character in the guess without the "!" in feedback, compare to all characters in copy
            // if it matches a character in  the copy, replace character in copy with "-" and replace "." with "+" in feedback
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (newGuess[i] == copySecretWord[j] and newFeedback[i] != '!') {
                        copySecretWord[j] = '-';
                        newFeedback[i] = '+';
                    }
                }
            }
            feedback.push_back(newFeedback);

            // Milestone#6 - step#3
            // change the value at the proper index of availableLetter to false if a guessed letter is not in the
            // secret word
            for (int i = 0; i<5; i++) {
                if (newFeedback[i] == '.') { // why is this string and not char?
                    for (int j = 0; j < 26; j++) {
                        if (newGuess[i] == alphabet[j]) {
                            availableLetter[j] = false;
                        }
                    }
                }
            }

            guessNum = guessNum += 1;
            if (newGuess == secretWord) {
                cout << "Congratulations! You guessed the right word." << endl;
                return true;
                // should anything else be added to prevent more unnecessary guesses?
            } else {
                if (guessNum == 6) {
                    cout << "Game over. Correct word: " << secretWord << endl;
                    return false;
                } else {
                    cout << "Incorrect word. Try again." << endl;
                    return false;
                }
            }
        }
    } else {
        cout << "You have no more guesses left :(" << endl;
        return false;
    }
}


///////////////////////////////////////////////////////////////////////////


// Milestone#3 - step#4 - print()
void Wordle::print() {
    for (int i = 0; i < guess.size(); i++) {
        cout << i+1 << ": " << guess[i] << " " << feedback[i] << endl;
    }
    cout << endl;
}


///////////////////////////////////////////////////////////////////////////


// Milestone#6 - step#4 - printAvailableLetters()
void Wordle::printAvailableLetters() {
    cout << "Available letters: ";
    for (int i = 0; i < 26; i++) {
        if (availableLetter[i] == true) {
            cout << alphabet[i] << " ";
        }
    }
    cout << endl;
}


///////////////////////////////////////////////////////////////////////////