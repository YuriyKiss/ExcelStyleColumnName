#include <iostream>

const int AMOUNT_OF_LETTERS = 26;

int findDepth(int value)
{
    int depth = 1;

    int iterationValue = value / AMOUNT_OF_LETTERS;

    if (iterationValue > 0)
    {
        depth += findDepth(iterationValue - 1);
    }

    return depth;
}

char* intToLiteral(int value, int depth)
{
    char* result = new char[depth];

    for (int i = 0; i < depth; ++i) 
    {
        int modulo = value % AMOUNT_OF_LETTERS;
        result[i] = 'A' + modulo;

        value = value / AMOUNT_OF_LETTERS - 1;
    }

    return result;
}

void displayExcelStyleColumnName(int value) 
{
    int depth = findDepth(value);
    char* result = intToLiteral(value, depth);

    for (int i = depth - 1; i >= 0; i--)
    {
        std::cout << result[i];
    }
    std::cout << std::endl;
}

clock_t calculateTime(int value, void (*func)(int)) 
{
    clock_t timer = clock();
    for (int i = 0; i < value; ++i)
    {
        func(i);
    }
    return clock() - timer;
}

int main()
{
    int maxThreeLetterInt = pow(AMOUNT_OF_LETTERS, 3) + pow(AMOUNT_OF_LETTERS, 2) + AMOUNT_OF_LETTERS;
    clock_t timer = calculateTime(maxThreeLetterInt, displayExcelStyleColumnName);
    float timeInSeconds = (float)timer / CLOCKS_PER_SEC;

    std::cout << std::endl << "It took " << timer << " clicks or " << timeInSeconds
        << " seconds to perform " << maxThreeLetterInt << " calculations.\n";

    std::cout << "That equals to " << maxThreeLetterInt / timeInSeconds << " calculations per second or " 
        << timeInSeconds / maxThreeLetterInt << " seconds per calculation.\n";
}
