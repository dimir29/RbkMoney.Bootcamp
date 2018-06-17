#pragma once
#include <vector>
#include <utility>
#include "imerchant.h"
namespace randomgen{
    /// С вероятностью 5% вернёт true
    bool isWrongDecision();
    /// Вернёт число из закрытого интервала [5,10],
    /// числа выпадают с одинаковой вероятностью
    /// (равномерное распределение)
    int  getCountTransactionsPerYear();

    /// Генерирует случайную перестановку вектор пар индексов
    void shuffle(std::vector<std::pair<int, int> >& v);

    IMerchant::BehaviorType getRandomBehavior();
}
