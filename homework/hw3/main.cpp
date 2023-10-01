/***************************************************************************************************
 * Name: Grace Flores
 * Date: September 24, 2022
 * File Name: hw3
 * Description: This program simulates the Wordle game by using classes.
****************************************************************************************************/


#include "Wordle.h"


int main() {

    // Milestone#1 - step#7
    // unit tests for Wordle(), setWordListFilename(), getWordListFilename(), loadWordList(), printWordList()
    cout << endl;
    cout << "UNIT TEST FOR Wordle(), setWordListFilename(), and getWordListFilename()" << endl;
    Wordle empty_file; // constructor test includes setter test
    cout << "Expected output:" << endl;
    cout << "" << endl;
    cout << "Actual output:" << endl;
    cout << empty_file.getWordListFilename() << endl;
    Wordle working_object("wordList.txt");
    cout << "Expected output:" << endl;
    cout << "wordList.txt" << endl;
    cout << "Actual output:" << endl;
    cout << working_object.getWordListFilename() << endl;
    //
    cout << endl;
    cout << "UNIT TEST FOR loadWordList() and printWordList()" << endl;
    cout << "Expected output:" << endl;
    cout << "Error: no words in wordList vector" << endl;
    Wordle empty_vector("emptyFile.txt");
    empty_vector.loadWordList();
    cout << "Actual output:" << endl;
    empty_vector.printWordList();
    cout << "Expected output is a lot of words." << endl;
    working_object.loadWordList();
    cout << "Actual output:" << endl;
    // working_object.printWordList(); // test works


    // Milestone#2 - step#5
    // unit tests for setSecretWord(), getSecretWord(), setRandomSecretWord()
    cout << endl;
    cout << "UNIT TEST FOR setSecretWord() and getSecretWord()" << endl;
    cout << "Expected output:" << endl;
    cout << "Error: word is not in wordList vector" << endl;
    cout << "Actual output:" << endl;
    working_object.setSecretWord("bxslk"); // error should be generated
    cout << "Expected output:" << endl;
    cout << "booby" << endl;
    working_object.setSecretWord("booby");
    cout << "Actual output:" << endl;
    cout << working_object.getSecretWord() << endl;
    //
    cout << endl;
    cout << "UNIT TEST FOR setRandomSecretWord()" << endl;
    cout << "Expected output is a bunch of random words." << endl;
    working_object.setRandomSecretWord();
    cout << working_object.getSecretWord() << endl;
    working_object.setRandomSecretWord();
    cout << working_object.getSecretWord() << endl;
    working_object.setRandomSecretWord();
    cout << working_object.getSecretWord() << endl;
    working_object.setRandomSecretWord();
    cout << working_object.getSecretWord() << endl;
    working_object.setRandomSecretWord();
    cout << working_object.getSecretWord() << endl;
    working_object.setRandomSecretWord();
    cout << working_object.getSecretWord() << endl;


    // Milestone#3 - step#5
    // unit tests for guessNum(), makeGuess(), print()
    cout << endl;
    cout << "UNIT TEST FOR setRandomSecretWord()" << endl;
    working_object.setSecretWord("booby");
    cout << "The secret word is set to " << working_object.getSecretWord() << "." << endl;
    working_object.makeGuess("blue");
    working_object.makeGuess("btxst");
    working_object.makeGuess("thars");
    working_object.print();
    working_object.makeGuess("vezir");
    working_object.print();
    working_object.makeGuess("vezir");
    working_object.print();
    working_object.makeGuess("vezir");
    working_object.print();
    working_object.makeGuess("stall");
    working_object.print();
    working_object.makeGuess("booby");
    working_object.print();
    working_object.makeGuess("waist");
    // I'm not sure how to test the scenario where the user
    // guesses incorrectly all 6 times. The homework says
    // to not make a setter for guessNum, so I can't redo the
    // guesses.


    // Milestone#5 - step#2 - unit tests for updated makeGuess()
    cout << endl;
    cout << "UNIT TEST FOR updated makeGuess()" << endl;
    Wordle testMakeGuess("wordList.txt");
    testMakeGuess.loadWordList();
    testMakeGuess.setSecretWord("sloth");
    cout << "Secret word is set to " << testMakeGuess.getSecretWord() << "." << endl;
    cout << "Expected output for final feedback:" << endl;
    cout << "1: weary ....." << endl;
    cout << "2: blush .!.+!" << endl;
    cout << "3: slosh !!!.!" << endl;
    cout << "4: sloth !!!!!" << endl;
    cout << "Actual output:" << endl;
    testMakeGuess.makeGuess("weary");
    testMakeGuess.print();
    testMakeGuess.makeGuess("blush");
    testMakeGuess.print();
    testMakeGuess.makeGuess("slosh");
    testMakeGuess.print();
    testMakeGuess.makeGuess("sloth");
    testMakeGuess.print();


    // Milestone#6 - step#6 - unit tests for updated makeGuess() and printAvailableLetters()
    cout << endl;
    cout << "UNIT TEST FOR updated makeGuess() printAvailableLetters()" << endl;
    Wordle testAvailableLetters("wordList.txt");
    testAvailableLetters.loadWordList();
    testAvailableLetters.setSecretWord("sloth");
    cout << "Secret word is set to " << testMakeGuess.getSecretWord() << "." << endl;
    cout << "Expected output for each print of printAvailableLetters():" << endl;
    cout << "Available letters: b c d f g h i j k l m n o p q s t u v x z" << endl;
    cout << "Available letters: c d f g h i j k l m n o p q s t v x z" << endl;
    cout << "Available letters: c d f g h i j k l m n o p q t v x z" << endl;
    cout << "Actual output:" << endl;
    testAvailableLetters.makeGuess("weary");
    testAvailableLetters.printAvailableLetters();
    testAvailableLetters.makeGuess("blush");
    testAvailableLetters.printAvailableLetters();
    testAvailableLetters.makeGuess("slosh");
    testAvailableLetters.printAvailableLetters();
    testAvailableLetters.makeGuess("sloth");


    // GAMEPLAY
    // Milestone#4 - step#1 - print a list of instructions for playing Wordle
    // These instructions may not fully apply can be changed later.
    cout << endl;
    cout << "HOW TO PLAY WORDLE" << endl;
    cout << "Guess the Wordle in 6 tries." << endl;
    cout << "Each guess must be a valid 5-letter word. Hit the enter button to submit." << endl;
    cout << "After each guess, a string of feedback will show you how close your guess was to the word." << endl;
    cout << "\t! means the letter is in the correct spot." << endl;
    cout << "\t+ means the letter is in the word, but it is not in the correct spot." << endl;
    cout << "\t. means the letter is not in the word." << endl;
    cout << "Good luck!" << endl;
    cout << endl;

    // Milestone#4 - step#2 - instantiate Wordle object, load valid word list
    Wordle wordleGame("wordList.txt");
    wordleGame.loadWordList();

    // Milestone#4 - step#3 - set a known secret word and print it
    wordleGame.setSecretWord("hammy");
    cout << "Secret word is set to " << wordleGame.getSecretWord() << "." << endl;

    // Milestone#4 - step#4 - while loop
    while (wordleGame.getGuessNum() < 6) {
        wordleGame.printAvailableLetters();
        string newGuess;
        cout << "Enter guess#" << wordleGame.getGuessNum()+1 << ": " << endl;
        cin >> newGuess;
        if (wordleGame.makeGuess(newGuess) == true) {
            wordleGame.print();
            break; // break out of while loop if user guesses the right word
        }
        wordleGame.print();
    }


    return 0;
}
