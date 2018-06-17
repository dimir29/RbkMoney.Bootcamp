#pragma once

#include "imerchant.h"
class DodgerMerchant: public IMerchant
{
public:
    DodgerMerchant();
    DodgerMerchant(const DodgerMerchant& other) = delete;
    DodgerMerchant& operator=(const DodgerMerchant& other) = delete;
    virtual ~DodgerMerchant(){}

    BehaviorType doRightDecision() override;
    BehaviorType doWrongDecision() override;

    void applyResultOfTransaction(profit_t p, BehaviorType opponentBehavior) override;

    std::string getDescription() const override{
        return "Хитрец. Прибыль:" + std::to_string(m_profit);
    }

    IMerchant* createNewMerchant() const{
        return new DodgerMerchant();
    }
    void reset() override;

private:
    bool m_isFirstStep;
    BehaviorType m_opponentDecision;
};


