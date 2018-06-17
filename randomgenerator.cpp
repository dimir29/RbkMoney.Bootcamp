#include "randomgenerator.h"
#include <chrono>
#include <random>
#include <algorithm>

    static std::mt19937_64 gen{
        static_cast<unsigned long long>(
                    std::chrono::system_clock::now().time_since_epoch().count())};
    static std::discrete_distribution<int> dis{1, 19};    ///< для 5% вероятности ошибки
    static std::uniform_int_distribution<int> dis1(5,10); ///< для количество сделок в год
    static std::uniform_int_distribution<int> dis2(0,1);  ///< для случайного поведения торвгоца

namespace randomgen{


bool isWrongDecision()
{
    return dis(gen) == 0;
}

int getCountTransactionsPerYear()
{
    return dis1(gen);
}

void shuffle(std::vector<std::pair<int, int> > &v)
{
    std::shuffle(v.begin(), v.end(), gen);
}

IMerchant::BehaviorType getRandomBehavior()
{
    return static_cast<IMerchant::BehaviorType>(dis2(gen));
}

}
