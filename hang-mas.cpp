//File: hangman.cpp
//Name: Bryan Alvarez, Scott Smith, Tin Chung, Mia Han
//Date: 05/14/2021
//Course: CompSci 1
//Description:Classic game of Hangman written in C++ programming language utilizing object oriented designs, well-defined behaviors, sufficient complexity, interactive, showing good modularization of functions using data structure, and classes.
//Usage: user will be prompted for input to try and solve the mystery word, if the user fails to solve the word within 6 tries. the user will lose the game.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <cstdio>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

void Banner()
{
    cout << R"(
██╗  ██╗ █████╗ ███╗   ██╗ ██████╗ ███╗   ███╗ █████╗ ███╗   ██╗
██║  ██║██╔══██╗████╗  ██║██╔════╝ ████╗ ████║██╔══██╗████╗  ██║
███████║███████║██╔██╗ ██║██║  ███╗██╔████╔██║███████║██╔██╗ ██║
██╔══██║██╔══██║██║╚██╗██║██║   ██║██║╚██╔╝██║██╔══██║██║╚██╗██║
██║  ██║██║  ██║██║ ╚████║╚██████╔╝██║ ╚═╝ ██║██║  ██║██║ ╚████║
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝
)"
         << "\n\n\n";
};

void Rules()
{
    Banner();
    cout << "Rules:\nWelcome to the classic game of hangman!\n"
         << "Your objective will be to guess each letter in our secret word.\n"
         << "We will provide blank spaces that will show the length of the word.\n"
         << "If you guess all letters correctly then you win and Mr.ASCII will thank you for it.\n"
         << "However, if you fail to guess a correct letter 5 times, the game will end badly for Mr.ASCII." << endl;
};

// Vector holding the possible states of the hangman.
class Hangman
{

public:
    vector<string> GetOriginal(int currentStage);
    vector<string> GetChristmas(int currentStage);
};

vector<string> Hangman::GetOriginal(int currentStage)
{
    vector<string> HangmanState;
    HangmanState.push_back(R"(
                    +---------+
                    |         |
                    |         |
                    |         |
                    |         |
                    +---------+
)");
    HangmanState.push_back(R"(
                    +---------+
                    |    |    |
                    |         |
                    |         |
                    |         |
                    +---------+
)");
    HangmanState.push_back(R"(
                    +---------+
                    |    |    |
                    |    U    |
                    |         |
                    |         |
                    +---------+
)");
    HangmanState.push_back(R"(
                    +---------+
                    |    |    |
                    |    O    |
                    |         |
                    |         |
                    +---------+
)");
    HangmanState.push_back(R"(
                    +---------+
                    |    |    |
                    |    O    |
                    |    |    |
                    |         |
                    +---------+
)");
    HangmanState.push_back(R"(
                    +---------+
                    |    |    |
                    |    O    |
                    |   /|    |
                    |         |
                    +---------+
)");
    HangmanState.push_back(R"(
                    +---------+
                    |    |    |
                    |    O    |
                    |   /|\   |
                    |         |
                    +---------+
)");
    HangmanState.push_back(R"(
                    +---------+
                    |    |    |
                    |    O    |
                    |   /|\   |
                    |   /     |
                    +---------+
)");
    HangmanState.push_back(R"(
                    +---------+
                    |    |    |
                    |    O    |
                    |   /|\   |
                    |   / \   |
                    +---------+
)");

    return HangmanState;
}

vector<string> Hangman::GetChristmas(int currentStage)
{
    vector<string> HangmanState;
    HangmanState.push_back(R"(
                +----------------+       
                |        *       |
                |       /.\      |
                |      /..'\     |
                |      /'.'\     |
                |     /.''.'\    |
                |     /.'.'.\    |
                |    /'.''.'.\   |
                |    ^^^[_]^^^   |
                +----------------+
)");
    HangmanState.push_back(R"(
                +----------------+       
                |        X       |
                |       XXX      |
                |      /..'\     |
                |      /'.'\     |
                |     /.''.'\    |
                |     /.'.'.\    |
                |    /'.''.'.\   |
                |    ^^^[_]^^^   |
                +----------------+
)");
    HangmanState.push_back(R"(
                +----------------+       
                |        X       |
                |       XXX      |
                |      XXXXX     |
                |      /'.'\     |
                |     /.''.'\    |
                |     /.'.'.\    |
                |    /'.''.'.\   |
                |    ^^^[_]^^^   |
                +----------------+
)");
    HangmanState.push_back(R"(
                +----------------+       
                |        X       |
                |       XXX      |
                |      XXXXX     |
                |     XXXXXXX    |
                |     /.''.'\    |
                |     /.'.'.\    |
                |    /'.''.'.\   |
                |    ^^^[_]^^^   |
                +----------------+
)");
    HangmanState.push_back(R"(
                +----------------+       
                |        X       |
                |       XXX      |
                |      XXXXX     |
                |     XXXXXXX    |
                |    XXXXXXXXX   |
                |     /.'.'.\    |
                |    /'.''.'.\   |
                |    ^^^[_]^^^   |
                +----------------+
)");
    HangmanState.push_back(R"(
                +----------------+       
                |        X       |
                |       XXX      |
                |      XXXXX     |
                |     XXXXXXX    |
                |    XXXXXXXXX   |
                |   XXXXXXXXXXX  |
                |    /'.''.'.\   |
                |    ^^^[_]^^^   |
                +----------------+
)");
    HangmanState.push_back(R"(
                +----------------+       
                |        X       |
                |       XXX      |
                |      XXXXX     |
                |     XXXXXXX    |
                |    XXXXXXXXX   |
                |   XXXXXXXXXXX  |
                |  XXXXXXXXXXXXX |
                |    ^^^[_]^^^   |
                +----------------+
)");
    HangmanState.push_back(R"(
                +----------------+       
                |        X       |
                |       XXX      |
                |      XXXXX     |
                |     XXXXXXX    |
                |    XXXXXXXXX   |
                |   XXXXXXXXXXX  |
                |  XXXXXXXXXXXXX |
                |  XXXXXXXXXXXXX |
                +----------------+
)");
    HangmanState.push_back(R"(
                +----------------+       
                |                |
                |                |
                |                |
                |                |
                |       )        |
                |       ) \      |
                |      / ) (     |
                |      \(_)/     |  
                +----------------+
)");

    return HangmanState;
}

