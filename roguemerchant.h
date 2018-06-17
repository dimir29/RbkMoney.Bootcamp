#pragma once

#include "imerchant.h"

class RogueMerchant: public IMerchant
{
public:
    RogueMerchant();
    RogueMerchant(const RogueMerchant& other) = delete;
    RogueMerchant& operator = (const RogueMerchant& other) = delete;
    virtual ~RogueMerchant(){}

    BehaviorType doRightDecision() override{
        return BehaviorType::Scam;
    }
    BehaviorType doWrongDecision() override{
        return BehaviorType::Cooperation;
    }
    std::string getDescription() const override{
        return "Кидала. Прибыль:" + std::to_string(m_profit);
    }
    IMerchant* createNewMerchant() const override{
        return new RogueMerchant();
    }
};
