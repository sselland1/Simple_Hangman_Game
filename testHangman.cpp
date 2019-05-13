//
//  testHangman.cpp
//  
//
//  Created by Scott Selland and Jeff Hank on 5/1/19.
//

#include "testHangman.hpp"
#include <iostream>
#include <SDL2/SDL.h>
#include "vector"
#include <string.h>
using namespace std;
vector<char> wordProgress(15);
vector<char> usedLetters(30);
int numGuesses = 0;
bool wordCompleted(vector<char> v, int size) {
    for(int i = 0; i < size ; i++) {
        if(v[i] == '_') {
            return false;
        }
    }
    return true;
}

void displayUsedLetters(vector<char> v, int size) {
    cout << "Used Letters: ";
    for(int i = 0 ; i < size ; i++) {
        cout << v[i] << ", ";
    }
}

void displayWord(vector<char> v, int size) {
    for(int i = 0 ; i < size ; i++) {
        cout << v[i] << " ";
    }
}

bool checkLetter(char letter, string word) {
    bool flag = false;
    for(int i  = 0 ; i < word.length() ; i++) {
        if(letter==word[i]) {
            wordProgress[i] = letter;
            flag = true;
        }
    }
    if(!flag) {
        cout << "You guessed incorrectly" << endl;
    }
    return flag;
}