void PrintAvailableLetters(string userGuesses)
{
    string remainingLetters;

    // Loop through capital letters to see if the user's guess is in the
    for (char i = 'A'; i <= 'Z'; i++)
    {
        if (userGuesses.find(i) == string::npos)
        {
            remainingLetters += i;
            remainingLetters += ' ';
        }
        else
        {
            remainingLetters += "  ";
        }
    }
    cout << "_______________ Available Letters _________________" << endl;
    cout << remainingLetters;
};

string GetRandomWord(string file)
{
    vector<string> words;
    string fileOutput;
    int selectedWord;

    ifstream myFile;
    myFile.open(file);

    if (myFile.is_open())
    {
        while (std::getline(myFile, fileOutput))
        {
            words.push_back(fileOutput);
            selectedWord = rand() % words.size();
            fileOutput = words.at(selectedWord);
        }
    }
    myFile.close();

    return fileOutput;
};

int ProcessUserGuess(string secretWord, string guessed)
{
    int incorrectGuesses = 0;

    for (int i = 0; i < guessed.length(); i++)
    {
        if (secretWord.find(guessed[i]) == string::npos)
        {
            incorrectGuesses++;
        }
    }

    return incorrectGuesses;
}

bool Game(string secretWord, string userGuesses, bool &blanksRemaining)
{
    string str;

    for (int i = 0; i < secretWord.length(); i++)
    {
        if (userGuesses.find(secretWord[i]) == string::npos)
        {
            str += "_ ";
        }
        else
        {
            str += secretWord[i];
            str += "";
        }
    }

    int found = str.find("_");
    if (found != std::string::npos)
    {
        blanksRemaining = true;
    }
    else
    {
        blanksRemaining = false;
    }

    cout << "Secret Word:  " << str << "\n\n";

    return blanksRemaining;
};

int main()
{
    srand(time(0));
    char gameMode;
    Hangman gameTemplate;
    vector<string> gridAtPlay;
    string selectedGameType;
    string objective;
    string secretWord;
    string userGuesses;
    int incorrectGuesses = 0;
    bool gameOver = false;
    bool blanksRemaining;

    Rules();

    secretWord = GetRandomWord("./words.txt");

    while (true)
    {
        cout << "\n\n\n Choose a game mode: \n(o) = original \n(c) = christmas \n\n";
        cin >> gameMode;
        if (gameMode == 'c')
        {
            gridAtPlay = gameTemplate.GetChristmas(incorrectGuesses);
            selectedGameType = "christmas";
            objective = "christmas";
            break;
        }
        else if (gameMode == 'o')
        {
            gridAtPlay = gameTemplate.GetOriginal(incorrectGuesses);
            selectedGameType = "orignal";
            objective = "the hang man";
            break;
        }
        else
        {
            continue;
        }
    }

    while (incorrectGuesses < 8)
    {
        cout << gridAtPlay.at(incorrectGuesses);
        PrintAvailableLetters(userGuesses);
        cout << "\n\nGuess the secret word, save the hangman\n";
        blanksRemaining = Game(secretWord, userGuesses, blanksRemaining);

        char guess;
        cout << "Enter your guess: ";
        cin >> guess;

        if (islower(guess))
        {
            guess = toupper(guess);
            cout << guess;
        }

        if (userGuesses.find(guess) == string::npos)
        {
            userGuesses += guess;
        }

        incorrectGuesses = ProcessUserGuess(secretWord, userGuesses);

        blanksRemaining = blanksRemaining;

        if (blanksRemaining == 0)
        {
            break;
        };
    };

    if (incorrectGuesses < 8)
    {
        cout << "\nYou guessed " << secretWord << " correctly!\n";
        cout << "You saved " << objective << "! Congratulations!\n\n";
        system("pause");
    }
    else
    {
        cout << gridAtPlay.at(incorrectGuesses);
        cout << "You failed to save " << objective << "...\n";
        cout << "The secret word was " << secretWord << "\n\n";
        system("pause");
    }

    return 0;
};