#pragma once

#include "imerchant.h"
class RancorousMerchant: public IMerchant
{
public:
    RancorousMerchant();
    RancorousMerchant(const RancorousMerchant& other) = delete;
    RancorousMerchant& operator=(const RancorousMerchant& other) = delete;
    virtual ~RancorousMerchant(){}

    BehaviorType doRightDecision() override{
        if (m_mustScam){
            return BehaviorType::Scam;
        }
        return BehaviorType::Cooperation;
    }
    BehaviorType doWrongDecision() override{
        if (m_mustScam){
            return BehaviorType::Cooperation;
        }
        return BehaviorType::Scam;
    }

    void applyResultOfTransaction(profit_t p, BehaviorType opponentBehavior) override;

    std::string getDescription() const override{
        return "Злопамятный. Прибыль:" + std::to_string(m_profit);
    }

    IMerchant* createNewMerchant() const override{
        return new RancorousMerchant();
    }

    void reset() override;
private:
    bool m_mustScam;
};

