#pragma once

#include "imerchant.h"
#include <array>
class QuirkyMerchant: public IMerchant
{
public:
    QuirkyMerchant();
    QuirkyMerchant(const QuirkyMerchant& other) = delete;
    QuirkyMerchant& operator=(const QuirkyMerchant& other) = delete;
    virtual ~QuirkyMerchant(){}

    BehaviorType doRightDecision() override;
    BehaviorType doWrongDecision() override;

    void applyResultOfTransaction(profit_t p, BehaviorType opponentBehavior) override;

    std::string getDescription() const override{
        return "Ушлый. Прибыль:" + std::to_string(m_profit);
    }
    IMerchant* createNewMerchant() const override{
        return new QuirkyMerchant();
    }

    void reset() override;

private:
    std::array<BehaviorType, 5> m_startSeq;
    BehaviorType m_opponentBehavior;
    bool m_mustScam;
    int  m_currentStep;
};


