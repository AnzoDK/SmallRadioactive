//Small dice roll

#include <iostream>
#include <vector>
#include <time.h> 


#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;

std::vector<int> castCount;
int dSides = 6;
int amount = 1000;
int casts = 0;
int currAmount = 0;
std::vector<int> rolls;
std::vector<int> remaining;

void roll()
{
    rolls.clear();
    for(int i = 0; i < currAmount;i++)
    {
        int roll = rand() % dSides + 1;
        //std::cout << roll << std::endl;
        rolls.push_back((int)roll);
    }
}

void evaluate()
{
    for(int i = 0; i < rolls.size();i++)
    {
        if(rolls.at(i) == 6)
        {
            currAmount--;
        }
    }
    casts++;
    castCount.push_back(casts);
    remaining.push_back(currAmount);
}

int main()
{
    currAmount = amount;
    srand(time(0));
    rolls = std::vector<int>();
    remaining = std::vector<int>();
    castCount = std::vector<int>();
    while(currAmount > 0)
    {
        std::cout << "loop currCount = " << currAmount << std::endl;
        roll();
        evaluate();
    }
    plt::plot(castCount, remaining,"ro");
    plt::show();
    return 0;
}