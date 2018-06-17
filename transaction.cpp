#include "transaction.h"
#include "randomgenerator.h"
#include <tuple>
#include <array>
#include <utility>

using ProfitResult = std::pair<IMerchant::profit_t, IMerchant::profit_t>;

static std::array< std::array<ProfitResult, 2>, 2> ProfitMap{{
    { ProfitResult{2,2}, ProfitResult{5,1} },
    { ProfitResult{1,5}, ProfitResult{4,4} }
}};

void doTransaction(IMerchant *left, IMerchant *right)
{
    const std::size_t profit = 0;
    const std::size_t behavior = 1;
    auto leftDetails = std::make_tuple(0, IMerchant::BehaviorType::Cooperation);
    auto rightDetails = std::make_tuple(0, IMerchant::BehaviorType::Cooperation);
    std::get<behavior>(leftDetails) =
            randomgen::isWrongDecision()?left->doWrongDecision():left->doRightDecision();
    std::get<behavior>(rightDetails) =
            randomgen::isWrongDecision()?right->doWrongDecision():right->doRightDecision();
    int i = static_cast<int>(std::get<behavior>(leftDetails));
    int j = static_cast<int>(std::get<behavior>(rightDetails));
    std::get<profit>(leftDetails) = ProfitMap[i][j].first;
    std::get<profit>(rightDetails) = ProfitMap[i][j].second;
    left->applyResultOfTransaction(std::get<profit>(leftDetails), std::get<behavior>(rightDetails));
    right->applyResultOfTransaction(std::get<profit>(rightDetails), std::get<behavior>(leftDetails));
}
