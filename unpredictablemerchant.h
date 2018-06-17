#pragma once

#include "imerchant.h"
#include "randomgenerator.h"
class UnpredictableMerchant: public IMerchant
{
public:
    UnpredictableMerchant();
    UnpredictableMerchant(const UnpredictableMerchant& o) = delete;
    UnpredictableMerchant& operator=(const UnpredictableMerchant& o) = delete;
    virtual ~UnpredictableMerchant(){}

    BehaviorType doRightDecision() override{
        return randomgen::getRandomBehavior();
    }

    BehaviorType doWrongDecision() override{
        BehaviorType b = doRightDecision();
        if (b == BehaviorType::Cooperation){
            return BehaviorType::Scam;
        }
        return BehaviorType::Cooperation;
    }

    std::string getDescription() const override{
        return "Непредсказуемый. Прибыль:" + std::to_string(m_profit);
    }

    IMerchant* createNewMerchant() const override{
        return new UnpredictableMerchant();
    }
};


