#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sorting.h"

const int maxSize = 100;

void displayArr(int arr[]);

int main()
{
    int votes[maxSize];
    
    srand(time(0));

    for(int i = 0; i < maxSize; i++)
    {
        votes[i] = rand() % 5 + 1;
    }

    std::cout << "Original Votes:\n";
    displayArr(votes);

    selectionSort(votes, maxSize);

    std::cout << "\nSorted Votes:\n";
    displayArr(votes);

    int vote1 = 0;
    int vote2 = 0;
    int vote3 = 0;
    int vote4 = 0;
    int vote5 = 0;

    for(int i = 0; i < maxSize; i++)
    {
        if(votes[i] == 1)
            vote1++;
        else if(votes[i] == 2)
            vote2++;
        else if(votes[i] == 3)
            vote3++;
        else if(votes[i] == 4)
            vote4++;
        else if(votes[i] == 5)
            vote5++;
    }

    std::cout << "\nManual Count:\n";
    std::cout << "Vote 1: " << vote1 << std::endl;
    std::cout << "Vote 2: " << vote2 << std::endl;
    std::cout << "Vote 3: " << vote3 << std::endl;
    std::cout << "Vote 4: " << vote4 << std::endl;
    std::cout << "Vote 5: " << vote5 << std::endl;

    int count[6] = {0};

    for(int i = 0; i < maxSize; i++)
    {
        count[votes[i]]++;
    }

    std::cout << "\nCandidate Voting Results:\n";

    std::cout << "Candidate 1 - Bo Dalton Capistrano: "
              << count[1] << " votes\n";

    std::cout << "Candidate 2 - Cornelius Raymon Agustín: "
              << count[2] << " votes\n";

    std::cout << "Candidate 3 - Deja Jayla Bañaga: "
              << count[3] << " votes\n";

    std::cout << "Candidate 4 - Lalla Brielle Yabut: "
              << count[4] << " votes\n";

    std::cout << "Candidate 5 - Franklin Relano Castro: "
              << count[5] << " votes\n";


    int winner = 1;

    for(int i = 2; i <= 5; i++)
    {
        if(count[i] > count[winner])
        {
            winner = i;
        }
    }

    std::cout << "\nWinner: ";

    if(winner == 1)
        std::cout << "Bo Dalton Capistrano";
    else if(winner == 2)
        std::cout << "Cornelius Raymon Agustín";
    else if(winner == 3)
        std::cout << "Deja Jayla Bañaga";
    else if(winner == 4)
        std::cout << "Lalla Brielle Yabut";
    else
        std::cout << "Franklin Relano Castro";

    std::cout << std::endl;

    return 0;
}

void displayArr(int arr[])
{
    for(int i = 0; i < maxSize; i++)
    {
        std::cout << arr[i] << " ";

        if((i + 1) % 10 == 0)
            std::cout << std::endl;
    }
}