#include <iostream>
#include <vector>
#include <cmath>

int main()
{
    std::vector<int> vectorOfNumbers;
    std::vector<int> mapingVector;
    std::vector<bool> mapingBool;
    int numberOfElement;
    int numberInVector;
    int i;

    std::cout << "How many numbers? ";
    std::cin >> numberOfElement;

    std::cout << "Please enter the numbers ";

    // populate the vector
    for (i = 0; i < numberOfElement; ++i)
    {
        std::cin >> numberInVector;
        vectorOfNumbers.push_back(numberInVector);
    }

    // find the smallest number in the vector
    // find the greatest number in the vector
    int smallestNumInVector = vectorOfNumbers.at(0);
    int greatestNumInVector = vectorOfNumbers.at(0);
    for (i = 0; i < numberOfElement; ++i)
    {
        if (vectorOfNumbers.at(i) < smallestNumInVector)
        {
            smallestNumInVector = vectorOfNumbers.at(i);
        }
        if (vectorOfNumbers.at(i) > greatestNumInVector)
        {
            greatestNumInVector = vectorOfNumbers.at(i);
        }
    }

    /// create a maping vector
    // int numberForMappingVector;
    for (i = greatestNumInVector; (i >= smallestNumInVector); i = i - 1)
    {
        // std::cout << i << std::endl;

        mapingVector.push_back(i);
        mapingBool.push_back(false);
    }

    /// if smallestNumInVector is negtive

    // for (i = 0; (i >= (smallestNumInVector)); i--)
    // {
    //     // std::cout << i << std::endl;

    //     mapingVector.push_back(i);
    //     mapingBool.push_back(false);
    // }

    // std::cout << "greatest value " << greatestNumInVector << std::endl;
    // std::cout << " smallest value " << smallestNumInVector << std::endl;

    // do the mapping and set the exist element to zero
    for (i = 0; i < numberOfElement; ++i)
    {
        int num = vectorOfNumbers.at(i);

        int indexInMapping = abs(greatestNumInVector - num);
        mapingVector.at(indexInMapping) = 0;
        // if( num == 0){
        //     mapingBool.at(indexInMapping) = true;
        // }

        mapingBool.at(indexInMapping) = true;

        // if(num == 0) {

        // }
    }

    int smallestPossibleValue;

    for (i = (mapingVector.size() - 1); i >= 0; --i)
    {
        // std::cout << mapingVector.at(i) << std::endl;

        if (mapingBool.at(i) == 0)
        {
            smallestPossibleValue = mapingVector.at(i);
            std::cout << "The smallest missing number is " << smallestPossibleValue << std::endl;

            return 0;
        } /// if all zeros
        else
        {
            continue;
        }
    }

    smallestPossibleValue = greatestNumInVector + 1;

    // print a vector
    // for (i = 0; i < mapingVector.size(); ++i)
    // {
    //     std::cout << mapingVector.at(i) << " " << mapingBool.at(i) << std::endl;
    // }

    std::cout << "The smallest missing number is " << smallestPossibleValue << std::endl;

    return 0;
}

// check the smallestPossibleMissing in vector
//// if it is exist then add 1 and check again
// int smallestPossibleMissing = smallestNumInVector + 1;
// for (i = 0; i < numberOfElement;)
// {
//     // check if this possible smallestPossibleMissing is in the vector
//     if (vectorOfNumbers.at(i) == smallestPossibleMissing)
//     {
//         // add 1 to the smallestPossibleMissing
//         smallestPossibleMissing += 1;
//         i = 0;
//     }
//     else
//     {
//         ++i;
//     }
// }