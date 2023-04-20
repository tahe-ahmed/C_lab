#include <iostream>
#include <string>
#include <fstream>
#include <vector>

std::string processInput(std::istream &input);
std::ifstream openAndReadFile(std::string fileName);
void fillVectorsWithLetters(std::vector<char> &charVector);
void parseInputToCharVector(std::string input, std::vector<char> &charVector, std::vector<int> &countChar);
int findOverallFreqIndex(std::vector<char> charVector, std::vector<int> countChar);
int findMostVowelFreqIndex(std::vector<char> charVector, std::vector<int> countChar);
int findMostConsonantFreqIndex(std::vector<char> charVector, std::vector<int> countChar);

int main(int argc, char *argv[])
{
    std::vector<char> charVector(26);
    std::vector<int> countChar(26, 0);
    std::ifstream inputFileStream;
    std::string input;
    std::string fileName;
    unsigned int index;

    try
    {
        if (argc == 2)
        {
            fileName = argv[1];
            inputFileStream = openAndReadFile(fileName);
            input = processInput(inputFileStream);
        }
        else if (argc > 2)
        {
            throw std::invalid_argument("cannot handle parameter list");
        }
        else
        {
            input = processInput(std::cin);
        }
    }
    catch (std::invalid_argument &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    catch (std::runtime_error &e)
    {
        std::cerr << e.what() << fileName << std::endl;
        return 2;
    }

    fillVectorsWithLetters(charVector);
    parseInputToCharVector(input, charVector, countChar);

    index = findMostVowelFreqIndex(charVector, countChar);
    std::cout << "Most frequent vowel: " << charVector.at(index) << " (" << countChar.at(index) << " times)" << std::endl;

    index = findMostConsonantFreqIndex(charVector, countChar);
    std::cout << "Most frequent consonant: " << charVector.at(index) << " (" << countChar.at(index) << " times)" << std::endl;

    index = findOverallFreqIndex(charVector, countChar);
    std::cout << "Most frequent letter, overall: " << charVector.at(index) << " (" << countChar.at(index) << " times)" << std::endl;

    return 0;
}

std::string processInput(std::istream &input)
{
    std::string singleInput;
    std::string allInput;

    while (!input.fail())
    {
        input >> singleInput;
        allInput += singleInput;
        singleInput = "";
    }

    return allInput;
}

std::ifstream openAndReadFile(std::string fileName)
{
    std::ifstream fileStream;

    fileStream.open(fileName);

    if (!fileStream.is_open())
    {
        throw std::runtime_error("cannot open input file ");
    }

    return fileStream;
}

void fillVectorsWithLetters(std::vector<char> &charVector)
{
    int i;
    for (i = 0; i <= 25; i++)
    {
        charVector.at(i) = char(i + 97);
    }
}

void parseInputToCharVector(std::string input, std::vector<char> &charVector, std::vector<int> &countChar)
{
    int ASSCIIValue;
    unsigned int i;
    unsigned int index;

    if (input.size() != 0)
    {
        for (i = 0; i <= input.size() - 1; ++i)
        {
            ASSCIIValue = int(input.at(i));

            if ((ASSCIIValue >= 65 && ASSCIIValue <= 90) || (ASSCIIValue >= 97 && ASSCIIValue <= 122))
            {
                index = (ASSCIIValue > 90) ? ASSCIIValue - 97 : (ASSCIIValue - 65);
                charVector.at(index) = char(index + 97);
                countChar.at(index) = countChar.at(index) + 1;
            }
        }
    }
}

int findOverallFreqIndex(std::vector<char> charVector, std::vector<int> countChar)
{
    char mostFrequentChar = charVector.at(0);
    unsigned int frequency = 0;
    unsigned int index = 0;
    unsigned int i;

    for (i = 0; i < countChar.size(); i++)
    {
        if (countChar.at(i) > frequency)
        {
            frequency = countChar.at(i);
            mostFrequentChar = charVector.at(i);
            index = i;
        }
    }

    return index;
}

int findMostVowelFreqIndex(std::vector<char> charVector, std::vector<int> countChar)
{
    std::vector<int> vowelIndexes{0, 4, 8, 14, 20};
    unsigned int vowelIndex = 0;
    unsigned int index = 0;
    unsigned int frequency = 0;
    unsigned int i;

    for (i = 0; i < vowelIndexes.size(); i++)
    {
        vowelIndex = vowelIndexes.at(i);
        if (countChar.at(vowelIndex) > frequency)
        {
            frequency = countChar.at(vowelIndex);
            index = vowelIndex;
        }
    }

    return index;
}

int findMostConsonantFreqIndex(std::vector<char> charVector, std::vector<int> countChar)
{
    std::vector<int> nonConsIndexes{0, 4, 8, 14, 20};
    unsigned int nonConsIndex = 0;
    unsigned int index = 1;
    unsigned int frequency = 0;
    unsigned int i = 0;

    for (i = 0; i < countChar.size(); i++)
    {
        if (nonConsIndexes.at(nonConsIndex) == i)
        {
            nonConsIndex = (nonConsIndex < 4) ? nonConsIndex + 1 : nonConsIndex;
            continue;
        }
        else if (countChar.at(i) > frequency)
        {
            frequency = countChar.at(i);
            index = i;
        }
    }

    return index;
}