int main(int argc, char* argv[]) {
    int wrong = 0;
    string word;
    vector<char> unusedLetters;
    bool hangman = false;
    bool wordCorrect = false;
    int bodyParts = 0;
    string easyWords[6] = {"apple", "banjo", "dwarf", "castle", "zebra", "whale"};
    string mediumWords[6] = {"august", "ourselves", "illinois", "memory", "essential", "relation"};
    string hardWords[6] = {"pennsylvania", "independent", "manufacturing", "neighborhood", "kayaking", "trampoline"};
    string wordUnderscores;
        char input;
        cout << "ALL WORDS ARE COMPLETELY LOWERCASE." << endl;
        cout << "Please pick a word difficulty (Easy: e, Medium: m, Hard: h) " << endl;
        cin >> input;
    srand((unsigned)time(0));
    int randNum = (rand() % 6);
    cout << randNum << endl;
    if(input == 'e' || input== 'E') {
        word = easyWords[randNum];
    }
    else if(input == 'm' || input== 'M') {
        word = mediumWords[randNum];
    }
    else if(input == 'h' || input== 'H') {
        word = hardWords[randNum];
    }
        for(int i = 0; i <=word.length(); i++) {
            wordUnderscores.append("_");
        }
    for(int j = 0; j <word.length(); j++) {
        wordProgress[j] = '_';
    }
        printf("        ____________\n");
        printf("        |          |\n");
        printf("        |          |\n");
        printf("        |          |\n");
        printf("                   |\n");
        printf("                   |\n");
        printf("                   |\n");
        printf("                   |\n");
        printf("                   |\n");
        printf("                   |\n");
        printf("                   |\n");
        printf("                   |\n");
        printf("                   |\n");
        printf("                   |\n");
        printf("                   |\n");
        printf("        ___________|____________\n");
    printf("Word to complete: ");
    for(int k=0;k<word.length();k++) {
        cout << wordProgress[k];
    }
    cout << endl;
    printf("\n");
    printf("Letters incorrectly guessed: ");
    for(int e=0;e<usedLetters.size();e++) {
        printf("%c", usedLetters[e]);
    }
    printf("\n");
        while(!hangman && !wordCorrect) {
            cout << "Please enter a un-capitalized letter to guess: " << endl;
            cin >> input;
            bool correctGuess = checkLetter(input, word);
            if(bodyParts == 0 && correctGuess){
                printf("Correct guess!\n");
                printf("        ____________\n");
                printf("        |          |\n");
                printf("        |          |\n");
                printf("        |          |\n");
                printf("                   |\n");
                printf("                   |\n");
                printf("                   |\n");
                printf("                   |\n");
                printf("                   |\n");
                printf("                   |\n");
                printf("                   |\n");
                printf("                   |\n");
                printf("                   |\n");
                printf("                   |\n");
                printf("                   |\n");
                printf("        ___________|____________\n");
                printf("Word to complete: ");
                numGuesses++;
                for(int k=0;k<word.length();k++) {
                    printf("%c",wordProgress[k]);
                }
                printf("\n");
                printf("Letters incorrectly guessed: ");
                for(int e=0;e<usedLetters.size();e++) {
                    printf("%c", usedLetters[e]);
                }
                printf("\n");
                wordCorrect = true;
                for(int g=0;g<word.length();g++) {
                    if(word[g] != wordProgress[g]) {
                        wordCorrect = false;
                    }
                }
            }
            //if no body parts but incorrect first guess
            else if(bodyParts == 0 && !correctGuess){
                usedLetters.push_back(input);
                printf("        ____________\n");
                printf("        |          |\n");
                printf("        |          |\n");
                printf("        |          |\n");
                printf("      ______       |\n");
                printf("     /     \\");
                printf("       |\n");
                printf("     | x  x |      |\n");
                printf("     \\_____/");
                printf("       |\n");
                printf("                   |\n");
                printf("                   |\n");
                printf("                   |\n");
                printf("                   |\n");
                printf("                   |\n");
                printf("                   |\n");
                printf("                   |\n");
                printf("                   |\n");
                printf("        ___________|____________\n");
                printf("Word to complete: ");
                numGuesses++;
                for(int k=0;k<word.length();k++) {
                    printf("%c",wordProgress[k]);
                }
                printf("\n");
                printf("Letters incorrectly guessed: ");
                for(int e=0;e<usedLetters.size();e++) {
                    printf("%c", usedLetters[e]);
                }
                printf("\n");
                bodyParts++;
            }
            else if(bodyParts==1 && correctGuess) {
                printf("Correct guess!\n");
                printf("        ____________\n");
                printf("        |          |\n");
                printf("        |          |\n");
                printf("        |          |\n");
                printf("      ______       |\n");
                printf("     /     \\");
                printf("       |\n");
                printf("     | x  x |      |\n");
                printf("     \\_____/");
                printf("       |\n");
                printf("                   |\n");
                printf("                   |\n");
                printf("                   |\n");
                printf("                   |\n");
                printf("                   |\n");
                printf("                   |\n");
                printf("                   |\n");
                printf("                   |\n");
                printf("        ___________|____________\n");
                printf("Word to complete: ");
                numGuesses++;
                for(int k=0;k<word.length();k++) {
                    printf("%c",wordProgress[k]);
                }
                printf("\n");
                printf("Letters incorrectly guessed: ");
                for(int e=0;e<usedLetters.size();e++) {
                    printf("%c", usedLetters[e]);
                }
                printf("\n");
                wordCorrect = true;
                for(int g=0;g<word.length();g++) {
                    if(word[g] != wordProgress[g]) {
                        wordCorrect = false;
                    }
                }
            }
            else if(bodyParts==1 && !correctGuess) {
                usedLetters.push_back(input);
                printf("        ____________\n");
                printf("        |          |\n");
                printf("        |          |\n");
                printf("        |          |\n");
                printf("      ______       |\n");
                printf("     /     \\");
                printf("       |\n");
                printf("     | x  x |      |\n");
                printf("     \\_____/");
                printf("       |\n");
                printf("        |          |\n");
                printf("        |          |\n");
                printf("        |          |\n");
                printf("        |          |\n");
                printf("        |          |\n");
                printf("        |          |\n");
                printf("                   |\n");
                printf("                   |\n");
                printf("        ___________|____________\n");
                printf("Word to complete: ");
                numGuesses++;
                for(int k=0;k<word.length();k++) {
                    printf("%c",wordProgress[k]);
                }
                printf("\n");
                printf("Letters incorrectly guessed: ");
                for(int e=0;e<usedLetters.size();e++) {
                    printf("%c", usedLetters[e]);
                }
                printf("\n");
                bodyParts++;
            }
            else if(bodyParts==2 && correctGuess) {
                printf("Correct guess!\n");
                printf("        ____________\n");
                printf("        |          |\n");
                printf("        |          |\n");
                printf("        |          |\n");
                printf("      ______       |\n");
                printf("     /     \\");
                printf("       |\n");
                printf("     | x  x |      |\n");
                printf("     \\_____/");
                printf("       |\n");
                printf("        |          |\n");
                printf("        |          |\n");
                printf("        |          |\n");
                printf("        |          |\n");
                printf("        |          |\n");
                printf("        |          |\n");
                printf("                   |\n");
                printf("                   |\n");
                printf("        ___________|____________\n");
                printf("Word to complete: ");
                numGuesses++;
                for(int k=0;k<word.length();k++) {
                    printf("%c",wordProgress[k]);
                }
                printf("\n");
                printf("Letters incorrectly guessed: ");
                for(int e=0;e<usedLetters.size();e++) {
                    printf("%c", usedLetters[e]);
                }
                printf("\n");
                wordCorrect = true;
                for(int g=0;g<word.length();g++) {
                    if(word[g] != wordProgress[g]) {
                        wordCorrect = false;
                    }
                }
            }
            else if(bodyParts==2 && !correctGuess) {
                usedLetters.push_back(input);
                printf("        ____________\n");
                printf("        |          |\n");
                printf("        |          |\n");
                printf("        |          |\n");
                printf("      ______       |\n");
                printf("     /     \\");
                printf("       |\n");
                printf("     | x  x |      |\n");
                printf("     \\_____/");
                printf("       |\n");
                printf("        |          |\n");
                printf("        |          |\n");
                printf("        |          |\n");
                printf("        |          |\n");
                printf("        |          |\n");
                printf("        |          |\n");
                printf("        /\\");
                printf("         |\n");
                printf("       /  \\");
                printf("        |\n");
                printf("        ___________|____________\n");
                printf("Word to complete: ");
                numGuesses++;
                for(int k=0;k<word.length();k++) {
                    printf("%c",wordProgress[k]);
                }
                printf("\n");
                printf("Letters incorrectly guessed: ");
                for(int e=0;e<usedLetters.size();e++) {
                    printf("%c", usedLetters[e]);
                }
                printf("\n");
                bodyParts++;
            }
            else if(bodyParts==3 && correctGuess) {
                printf("Correct guess!\n");
                printf("        ____________\n");
                printf("        |          |\n");
                printf("        |          |\n");
                printf("        |          |\n");
                printf("      ______       |\n");
                printf("     /     \\");
                printf("       |\n");
                printf("     | x  x |      |\n");
                printf("     \\_____/");
                printf("       |\n");
                printf("        |          |\n");
                printf("        |          |\n");
                printf("        |          |\n");
                printf("        |          |\n");
                printf("        |          |\n");
                printf("        |          |\n");
                printf("        /\\");
                printf("         |\n");
                printf("       /  \\");
                printf("        |\n");
                printf("        ___________|____________\n");
                printf("Word to complete: ");
                numGuesses++;
                for(int k=0;k<word.length();k++) {
                    printf("%c",wordProgress[k]);
                }
                printf("\n");
                printf("Letters incorrectly guessed: ");
                for(int e=0;e<usedLetters.size();e++) {
                    printf("%c", usedLetters[e]);
                }
                printf("\n");
                wordCorrect = true;
                for(int g=0;g<word.length();g++) {
                    if(word[g] != wordProgress[g]) {
                        wordCorrect = false;
                    }
                }
            }
            else if(bodyParts==3 && !correctGuess) {
                usedLetters.push_back(input);
                printf("        ____________\n");
                printf("        |          |\n");
                printf("        |          |\n");
                printf("        |          |\n");
                printf("      ______       |\n");
                printf("     /     \\");
                printf("       |\n");
                printf("     | x  x |      |\n");
                printf("     \\_____/");
                printf("       |\n");
                printf("     \\  |  /       |\n");
                printf("      \\ | /        |\n");
                printf("       \\|/         |\n");
                printf("        |          |\n");
                printf("        |          |\n");
                printf("        |          |\n");
                printf("        /\\");
                printf("         |\n");
                printf("       /  \\");
                printf("        |\n");
                printf("        ___________|____________\n");
                printf("Word to complete: ");
                numGuesses++;
                for(int k=0;k<word.length();k++) {
                    printf("%c",wordProgress[k]);
                }
                printf("\n");
                printf("Letters incorrectly guessed: ");
                for(int e=0;e<usedLetters.size();e++) {
                    printf("%c", usedLetters[e]);
                }
                printf("\n");
                bodyParts++;
                hangman = true;
                printf("Sorry! You lost.\n");
                cout << "The word was: " << word << endl;
            }
            if(wordCorrect && wrong == 0) {
                printf("CONGRATULATIONS, YOU WON!!!\n");
                cout << "Number of guesses to win: " << numGuesses << endl;
                cout << "To play again, run the executable." << endl;
            }
        }
}
