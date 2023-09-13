#include <algorithm>    
#include <fstream>
#include <iostream>
#include <random>

std::vector<std::string> openFile() 
{
    std::vector<std::string> words {};
    std::ifstream inf {"/home/simon/VSCodeProjects/HangmanGame/words.txt"};

    if (!inf)
    {
        std::cerr << "Uh oh, words.txt could not be opened for reading!\n";
        return words;
    }

    while (inf)
    {
        std::string strInput;
        inf >> strInput;
        words.push_back(strInput);
    }

    return words;
}

int randomNumberGenerator(int upperLimit)
{
    std::mt19937 mt{ std::random_device{}()};
    std::uniform_int_distribution rollNumber(0, upperLimit);
    int randomNumber {rollNumber(mt)};
    return randomNumber;
}

void printLettersAndSpaces(std::vector<char> lettersFound, std::string wordIn)
{
    int wordLength = wordIn.size();
}

std::vector<char> printAvailableLetters(std::vector<char> guessedLetters)
{
    std::vector<char> alphabetVector{};
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    for (int i {}; i < guessedLetters.size(); i++)
    {
        alphabet.erase(std::find(alphabet.begin(), alphabet.end(), guessedLetters[i]));
    }
    std::cout << "Available letters: ";
    for (int i{}; i < alphabet.size(); i++)
    {
        alphabetVector.push_back(alphabet[i]);
        std::cout << alphabet[i];
    }
    std::cout << std::endl;
    return alphabetVector;
}

char UserInput()
{
    while (true)
    {
    std::cout << "Please choose a letter: ";
    char x {}; 
    std::cin >> x;
    if (std::isalpha(x))
    {
        return x;
    }
    else
    {
        std::cerr << "Invalid input, please enter a letter from the available letters. " << '\n';
        std::cin.ignore();
    }
    }
}



int main()
{
    std::vector<char> guessedLettersTest {'a', 'b', 'c'};
    std::vector<char> currentAvailableLetters {printAvailableLetters(guessedLettersTest)};
    std::cout << UserInput();
    std::vector<std::string> wordVector {openFile()};
    int upperLimit {wordVector.size()};
    int randomNumber {randomNumberGenerator(upperLimit)};
    std::string currentWord {wordVector[randomNumber]};
    printLettersAndSpaces(guessedLettersTest, currentWord);
    std::cout << "a word: "<< currentWord << std::endl;
    return 0;
}