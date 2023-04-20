#include <iostream>
#include <vector>

void deduplicate(std::vector<int> duplicateVector)
{
    unsigned int i, j;
    std::vector<int> deduplicateVector;

    deduplicateVector.push_back(duplicateVector.at(0));

    for (i = 0; i < duplicateVector.size(); i++)
    {
        bool isDuplicate = false;
        for (j = 0; j < deduplicateVector.size(); j++)
        {

            if (deduplicateVector.at(j) == duplicateVector.at(i))
            {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate)
        {
            deduplicateVector.push_back(duplicateVector.at(i));
        }
    }

    // print out the vector
    for (i = 0; i < deduplicateVector.size(); ++i)
    {
        std::cout << deduplicateVector.at(i) << std::endl;
    }
}

int main()
{
    std::vector<int> duplicateVector;
    int vectorElement;
    unsigned int i;

    std::cout << "Enter the vector elements: ";
    std::cin >> vectorElement;

    while (std::cin)
    {
        // std::cin >> vectorElement;
        // if (!std::cin)
        //     break;

        duplicateVector.push_back(vectorElement);
        std::cin >> vectorElement;
    }
    // std::cout << "go" << duplicateVector.size();

    deduplicate(duplicateVector);

    // print out the vector
    // for (i = 0; i < duplicateVector.size(); ++i)
    // {
    //     std::cout << duplicateVector.at(i) << std::endl;
    // }
    return 0;
}