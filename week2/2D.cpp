#include <iostream>
#include <vector>
using namespace std;

void deduplicate(std::vector<int> duplicateVector)
{

    vector<int> numRangeVector;
    vector<int> numRecurrence;
    vector<int> deduplicateVector;
    int i;
    int greatestValue = duplicateVector.at(0);
    int leastValue = duplicateVector.at(0);

    for (i = 0; i < duplicateVector.size(); ++i)
    {
        greatestValue = (duplicateVector.at(i) > greatestValue) ? duplicateVector.at(i) : greatestValue;
        leastValue = (duplicateVector.at(i) < leastValue) ? duplicateVector.at(i) : leastValue;
    }

    for (i = leastValue; i <= greatestValue; ++i)
    {
        numRangeVector.push_back(i);
        numRecurrence.push_back(0);
    }

    for (i = 0; i < duplicateVector.size(); ++i)
    {
        int currentIndex = duplicateVector.at(i) - leastValue;
        numRecurrence.at(currentIndex) += 1;
    }

    for (i = 0; i < duplicateVector.size(); ++i)
    {
        int currentIndex = duplicateVector.at(i) - leastValue;
        if (numRecurrence.at(currentIndex) == 0)
        {
            continue;
        }
        else
        {
            deduplicateVector.push_back(duplicateVector.at(i));
            numRecurrence.at(currentIndex) = 0;
        };
    }

    for (i = 0; i < deduplicateVector.size(); ++i)
    {
        cout << deduplicateVector.at(i) << endl;
    }
}

int main()
{
    std::vector<int> duplicateVector;
    int vectorElement;

    std::cout << "Enter the vector elements: ";
    std::cin >> vectorElement;

    while (std::cin)
    {
        duplicateVector.push_back(vectorElement);
        std::cin >> vectorElement;
    }

    deduplicate(duplicateVector);
    return 0;
}