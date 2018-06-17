#pragma once
#include "imerchant.h"

class AltruistMerchant: public IMerchant
{
public:
    AltruistMerchant();
    AltruistMerchant(const AltruistMerchant& other) = delete;
    AltruistMerchant& operator=(const AltruistMerchant& other) = delete;

    BehaviorType doRightDecision() override{
        return BehaviorType::Cooperation;
    }
    BehaviorType doWrongDecision() override{
        return BehaviorType::Scam;
    }

    std::string getDescription() const override{
        return "Альтруист. Прибыль:" + std::to_string(m_profit);
    }
    IMerchant* createNewMerchant() const override{
        return new AltruistMerchant();
    }
    virtual ~AltruistMerchant(){}
};

